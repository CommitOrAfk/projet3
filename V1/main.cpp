/** main.cpp juste pour tester
test date uniquement pour l'instant
**/
#include "date.h"
#include "client.h"
#include "compte.h"
#include "comptecourant.h"
#include "livret.h"
#include "comptebloque.h"
#include "pel.h"
#include "ecompte.h"

void Saisir_Today(int *today); //Pierre
void Afficher_Today(const int *today); //Pierre
void Ajouter_Jour(int *today, int nb_jour_ajoute); //Pierre
void Ajouter_Mois(int *today, int nb_mois_ajoute); //Pierre
void Ajouter_An(int *today, int nb_an_ajoute); //Pierre

int Afficher_Clients( vector <Client> MesClients); //Pierre
void Saisir_Clients(vector <Client> *MesClients); //Pierre

void Menu_CompteCourant(Client *LeClient, int *today); //Pierre
void MenuCompteBloque(Client *LeClient, int *today); //Alex
void MenuLivret(Client *LeClient); //Jordan
void MenuECompte(Client *LeClient,  int *today); //Sofian
void MenuPel(Client *LeClient,  int *date_today); //Théo

int main()
{
    int choix =0;
    int nb_clients =0;
    int choix_client =0;
    int choix_compte = 0;

    vector <Client> Tab_Client;

    do{
        int date_today[3]; // date_today est un tableau de 3 entiers représentant la date du jour: date_today[0] est le jour, date_today[1] est le mois, date_today[2] est l'année

        time_t today = time(NULL);
        tm* todayTm  = localtime(&today);


        date_today[0] = todayTm->tm_mday;
        date_today[1] = todayTm->tm_mon + 1;
        date_today[2] = todayTm->tm_year + 1900;




        // menu ╠ ╣ ╔ ╗ ═ ║ ╚ ╝ ╟ ╢ ─
	cout << "╔══════════════════════════════════════════════════════╗" << endl;;
    cout << "║              Menu Principal                          ║" <<endl;;
    cout << "╠══════════════════════════════════════════════════════╣" << endl;
    cout << "║ "; Afficher_Today(date_today) ; cout <<"                            ║ " << endl;
    cout << "╟──────────────────────────────────────────────────────╢" << endl;
    cout << "║ Que voulez vous faire?                               ║ " << endl;
    cout << "║ 1. Saisir un nouveau client.                         ║ " << endl;
    cout << "║ 2. Afficher les clients.                             ║ " << endl;
    cout << "║ 3. Choisir un client                                 ║ " << endl;
    cout << "╟──────────────────────────────────────────────────────╢" << endl;
    cout << "║ 5. Changer la date actuelle.                         ║ " << endl;
    cout << "║ 0. Quitter                                           ║ " << endl;
    cout << "╚══════════════════════════════════════════════════════╝" << endl;
    cout << " Votre choix: ";
    cin>>choix;


        switch(choix)
        {
            default: cout<<"\n erreur\n";
                break;
            case 0: return 0;
                break;
            case 5: Saisir_Today(date_today);
                break;
            case 1: Saisir_Clients(&Tab_Client);
                break;
            case 2: nb_clients = Afficher_Clients(Tab_Client);
                cout<<"\nIl y a "<<nb_clients -1<<" clients\n";
                break;
            case 3: do{

                    nb_clients = Afficher_Clients(Tab_Client);
                    cout<<"Rentrez le numero du client a editer (ex: 1)";
                    cin>>choix_client;
                    	cout << "╔══════════════════════════════════════════════════════╗" << endl;;
                        cout << "║              Gestion des comptes                     ║" <<endl;;
                        cout << "╠══════════════════════════════════════════════════════╣" << endl;
                        cout << "║ "; Afficher_Today(date_today) ; cout <<"                            ║ " << endl;
                        cout << "╟──────────────────────────────────────────────────────╢" << endl;
                        cout << "║ Que voulez vous faire?                               ║ " << endl;
                        cout << "║ 1. Compte Courant                                    ║ " << endl;
                        cout << "║ 2. Livret Epargne                                    ║ " << endl;
                        cout << "║ 3. Compte bloque                                     ║ " << endl;
                        cout << "║ 4. PEL                                               ║ " << endl;
                        cout << "║ 5. E-Compte                                          ║ " << endl;
                        cout << "╟──────────────────────────────────────────────────────╢" << endl;
                        cout << "║ 0. Retour au menu principal.                         ║ " << endl;
                        cout << "╚══════════════════════════════════════════════════════╝" << endl;
                        cout << " Votre choix: ";
                        cin>>choix_compte;

                        switch(choix_compte)
                        {
                            case 1: Menu_CompteCourant(&Tab_Client.at(choix_client -1), date_today);
                                break;
                            case 2: //Menu Livret Epargne
                                MenuLivret(&Tab_Client.at(choix_client -1));
                                break;
                            case 3: //Menu compte bloque
                                MenuCompteBloque(&Tab_Client.at(choix_client -1), date_today);
                                break;
                            case 4: //Menu PEL
                                MenuPel(&Tab_Client.at(choix_client -1),  date_today);
                                break;
                            case 5: //Menu ecompte
                                MenuECompte(&Tab_Client.at(choix_client -1),  date_today);
                                break;
                            case 0: return 0;
                                break;
                            default : cout<<"\n erreur\n";
                                break;

                        }

                    }while(choix_compte != 0);



        }

    }while(choix != 0);

return 0;
}

