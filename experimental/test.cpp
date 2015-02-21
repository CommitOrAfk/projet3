#include "test.h"

Test::Test(double tx): Compte(id, solde)//, Compte::Date(int jour, int mois, int annee), Compte::Client(int id, int code, string nom, string prenom, string adresse)
{
    this->txinteret = tx;
    this->isOpen = true;

}

void Test::Afficher()
{
    cout << "Taux interet: " << setprecision(1) << txinteret << endl;
    Compte::Afficher();
}

void Test::ChangerCoordonnes()
{
    //TODO
}
double Test::Consulter()
{
    //TODO
    return 0;
}
void Test::Cloturer()
{
    //TODO
}

bool Test::EstOuvert()
{
    //TODO
    return true;
}


