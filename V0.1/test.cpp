#include "test.h"

Test::Test(double tx): Compte(int id, double solde), Compte::Date(int jour, int mois, int annee), Compte::Client(int id, int code, string nom, string prenom, string adresse)
{
}

void Test::Afficher()
{
    cout << "Taux interet: " << setprecision(1) << txinteret << endl;
    Compte::Afficher();
}
