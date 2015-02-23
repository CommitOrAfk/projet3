#include "date.h"
#include "client.h"
#include "compte.h"
#include "pel.h"
#include <vector>
#include <iostream>
using namespace std;

void Saisir_Today(int *today);
void Afficher_Today(const int *today);
void Ajouter_Jour(int *today, int nb_jour_ajoute);
void Ajouter_Mois(int *today, int nb_mois_ajoute);
void Ajouter_An(int *today, int nb_an_ajoute);
void MenuPel(Pel &P);

int main()
{
	Pel P;
	MenuPel(P);
}
void MenuPel(Pel &P)
{
	int choix, montant;

    // date_today est un tableau de 3 entiers représentant la date du jour: date_today[0] est le jour, date_today[1] est le mois, date_today[2] est l'année
	// Volontairement, je ne fais pas de fonction Bon dans le temps, il suffira de rajouter le temps voulu aux moments données dans l'application. Ceci explique mon choix d'un tableau d'entier.
    time_t today = time(NULL);
	tm* todayTm  = localtime(&today);
	int date_today[3];

	date_today[0] = todayTm->tm_mday;
	date_today[1] = todayTm->tm_mon + 1;
	date_today[2] = todayTm->tm_year + 1900;

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
					P.Afficher();
					break;

				case 2:
					cout << "╔══════════════════════════════════════════════════════╗" << endl;
					cout << "║                      Saisir PEL                      ║" << endl;
					cout << "╠══════════════════════════════════════════════════════╣" << endl;
					cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
					cout << "╚══════════════════════════════════════════════════════╝" << endl;
					P.Saisir(cin);
					break;

				case 3:
					cout << "╔══════════════════════════════════════════════════════╗" << endl;
					cout << "║           Temps restant avant d'emprunter            ║" << endl;
					cout << "╠══════════════════════════════════════════════════════╣" << endl;
					cout << "║ "; Afficher_Today(date_today) ; cout <<"                              ║ " << endl;
					cout << "╠══════════════════════════════════════════════════════╣" << endl;
					cout << "║ Emprunt possible dans:                               ║" << endl;
					cout << "╚══════════════════════════════════════════════════════╝" << endl;
					P.TempsRestantAvantEmprunt(date_today);
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
					P.Deposer(date_today, montant);
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
					P.Retirer(date_today, montant);
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
					P.AvancerAnnees(date_today);
					break;
			}
		}
	}
	while (choix != 0);
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
    cout<<"Date du jour: "<< today[0]<<"/"<<today[1]<<"/"<<today[2];
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