//Saisie de la date d'aujourd'hui
void Saisir_Today(int *today)
{
    do
    {
    cout << "Saisissez le jour: " <<endl;
    cin >> today[0];
        if((today[0] < 1) || (today[0] > 31))
        cout << "Saisie incorrecte!" <<endl;
    }while((today[0]<1) || (today[0] > 31));

    // saisir mois
    do
    {
    cout << "Saisissez le mois: " <<endl;
    cin >> today[1];
        if((today[1] < 1) || (today[1] > 12))
        cout << "Saisie incorrecte!" <<endl;
    }while((today[1] < 1) || (today[1] > 12));

    //  saisir annee
    do
    {
    cout << "Saisissez l annee: " <<endl;
    cin >> today[2];
        if((today[2] < 1) || (today[2] > 2016))
        cout << "Saisie incorrecte!" <<endl;
    }while((today[2] < 1) || (today[2] > 2016));
}

//Affichage de la date du jour
void Afficher_Today(const int *today)
{
    cout<<"Nous sommes le: "<< today[0]<<"/"<<today[1]<<"/"<<today[2];
}

//Bon dans le temps, ajoute le nombre de jour passé en paramètre à la date du jour
void Ajouter_Jour(int *today, int nb_jour_ajoute)
{
    int temp =0;
    int temp_today0 = 0;
    int temp_today1 = 0;

    temp_today0 = today[0] + nb_jour_ajoute;


    //Si l'ajout dépasse le mois
    if(temp_today0 > 31)
    {
        temp_today1 = today[1] + 1;
        temp = nb_jour_ajoute - (31 - today[0]);
        today[0] = temp;
        temp = 0;

        if( temp_today1 > 12)
        {
            today[2] = today[2] +1;
            today[1] = 1;
        }
        else
        {
            today[1] = today[1] +1;
        }
    }
    else
    {
        today[0] =temp_today0;
    }
}

//Bon dans le temps, ajoute le nombre de mois passé en paramètre à la date du jour
void Ajouter_Mois(int *today, int nb_mois_ajoute)
{
    int temp =0;
    int temp_today1 = 0;
    temp_today1 = today[1] + nb_mois_ajoute;

    //Si l'ajout dépasse l'année
    if( temp_today1 > 12)
    {
        today[2] = today[2] +1;
        temp = nb_mois_ajoute - (12 - today[1]);
        today[1] = temp;
    }
    else
    {
        today[1] = temp_today1;
    }
}

//Bon dans le temps, ajoute le nombre d'année passé en paramètre à la date du jour
void Ajouter_An(int *today, int nb_an_ajoute)
{
    today[2] = today[2] + nb_an_ajoute;
}

//Affiche tous les clients créés
int Afficher_Clients( vector <Client> MesClients)
{
    vector <Client>:: iterator it;
    int i = 1;
    for(it = MesClients.begin() ; it != MesClients.end() ; it++)
    {
        cout<<i<<" - "<<*it;
        i++;
    }
    return i;
}

void Saisir_Clients(vector <Client> *MesClients)
{
    cout<<"Saisie d'un client\n";
    //Client Nouveau(111, 1234, "nom", "prenom", "adresse");
    Client Nouveau;
    Nouveau.Saisir(cin);
    MesClients->push_back(Nouveau);

}

