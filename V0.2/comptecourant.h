/**
Par Pierre
**/

#include "compte.h"
#include <vector>
#include <cstring>
#include <fstream>
#include <limits>
#include <iomanip>


using namespace std;

#ifndef COMPTECOURANT_H
#define COMPTECOURANT_H

class CompteCourant: public Compte
{
private:
    double decouvert;
    double aggio;
    string nomfichier;

    Date Date_temp; //date temporaire pour remplir le vector
    vector <Date> Tab_Date; //Vector de Date, sert pour le calcul des aggios
    vector <Date>::iterator it; //iterateur de Tab_Date


public:
    CompteCourant(double decouvert = 0, double aggio = 0);//, int id = 0, double solde = 0.0, int jour = 0, int mois = 0, int annee = 0, int identifiant = 0, int code = 0, string nom = "noname", string prenom = "noprenom", string adresse = "noadresse");
    ~CompteCourant() {};

    void Afficher();
    void ChangerCoordonnes();
    double Consulter(const int *today);
    void Cloturer();
    bool EstOuvert();

    void AjouterArgent(const int *today);
    void RetirerArgent(const int *today);
    void SeuilAlerte(const int *today);

    void CalculerAgios(const int *today);
    void AppliquerAgios();

    void ImprimerAction(string nom_operation, double montant, const int *today);
    void ImprimerTicket(const int *today);

};

#endif // COMPTECOURANT_H
