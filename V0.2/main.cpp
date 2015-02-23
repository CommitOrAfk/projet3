/** main.cpp juste pour tester
test date uniquement pour l'instant
**/
#include "date.h"
#include "client.h"
#include "compte.h"
#include "test.h"
#include "comptebloque.h"
#include "pel.h"
#include <vector>

void Saisir_Today(int *today);
void Afficher_Today(const int *today);
void Ajouter_Jour(int *today, int nb_jour_ajoute);
void Ajouter_Mois(int *today, int nb_mois_ajoute);
void Ajouter_An(int *today, int nb_an_ajoute);

void TesterPel();

int main()
{
	TesterPel();
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
        if((today[2] < 1) || (today[2] > 2018))
        cout << "Saisie incorrecte!" <<endl;
    }while((today[2] < 1) || (today[2] > 2018));
}

//Affichage de la date du jour
void Afficher_Today(const int *today)
{
    cout<<"Date du jour: "<< today[0]<<"/"<<today[1]<<"/"<<today[2]<<endl;
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

void VerifierChoix(int petit, int grand, int chiffre_a_comparer)
{
    while(chiffre_a_comparer<petit || chiffre_a_comparer>grand)
    {
        cout<<"Erreur ! Entrer un chiffre entre "<<petit<<" et "<<grand <<" : ";
        cin>>chiffre_a_comparer;
    }
}

void TesterPel()
{
	time_t today = time(NULL);
	tm* todayTm  = localtime(&today);
	int date_today[3]; // date_today est un tableau de 3 entiers représentant la date du jour: date_today[0] est le jour, date_today[1] est le mois, date_today[2] est l'année
	// Volontairement, je ne fais pas de fonction Bon dans le temps, il suffira de rajouter le temps voulu aux moments données dans l'application. Ceci explique mon choix d'un tableau d'entier.
	date_today[0] = todayTm->tm_mday;
	date_today[1] = todayTm->tm_mon + 1;
	date_today[2] = todayTm->tm_year + 1900;
	Afficher_Today(date_today);
	cout << "Saisie du compte:" << endl;
	Pel C1;
	cin >> C1;

	C1.Afficher();
	cout << "Solde: " << C1.Consulter() << endl;

	cout << "Dépot de 100€." << endl;
	C1.Deposer(date_today, 100);
	C1.TempsRestantAvantEmprunt(date_today);
	C1.CalculerEmprunt(date_today);

	cout << "Premier saut de 6 ans dans le futur." << endl;
	Ajouter_An(date_today, 6);
	C1.AvancerAnnees(date_today);

	cout << "Retrait de 100€." << endl;
	C1.Retirer(date_today, 100);
	C1.CalculerEmprunt(date_today);

	cout << "Dernier saut dans le temps de 2 ans." << endl;
	Ajouter_An(date_today, 2);
	C1.AvancerAnnees(date_today);
}
