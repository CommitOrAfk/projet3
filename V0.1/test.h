#include "compte.h"

#ifndef TEST_H
#define TEST_H

class Test: public Compte
{
private:
    double txinteret;
public:
    Test(double tx = 0.0, int id = 0, double solde = 0.0, int jour = 0, int mois = 0, int annee = 0, int identifiant = 0, int code = 0, string nom = "noname", string prenom = "noprenom", string adresse = "noadresse");
    ~Test() {};

    void Afficher();
};

#endif // TEST_H