void Menu_CompteCourant(Client *LeClient, int *today)
{

int choix =0;

do{
    cout << "╔══════════════════════════════════════════════════════╗" << endl;;
    cout << "║              Gestion compte bloque                   ║" <<endl;;
    cout << "╠══════════════════════════════════════════════════════╣" << endl;
    cout << "║ "; Afficher_Today(today) ; cout <<"                  ║ " << endl;
    cout << "╟──────────────────────────────────────────────────────╢" << endl;
    cout << "║ Que voulez vous faire?                               ║ " << endl;
    cout << "║ 1. Afficher le compte                                ║ " << endl;
    cout << "║ 2. Ajouter de l'argent.                              ║ " << endl;
    cout << "║ 3. Retirer de l'argent.                              ║ " << endl;
    cout << "║ 4. Imprimer un ticket.                               ║ " << endl;
    cout << "║ 5. Cloturer le compte.                               ║ " << endl;
    cout << "║ 6. Changer coordonees.                               ║ " << endl;
    cout << "╟──────────────────────────────────────────────────────╢" << endl;
    cout << "║ 0. Retour au menu principal.                         ║ " << endl;
    cout << "╚══════════════════════════════════════════════════════╝" << endl;

    cout<<"Votre choix:";

    cin>>choix;


    switch(choix)
    {
        case 1: LeClient->MonCompteCourant.Afficher();
            break;
        case 2: LeClient->MonCompteCourant.AjouterArgent(today);
            break;
        case 3: LeClient->MonCompteCourant.RetirerArgent(today);
            break;
        case 4: LeClient->MonCompteCourant.ImprimerTicket(today);
            break;
        case 5: LeClient->MonCompteCourant.Cloturer();
            break;
        case 6: LeClient->MonCompteCourant.ChangerCoordonnes();
            break;
        case 0: return;
            break;
        default: cout<<"erreur\n";
            break;
    }
    Ajouter_Jour(today, 1);
    LeClient->MonCompteCourant.SeuilAlerte(today);
}while(choix != 0);

}

void MenuCompteBloque(Client *LeClient, int *date_today)
{

        int choix;
    do{
        cout << "╔══════════════════════════════════════════════════════╗" << endl;;
        cout << "║              Gestion compte bloque                   ║" <<endl;;
        cout << "╠══════════════════════════════════════════════════════╣" << endl;
        cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
        cout << "╟──────────────────────────────────────────────────────╢" << endl;
        cout << "║ Que voulez vous faire?                               ║ " << endl;
        cout << "║ 1. Afficher le compte                                ║ " << endl;
        cout << "║ 2. Saisir le taux interet et les versements mensuels.║ " << endl;
        cout << "║ 3. Voir combien de temps existe le compte.           ║ " << endl;
        cout << "║ 4. Voir combien de temps le compte reste bloque.     ║ " << endl;
        cout << "╟──────────────────────────────────────────────────────╢" << endl;
        cout << "║ 5. Changer la date actuelle.                         ║ " << endl;
        cout << "║ 0. Retour au menu principal.                         ║ " << endl;
        cout << "╚══════════════════════════════════════════════════════╝" << endl;
        cout << "    Entrer l operation a effectuer: ";
        cin >> choix;

        while(choix < 0 || choix > 5)
        {
        cout << "    Merci de choisir un chiffre entre 0 et 5!" << endl;
        cin >> choix;
        }

        switch(choix)
        {
            case 0:
                        return;
                break;

            case 1:
                        cout << "╔══════════════════════════════════════════════════════╗" << endl;;
                        cout << "║              Afficher compte bloque                  ║" <<endl;;
                        cout << "╠══════════════════════════════════════════════════════╣" << endl;
                        cout << "║ "; Afficher_Today(date_today) ; cout <<"                            ║ " << endl;
                        cout << "╚══════════════════════════════════════════════════════╝" << endl;
                        LeClient->MonCompteBloque.Afficher();
                    break;

            case 2:
                        cout << "╔══════════════════════════════════════════════════════╗" << endl;;
                        cout << "║              Saisir compte bloque                    ║" <<endl;;
                        cout << "╠══════════════════════════════════════════════════════╣" << endl;
                        cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
                        cout << "╚══════════════════════════════════════════════════════╝" << endl;
                        LeClient->MonCompteBloque.Saisir();
                    break;

            case 3:
                        cout << "╔══════════════════════════════════════════════════════╗" << endl;;
                        cout << "║          Temps d existence compte bloque             ║" <<endl;;
                        cout << "╠══════════════════════════════════════════════════════╣" << endl;
                        cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
                        cout << "╠══════════════════════════════════════════════════════╣" << endl;
                        cout << "║ Temps que le compte est ouvert:                      ║ " << endl;
                        cout << "╚══════════════════════════════════════════════════════╝" << endl;
                        LeClient->MonCompteBloque.TempsRestant(date_today);
                    break;

                case 4:
                        cout << "╔══════════════════════════════════════════════════════╗" << endl;;
                        cout << "║            Temps restant compte bloque               ║" <<endl;;
                        cout << "╠══════════════════════════════════════════════════════╣" << endl;
                        cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
                        cout << "╠══════════════════════════════════════════════════════╣" << endl;
                        cout << "║ Temps que le compte est bloque:                      ║ " << endl;
                        cout << "╚══════════════════════════════════════════════════════╝" << endl;
                        LeClient->MonCompteBloque.TempsOuvert(date_today);
                    break;

                case 5:
                        cout << "╔══════════════════════════════════════════════════════╗" << endl;;
                        cout << "║            Changer date compte bloque                ║" <<endl;;
                        cout << "╠══════════════════════════════════════════════════════╣" << endl;
                        cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
                        cout << "╚══════════════════════════════════════════════════════╝" << endl;
                        Saisir_Today(date_today);
                    break;
        }
    }while(choix != 0);
        return;
}

