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
        ECompte();
        ECompte(string mail, string num="118218");
        // fonctions membres
        void Ajouter();
        void Retrait();
        void ChangerCoordonnes();
        void Afficher();
};

#endif // ECOMPTE_H
