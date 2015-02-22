/** Class: Compte Bloque    Alexander
Particularités:
compte bloqué pendant 4 ans (ou 48 mois)
**/
#include "compte.h"
#include <ctime>
using namespace std;

#ifndef COMPTEBLOQUE_H
#define COMPTEBLOQUE_H

class CompteBloque: public Compte
{
private:
    static int dureeblocage; // en mois
    double txinteret; // par an
    int dureeouverture; // en mois ?
public:
    CompteBloque(double tx = 1.1, int dureeouverture = 0);
    ~CompteBloque() {};

    void Afficher();
    void TempsRestant(const int *today);


};

#endif // TEST_H