void MenuLivret(Client *LeClient)
{
    int choix;
	double interet;
    cout << "╔══════════════════════════════════════════════════════╗" << endl;;
    cout << "║              Gestion Livret Epargne                   ║" <<endl;;
    cout << "╠══════════════════════════════════════════════════════╣" << endl;
    cout << "╟──────────────────────────────────────────────────────╢" << endl;
    cout << "║ Que voulez vous faire?                               ║ " << endl;
    cout << "║ 1. Ajouter de l'argent à votre compte épargne        ║ " << endl;
    cout << "║ 2. Calcul de vos intérêts sur l'année                ║ " << endl;
    cout << "║ 3. Cloturer le Livret Epargne                        ║ " << endl;
    cout << "╟──────────────────────────────────────────────────────╢" << endl;
    cout << "║ 0. Retour au menu principal.                         ║ " << endl;
    cout << "╚══════════════════════════════════════════════════════╝" << endl;
    cout<<"Entrer l'opération à effectuer : ";
    cin>>choix;

      while(choix<0 || choix>3)
    {
        cout<<"Erreur ! Entrer un chiffre entre 0 et 3 : ";
        cin>>choix;
    }
    switch(choix)
	{
		case 0 :	return;
					break;

		case 1 :	LeClient->MonLivret.Ajouter();
					break;

		case 2 :	interet=LeClient->MonLivret.CalculInteret();
					cout<<"Vos intérêts durant l'année sont de "<<interet<<"€"<<endl;
					break;
		case 3 :	LeClient->MonLivret.Cloturer();
					cout<<"Votre compte épargne a bien été clôturé"<<endl;
					break;
	}


}

void MenuECompte(Client *LeClient,  int *today)
{
    int choix;

    do
    {
        cout << "╔══════════════════════════════════════════════════════╗" << endl;;
        cout << "║              Gestion E-Compte                        ║" <<endl;;
        cout << "╠══════════════════════════════════════════════════════╣" << endl;
        cout << "║ "; Afficher_Today(today) ; cout <<"                  ║ " << endl;
        cout << "╟──────────────────────────────────────────────────────╢" << endl;
        cout << "║ Que voulez vous faire?                               ║ " << endl;
        cout << "║ 1. Afficher le compte                                ║ " << endl;
        cout << "║ 2. Ajouter de l'argent.                              ║ " << endl;
        cout << "║ 3. Retirer de l'argent.                              ║ " << endl;
        cout << "║ 4. Modifier les coordonnees.                         ║ " << endl;
        cout << "╟──────────────────────────────────────────────────────╢" << endl;
        cout << "║ 0. Retour au menu principal.                         ║ " << endl;
        cout << "╚══════════════════════════════════════════════════════╝" << endl;

        cout<<"\nVotre choix:";
        cin>>choix;

        switch(choix)
        {
            case 1: LeClient->MonECompte.Afficher();
                    break;

            case 2: LeClient->MonECompte.Ajouter();
                    break;

            case 3: LeClient->MonECompte.Retrait();
                    break;

            case 4: LeClient->MonECompte.ChangerCoordonnes();
                    break;

            case 0: return;
                    break;

            default : cout<<"Ce choix n'est pas valide !\n";
                      break;
        }
    }
    while(choix !=0);
}

