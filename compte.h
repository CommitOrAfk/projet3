/** date.cpp work in progress
**/
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
    Date DateOuverture;
    Client ClientCompte;
public:
    // constructeurs/destructeur
    Compte();
    Compte(int id = 0, double solde =0);
    virtual ~Compte();
    Afficher();
    void ChangerCoordonnes();
    void Consulter();
    Cloturer();
    // fonctions membres

};

#endif
