/** main.cpp juste pour tester
test date uniquement pour l'instant
**/
#include "date.h"
#include "client.h"
#include "compte.h"
#include "test.h"
#include "comptebloque.h"
#include <vector>

void Saisir_Today(int *today);
void Afficher_Today(const int *today);
void Ajouter_Jour(int *today, int nb_jour_ajoute);
void Ajouter_Mois(int *today, int nb_mois_ajoute);
void Ajouter_An(int *today, int nb_an_ajoute);

int main()
{

int date_today[3]; // date_today est un tableau de 3 entiers représentant la date du jour: date_today[0] est le jour, date_today[1] est le mois, date_today[2] est l'année
int date_compte[3];
int resJ, resM, resA; // vont stocker respectivement une différence entre 2 dates en Jours, Mois et Années
// Volontairement, je ne fais pas de fonction Bon dans le temps, il suffira de rajouter le temps voulu aux moments données dans l'application. Ceci explique mon choix d'un tableau d'entier.

CompteBloque C1(2.5, 0);
date_compte[0] = C1.Compte::getjour();
date_compte[1] = C1.Compte::getmois();
date_compte[2] = C1.Compte::getannee() + 4; // 4 ans de blocage dans le cas du CompteBloque

Saisir_Today(date_today);
Afficher_Today(date_today);

C1.TempsRestant(date_today, date_compte, resJ, resM, resA);

cout << resJ << " jours " << resM << " mois " << resA << " années.\n";

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