void MenuPel(Client *LeClient,  int *date_today)
{
	int choix, montant;

    // date_today est un tableau de 3 entiers représentant la date du jour: date_today[0] est le jour, date_today[1] est le mois, date_today[2] est l'année
	// Volontairement, je ne fais pas de fonction Bon dans le temps, il suffira de rajouter le temps voulu aux moments données dans l'application. Ceci explique mon choix d'un tableau d'entier.


	do
	{
		cout << "╔══════════════════════════════════════════════════════╗" << endl;;
		cout << "║                    Gestion du PEL                    ║" <<endl;;
		cout << "╠══════════════════════════════════════════════════════╣" << endl;
		cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
		cout << "╟──────────────────────────────────────────────────────╢" << endl;
		cout << "║ Que voulez vous faire?                               ║" << endl;
		cout << "║ 1. Afficher le compte                                ║" << endl;
		cout << "║ 2. Saisir le taux interet et les versements mensuels.║" << endl;
		cout << "║ 3. Voir combien de temps avant d'emprunter           ║" << endl;
		cout << "║ 4. Verser de l'argent                                ║" << endl;
		cout << "║ 5. Retirer de l'argent                               ║" << endl;
		cout << "╟──────────────────────────────────────────────────────╢" << endl;
		cout << "║ 6. Avancer dans le temps.                            ║" << endl;
		cout << "║ 0. Retour au menu principal.                         ║" << endl;
		cout << "╚══════════════════════════════════════════════════════╝" << endl;
		cout << "\tEntrer l operation a effectuer: ";
		cin >> choix;

		if (choix < 0 || choix > 6)
		{
			cout << "\tMerci de choisir un chiffre entre 0 et 6!" << endl;
			cin >> choix;
		}
		else
		{
			switch(choix)
			{
				case 0:
					return;
					break;

				case 1:
					cout << "╔══════════════════════════════════════════════════════╗" << endl;
					cout << "║                     Afficher PEL                     ║" << endl;
					cout << "╠══════════════════════════════════════════════════════╣" << endl;
					cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
					cout << "╚══════════════════════════════════════════════════════╝" << endl;
					LeClient->MonPel.Afficher();
					break;

				case 2:
					cout << "╔══════════════════════════════════════════════════════╗" << endl;
					cout << "║                      Saisir PEL                      ║" << endl;
					cout << "╠══════════════════════════════════════════════════════╣" << endl;
					cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
					cout << "╚══════════════════════════════════════════════════════╝" << endl;
					LeClient->MonPel.Saisir(cin);
					break;

				case 3:
					cout << "╔══════════════════════════════════════════════════════╗" << endl;
					cout << "║           Temps restant avant d'emprunter            ║" << endl;
					cout << "╠══════════════════════════════════════════════════════╣" << endl;
					cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
					cout << "╠══════════════════════════════════════════════════════╣" << endl;
					cout << "║ Emprunt possible dans:                               ║" << endl;
					cout << "╚══════════════════════════════════════════════════════╝" << endl;
					LeClient->MonPel.TempsRestantAvantEmprunt(date_today);
					break;

				case 4:
					cout << "╔══════════════════════════════════════════════════════╗" << endl;
					cout << "║                    Dépôt d'argent                    ║" << endl;
					cout << "╠══════════════════════════════════════════════════════╣" << endl;
					cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
					cout << "╠══════════════════════════════════════════════════════╣" << endl;
					cout << "║ Votre PEL doit avoir moins de 4 ans.                 ║" << endl;
					cout << "║ Saisissez le montant du dépôt:                       ║" << endl;
					cout << "╚══════════════════════════════════════════════════════╝" << endl;
					cin >> montant;
					LeClient->MonPel.Deposer(date_today, montant);
					break;

				case 5:
					cout << "╔══════════════════════════════════════════════════════╗" << endl;
					cout << "║                   Retrait d'argent                   ║" << endl;
					cout << "╠══════════════════════════════════════════════════════╣" << endl;
					cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
					cout << "╠══════════════════════════════════════════════════════╣" << endl;
					cout << "║ Votre PEL doit avoir plus de 4 ans.                  ║" << endl;
					cout << "║ Saisissez le montant du retait:                      ║" << endl;
					cout << "╚══════════════════════════════════════════════════════╝" << endl;
					cin >> montant;
					LeClient->MonPel.Retirer(date_today, montant);
					break;
				case 6:
					cout << "╔══════════════════════════════════════════════════════╗" << endl;
					cout << "║                 Avancer dans le temps                ║" << endl;
					cout << "╠══════════════════════════════════════════════════════╣" << endl;
					cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
					cout << "╠══════════════════════════════════════════════════════╣" << endl;
					cout << "║ (attention a ne pas avancer trop vite!)              ║" << endl;
					cout << "║ Saisissez le nombre d'années à avancer:              ║" << endl;
					cout << "╚══════════════════════════════════════════════════════╝" << endl;
					cin >> montant;
					Ajouter_An(date_today, montant);
					LeClient->MonPel.AvancerAnnees(date_today);
					break;
			}
		}
	}
	while (choix != 0);
}
