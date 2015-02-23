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
    private:

        double taux_remuneration;
        double plafond;


    public:

        Livret();
        void Ajouter();
        double CalculInteret();
        void Afficher() const;
        void Saisir();
        void Cloturer();
        double Consulter();
        void EstOuvert();


        virtual ~Livret();

};

#endif	/* LIVRET_H */

