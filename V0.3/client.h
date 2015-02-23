/*
Par le groupe.
Modification ultérieure: Pierre
*/
#include <iostream>
#include <ostream>
#include <string>
#include <iomanip>

//Inclure les comptes
#include "comptecourant.h"
#include "livret.h"
#include "comptebloque.h"
#include "pel.h"
#include "ecompte.h"

using namespace std;

#ifndef CLIENT_H
#define CLIENT_H

class Client
{
    private:
    CompteCourant MonCompteCourant;
    Livret MonLivret;
    CompteBloque MonCompteBloque;
    Pel MonPel;
    ECompte MonECompte;


    protected:
    int identifiant;
    int codesecret;
    string nom;
    string prenom;


    public:
    string adresse;
        // constructeurs/destructeur
        Client();
        //Client(int id = 0, int code = 0, string nom = "noname", string prenom = "noprenom", string adresse = "noadresse");
        ~Client(){}
        // fonctions membres
        void Afficher(ostream &out) const;
        void Saisir(istream &in);
        void OuvrirCompte();
        void ChangerCoordonnees();
        //void ChangerCoordonnees();
};

ostream &operator<<(ostream &out, const Client &C);
istream &operator>>(istream &in, Client &C);

#endif // CLIENT_H
