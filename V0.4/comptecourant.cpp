#include "comptecourant.h"

CompteCourant::CompteCourant(double decouvert, double aggio): Compte(id, solde)
{
        decouvert = 0;
        this->decouvert = decouvert;
        aggio = 0;
        this->aggio = aggio;
        this->solde = 0;

        //conversion en string de l'identifiant du compte
        stringstream out;
        out << (int)(this);
        string identifiant = out.str();
        string operation = "Operations_";
        string type_fichier = ".txt";
        this->nomfichier = operation + identifiant + type_fichier; //Concaténation pour former un fichier appelé "Operations_(numero identifiant du compte).txt"
        this->isOpen = true;

}

void CompteCourant::Saisir()
{

        this->id = (int)(this);
        if(this->id < 0)
        {
            id = id*-1;
        }
        this->decouvert = 0;
        this->aggio = 0;

        stringstream out;
        out << (int)(this);
        string identifiant = out.str();
        string operation = "Operations_";
        string type_fichier = ".txt";
        this->nomfichier = operation + identifiant + type_fichier; //Concaténation pour former un fichier appelé "Operations_(numero identifiant du compte).txt"
        this->isOpen = true;
}

void CompteCourant::Afficher() const
{

    cout<<"*** Compte Courant ***\n";
    Compte::Afficher();
    if(solde <0)
    {
        cout << "Decouvert: " << setprecision(2) << this->decouvert << endl;
        cout << "Aggio: " << setprecision(2) << this->aggio << endl;
    }
}

void CompteCourant::ChangerCoordonnes()
{
    //Appel de la fonction dans compte, pas de surcharge
}
double CompteCourant::Consulter()
{
    //Appel de celle de Compte
    return this->solde;
}
void CompteCourant::Cloturer()
{
    //Appel de celle de Compte
}

bool CompteCourant::EstOuvert() const
{
    return true;
}

void CompteCourant::AjouterArgent(const int *today)
{
    double ajout;
    do{
        cout<<"Quelle somme souhaitez-vous ajouter au solde:";
        cin>>ajout;
        if(ajout <0)
        {
            cout<<"\nValeur negtive, saisissez une valeur positive\n";
        }
    }while(ajout < 0);
    solde = solde + ajout;
    ImprimerAction("Ajout", ajout, today);

    if(solde > 0)
    {
        decouvert = 0;
        aggio = 0;
    }
    if(solde < 0)
    {
        //On associe la date de l'opération avec la date d'aujourd'hui et on la stocke dans le vector
        this->Date_temp.jour = today[0];
        this->Date_temp.mois = today[1];
        this->Date_temp.annee = today[2];

        Tab_Date.push_back(Date_temp);
        decouvert = -solde;
    }

    SeuilAlerte(today);

}

void CompteCourant::RetirerArgent(const int *today)
{
    double retrait;
    do{
        cout<<"Quelle somme souhaitez-vous retirer au solde:";
        cin>>retrait;
        if(retrait < 0)
        {
            cout<<"\nValeur negtive, saisissez une valeur positive\n";
        }
    }while(retrait < 0);
    solde = solde - retrait;

    if(solde < 0)
    {
        //On associe la date de l'opération avec la date d'aujourd'hui et on la stocke dans le vector
        this->Date_temp.jour = today[0];
        this->Date_temp.mois = today[1];
        this->Date_temp.annee = today[2];

        Tab_Date.push_back(Date_temp);
        decouvert = -solde;
    }
        ImprimerAction("Retrait", retrait, today);

        SeuilAlerte(today);

}

void CompteCourant::SeuilAlerte(const int *today)
{
    if(solde < 0)
    {
        decouvert = -solde;
        cout<<"Attention, vous etes a decouvert de"<<this->decouvert<<" / Vos agios sont calculés"<<endl;
        // appel de CalculerAgios et AppliquerAgios
        CalculerAgios(today);
        AppliquerAgios();
    }
}

