/** date.cpp work in progress
**/
#include "date.h"

Date::Date()
{
    jour = 1;
    mois = 1;
    annee = 00;
}

Date::Date(int j, int m, int a)
{
    cout << "constructeur parametre par default" << endl; //!debug
    jour = j;
    mois = m;
    annee = a;
}

Date::~Date()
{
}

void Date::Afficher(ostream &out) const
{
    cout << jour << "/" << mois << "/" << annee << endl;
}

// operator +, ajoute a à l annee
Date Date::operator+(int a) const
{
    Date D = *this;
    D.annee = D.annee + a;
    return D;
}
//operator =
Date& Date::operator=(const Date &D)
{
    this->jour = D.jour;
    this->mois = D.mois;
    this->annee = D.annee;
    return (*this);
}

//operator <
bool Date::operator<(const Date &D)
{
    //Les cas où la date est plus ancienne
    if((this->annee) < D.annee)
    {
        cout << "La date est plus ancienne"  << endl;
        return true;
    }
    if((this->annee) == D.annee && (this->mois) < D.mois)
    {
        cout << "La date est plus ancienne"  << endl;
        return true;
    }
    if((this->annee) == D.annee && (this->mois) == D.mois && (this->jour) < D.jour)
    {
        cout << "La date est plus ancienne"  << endl;
        return true;
    }

    //les cas où la date n'est pa plus ancienne
    if((this->annee) > D.annee)
    {
        cout << "La date n est pas plus ancienne."  << endl;
        return false;
    }
    if((this->annee) == D.annee && (this->mois) > D.mois)
    {
        cout << "La date n est pas plus ancienne."  << endl;
        return false;
    }
    if((this->annee) == D.annee && (this->mois) == D.mois && (this->jour) > D.jour)
    {
        cout << "La date n est pas plus ancienne."  << endl;
        return false;
    }
}

bool Date::operator==(const Date &D)
{
    if((this->jour && this->mois && this->annee) == (D.jour && D.mois && D.annee))
    {
        cout << "Les dates sont identiques." <<endl;
        return true;
    }
    else
    {
        cout << "Les dates ne sont pas identiques." <<endl;
        return false;
    }
}

ostream &operator<<(ostream &out, const Date &D)
{
    D.Afficher(out);
    return out;
}
