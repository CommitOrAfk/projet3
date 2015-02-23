/**
* @author Sofian HAMADACHE
**/

#include "compte.h"

#ifndef ECOMPTE_H
#define ECOMPTE_H

class ECompte: public Compte
{
    private:
        string mail;    // l'adresse email du client
        string numTel;  // le numero de telephone du client
    public:
        // constructeurs/destructeur
        //ECompte();
        ECompte(string mail = "", string num="");
        // fonctions membres
        void Ajouter();
        void Retrait();
        void ChangerCoordonnes();
        void Afficher() const;
        void Cloturer(const int *today);
        //void CalculInterets(const int *today);
};

#endif // ECOMPTE_H
