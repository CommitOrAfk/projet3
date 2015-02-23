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

int Afficher_Clients( vector <Client> MesClients);
void Saisir_Clients(vector <Client> *MesClients);

int main()
{



int date_today[3]; // date_today est un tableau de 3 entiers représentant la date du jour: date_today[0] est le jour, date_today[1] est le mois, date_today[2] est l'année

cout<<"Bienvenue a la banque LDNR, avant de commencer, veuillez saisir la date d'aujourd'hui:\n";
Saisir_Today(date_today);

/*cout<<"Creation d'un compte courant\n";
CompteCourant CC(0,0);

cout<<"Affichage du compte courant\n";
CC.Afficher();

int choix=0;
int nb_jour = 0;
do{
    Afficher_Today(date_today);
    cout<<"\nQue voulez-vous faire?\n";
    cout<<"*** 1-Afficher le compte ***\n";
    cout<<"*** 2-Ajouter de l'argent***\n";
    cout<<"*** 3-Retirer de l'argent***\n";
    cout<<"*** 4-Imprimer un ticket ***\n";
    cout<<"*** 0-Quitter            ***\n";
    cout<<"\n *** 5-Ajouter des jours  ***\n";
    cout<<"Votre choix:";

    cin>>choix;


    switch(choix)
    {
        case 1: CC.Afficher();
            break;
        case 2: CC.AjouterArgent(date_today);
            break;
        case 3: CC.RetirerArgent(date_today);
            break;
        case 4: CC.ImprimerTicket(date_today);
            break;
        case 5: cout<<"\nAjouter combien de jours? ";
                cin>>nb_jour;
                Ajouter_Jour(date_today, nb_jour);
            break;
        case 0: return 0;
            break;
        default: cout<<"erreur\n";
            break;
    }
    Ajouter_Jour(date_today, 1);
    CC.SeuilAlerte(date_today);
}while(choix != 0);
*/

vector <Client> Tab_Client;


Saisir_Clients(&Tab_Client);
/*Client Nouveau;
Tab_Client.push_back(Nouveau);*/

int nb_clients = Afficher_Clients(Tab_Client);
cout<<"\nIl y a "<<nb_clients -1<<" clients\n";



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
    cout<<"Nous sommes le: "<< today[0]<<"/"<<today[1]<<"/"<<today[2]<<endl;
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
