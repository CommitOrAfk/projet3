/** date.cpp work in progress
Par le groupe
**/
#include "date.h"
#include <sstream>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

#ifndef COMPTE_H
#define COMPTE_H

class Compte
{
protected:
    int id;
    double solde;

    bool isOpen;


public:
    Date DateOuverture;

    // constructeurs/destructeur
    //Compte();
    Compte(int id = 0, double solde =0);
    virtual ~Compte();
    virtual void Afficher() const;
    //virtual void ChangerCoordonnes();
    virtual double Consulter();
    virtual void Cloturer();
    virtual bool EstOuvert() const;

    int CalculIntervalle(const int *today, const int *date, int &resJours, int &resMois, int &resAns);
    int getjour();
    int getmois();
    int getannee();
    // fonctions membres

};

#endif
