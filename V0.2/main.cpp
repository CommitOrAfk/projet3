/** main.cpp juste pour tester
test date uniquement pour l'instant
**/
#include "date.h"
#include "client.h"
#include "compte.h"
#include "test.h"

void Saisir_Today(int *today);
void Afficher_Today(const int *today);

int main()
{
/*Date D1;
Date D2(18, 2, 2015);

D1.Afficher(cout);
D2.Afficher(cout);

if(D1<D2)
{
    cout<<"toto \n";
}
else
{
    cout<<"pa toto \n";
}

D2 = D2+5;
D2.Afficher(cout);

Client C1(1111, 0000, "Aznar", "Pierre", "24, rue de machin Millau");
C1.Afficher(cout);
C1.Saisir(cin);
C1.Afficher(cout);*/

/*Compte Co1(111, 1234.56);
Co1.Afficher();
Co1.ChangerCoordonnes();
Co1.Cloturer();
Co1.Afficher(); //ne marche pas car le compte est cloturé!*/

//Test T1(2.4);
/*Compte *ptr_C01 = new Test(2.4);
ptr_C01->Afficher();
delete ptr_C01;*/

Test T1(2.40);
T1.Afficher();

int date_today[3]; // date_today est un tableau de 3 entiers représentant la date du jour: date_today[0] est le jour, date_today[1] est le mois, date_today[2] est l'année
// Volontairement, je ne fais pas de fonction Bon dans le temps, il suffira de rajouter le temps voulu aux moments données dans l'application. Ceci explique mon choix d'un tableau d'entier.

Saisir_Today(date_today);
Afficher_Today(date_today);


T1.Consulter(date_today);

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
    cout<<"Date du jour: "<< today[0]<<"/"<<today[1]<<"/"<<today[2]<<endl;
}

