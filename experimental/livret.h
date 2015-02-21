/*
 * File:   livret.h
 * Author: jordan
 *
 * Created on 18 février 2015, 20:25
 */
#include "compte.h"
#ifndef LIVRET_H
#define	LIVRET_H

class Livret : public Compte
{
    const static double taux_remuneration=0.0125;
   const static double plafond=22000;


public:

     void Ajouter();
    double CalculInteret();

    void OuvrirCompteEpargne();

    virtual ~Livret();

};

#endif	/* LIVRET_H */