void CompteCourant::CalculerAgios(const int *today)
{
    //Todo
    /*Exemple : au premier trimestre de l'année, un compte est débiteur de 500 euros du 5 au 22 janvier, et de 450 euros du 2 au 28 mars.
Le taux d'intérêt débiteur est de 20% annuel.

Le nombre débiteur du premier découvert est de 500 × 17 = 8.500
Le nombre débiteur du deuxième découvert est de 450 × 26 = 11.700
Le total des nombres débiteurs du trimestre est de 8.500 + 11.700 = 20.200

Le montant des agios sera de ( 20.200 × 20 ) ÷ ( 365 × 100 ) = 11,07 euros*/

    int taille = Tab_Date.size(); //On récupère la taille du vector.
    Date Compare = Tab_Date.at(taille -1); //On copie la dernière date du tableau dans une Date Compare

    int difference_jour =0;

    if(Compare.jour < today[0])
    {
        difference_jour = today[0] - Compare.jour;
        cout<<"Jour de diff"<<difference_jour<<endl;
    }

    if(Compare.mois < today[1])
    {
        difference_jour = (31 - Compare.jour) + today[0] ;
        cout<<"Jour de diff"<<difference_jour<<endl;
    }

    if(Compare.annee < today[2])
    {
        difference_jour = (12 - today[1])*(31 - today[0]) + Compare.jour;
        cout<<"Jour de diff"<<difference_jour<<endl;
    }

    if((Compare.jour == today[0]) && (Compare.mois == today[1]) && (Compare.annee == today[2]))
    {
        aggio = 0;
        return;
    }

    //Calcul des agios, le taux d'intérêt débiteur est de 20% annuel

    double calc_agios = decouvert * difference_jour;

    aggio = (calc_agios * 20) / (365 * 100);
    cout<<"Les agios s'elevent a "<<aggio<<" euros/jour"<<endl;



}

void CompteCourant::AppliquerAgios()
{
    //la comission est de 5€
    solde = solde - aggio - 5;
}

void CompteCourant::ImprimerAction(string nom_operation, double montant, const int *today)
{
    //Fonction a implémenter dans toutes les fonctions d'opération bancaire
    char *lefichier = (char *)this->nomfichier.c_str();
    ofstream fichier(lefichier, ios_base::app);
    fichier << nom_operation << ":";
    fichier << montant <<" effectue le ";
    fichier << today[0] << "/" << today[1] << "/" << today[2]<<endl;
    fichier.close();

}

//Lit le fichier Operations_(numero identifiant du compte).txt et en imprime les dix dernières actions
void CompteCourant::ImprimerTicket(const int *today)
{
    string ligne;
    //Lit le fichier Operations_(numero identifiant du compte).txt et en imprime les dix dernières actions
    ofstream ticket("Ticket.txt", ios_base::trunc); //on créé notre ticket
    char *lefichier = (char *)this->nomfichier.c_str(); //on copie notre nom de fichier au format char *
    ifstream fichier(lefichier); //on ouvre notre fichier avec nos opérations en lecture

    getline(cin, ligne);// getline pour regler le probleme de tampon

    //Copie en texte le numero d'identifiant du compte
    stringstream out;
    out << (int)(this);
    string identifiant = out.str();

    ticket << "Ticket imprime le "<< today[0] << "/" << today[1] << "/" << today[2] <<" pour le Compte Courant n°"<< identifiant <<endl;
    ticket << "Details des 10 dernieres operations:\n";


    //On se met au debut du fichier
    fichier.seekg(0, fichier.beg);

    //On cherche le nombre de lignes du fichier
    int nbLignes = 0;
    while(fichier.ignore(numeric_limits<int>::max(), '\n'))
    {
        nbLignes++;
    }

    //On se remet au début du fichier
    fichier.clear();
    fichier.seekg(0, fichier.beg);

    if(nbLignes < 10)
    {
        while(getline(fichier, ligne))
        {
            ticket << ligne <<endl;
        }
    }
    else
    {
        for(int i=0; i < (nbLignes -11) && fichier.ignore(numeric_limits<int>::max(), '\n'); ++i)
        {
                //on se décale dans le fichier pour se mettre avant la liste des 10 lignes
        }

        for(int i =0 ; i<10 ; i++) //Lecture et réécriture des 10 dernières opérations dans le ticket
        {
            getline(fichier, ligne);
            ticket << ligne <<endl;
        }

    }


}



