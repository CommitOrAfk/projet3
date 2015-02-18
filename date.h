/** date.h work in progress
**/
#include <iostream>
#include <ostream>

using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
protected:
    int jour;
    int mois;
    int annee;

public:
    // constructeur/destructeur
    Date();
    Date(int j, int m, int a);
    ~Date();
    // fonctions membres
    void Afficher(ostream &out) const;
    Date operator+(int a) const;
    Date& operator=(const Date &D);
    Date& operator<(const Date &D);
};

ostream &operator<<(ostream &out, const Date &D);
#endif // DATE_H
