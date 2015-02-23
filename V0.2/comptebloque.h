/** Class: Compte Bloque    Alexander
Particularités:
compte bloqué pendant 4 ans
Somme verse initialement + versements par mois
Taux interet calcule a l annee
**/
#include "compte.h"
#include <ctime>
using namespace std;

#ifndef COMPTEBLOQUE_H
#define COMPTEBLOQUE_H

class CompteBloque: public Compte
{
private:
    static int dureeblocage; // en annees
    double txinteret; // par an
    double versements;
public:
    CompteBloque(double tx = 1.1, double versements = 0.0);
    ~CompteBloque() {};

    void Afficher();
    void Saisir();
    void TempsRestant(const int *today);
    void CalculInterets(const int *today);
    void TempsOuvert(const int *today);
};

#endif // TEST_H

