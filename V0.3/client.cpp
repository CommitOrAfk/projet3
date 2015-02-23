#include "client.h"

Client::Client()
{
    identifiant=(int)(this);
    if(identifiant < 0)
    {
        identifiant=identifiant * -1;
    }
    codesecret=0000;
    nom="MARTIN";
    prenom="Paul";
    adresse="15 rue de la paix";

}

/*Client::Client(int id, int code, string nom, string prenom, string adresse)
{
    string poubelle;        // on cree un string qui nous servira juste pour regler un probleme de tampon memoire
    identifiant=id;
    this->identifiant = (int)(this);
    if(this->identifiant < 0)
    {
        this->identifiant = this->identifiant * -1;
    }

    do{
        cout << "code secret : ";
        cin >> code;
        }while(code < 0 || code > 9999);
    this->codesecret=code;
    getline(cin,poubelle);  // getline pour regler le probleme de tampon
    cout << "nom : ";
    getline(cin,nom);
    this->nom=nom;
    cout << "prenom : ";
    getline(cin,prenom);
    this->prenom=prenom;
    cout << "adresse : ";
    getline(cin,adresse);
    this->adresse=adresse;

}*/

void Client::Afficher(ostream &out) const
{
    cout<<"*** Informations du client ***\n";
    out << "id : " << identifiant << "\t" << setfill('0')  << "code : " << setw(4) << codesecret << endl;
    out << "nom : " << nom << "\t" << "prenom : " << prenom << endl;
    out << "adresse : " << adresse << endl;

    //Affichage des comptes même vides
        this->MonCompteCourant.Afficher();
        this->MonLivret.Afficher();
        this->MonCompteBloque.Afficher();
        this->MonPel.Afficher();
        this->MonECompte.Afficher();
}

void Client::Saisir(istream &in)
{
    string poubelle;        // on cree un string qui nous servira juste pour regler un probleme de tampon memoire

    cout << "Saisir les informations relatives au client : \n";
    identifiant = (int)(this);
    if(this->identifiant < 0)
    {
        this->identifiant = this->identifiant * -1;
    }
    cout << "code secret : ";
    in >> codesecret;
    getline(in,poubelle);  // getline pour regler le probleme de tampon
    cout << "nom : ";
    getline(in,nom);
    cout << "prenom : ";
    getline(in,prenom);
    cout << "adresse : ";
    getline(in,adresse);
}

void Client::OuvrirCompte()
{
    int choix;
    do{
        cout<<"Quel compte souhaitez-vous ouvrir\n";
        cout<<"Rappel: Vous ne pouvez avoir qu'un seul compte de chaque type, ouvrir un compte deja ouvert entrainera la suppression de l'ancien compte\n";
        cout<<"*** 1-Compte Courant ***\n";
        cout<<"*** 2-Livret Epargne ***\n";
        cout<<"*** 3-Compte Bloque  ***\n";
        cout<<"*** 4-PEL            ***\n";
        cout<<"*** 5-E-Compte       ***\n";
        cin>>choix;

        switch(choix)
        {
            case 1: MonCompteCourant.Saisir();
                break;
            case 2: MonLivret.Saisir();
                break;
            case 3: MonCompteBloque.Saisir();
                break;
            case 4: MonPel.Saisir(cin);
                break;
            case 5: MonECompte.ChangerCoordonnes();
                break;
            default: cout<<"erreur\n";
                break;
        }


    }while(choix != 0);
}

void Client::ChangerCoordonnees()
{

    string poubelle;
    cout<<"Changer vos coordonnées"<<endl;
    cout <<"Entrer une nouvelle adresse : ";
    getline(cin, poubelle);
    getline(cin,this->adresse);

}

ostream &operator<<(ostream &out, const Client &C)
{
    C.Afficher(out);
    return out;
}

istream &operator>>(istream &in, Client &C)
{
    C.Saisir(in);
    return in;
}
