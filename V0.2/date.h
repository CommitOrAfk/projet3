/** date.h work in progress
**/
#include <iostream>
#include <ostream>

using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{

public:

    int jour;
    int mois;
    int annee;
    // constructeur/destructeur
    Date();
    Date(int j, int m, int a);
    ~Date();
    // fonctions membres
    void Afficher(ostream &out) const;
    void Saisir(istream &in);
    Date operator+(int a) const;
    Date& operator=(const Date &D);
    bool operator<(const Date &D);
    bool operator==(const Date &D);
};

ostream &operator<<(ostream &out, const Date &D);
istream &operator>>(istream &in, Date &D);
#endif // DATE_H
