/** date.cpp work in progress
**/
#include <ctime>
#include <cstdlib>
#include "client.h"
#include "date.h"
using namespace std;

#ifndef COMPTE_H
#define COMPTE_H

class Compte
{
protected:
    int id;
    double solde;
    //Date DateOuverture(1,1,1970);
    //Client ClientCompte(111, 0000, "nom", "prenom", "adresse");
    Date DateOuverture;
    Client ClientCompte;
    bool isOpen;

public:
    // constructeurs/destructeur
    //Compte();
    Compte(int id = 0, double solde =0);
    virtual ~Compte();
    virtual void Afficher();
    virtual void ChangerCoordonnes();
    virtual double Consulter();
    virtual void Cloturer();
    virtual bool EstOuvert();
    // fonctions membres
};

#endif
