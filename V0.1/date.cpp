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

    // saisir jour
    do
    {
    cout << "Saisissez le jour: " <<endl;
    cin >> j;
        if((j < 1) || (j > 31))
        cout << "Saisie incorrecte!" <<endl;
    }while((j<1) || (j > 31));
    this->jour = j;
    // saisir mois
    do
    {
    cout << "Saisissez le mois: " <<endl;
    cin >> m;
        if((m < 1) || (m > 12))
        cout << "Saisie incorrecte!" <<endl;
    }while((m < 1) || (m > 12));
    this->mois = m;
    //  saisir annee
    do
    {
    cout << "Saisissez l annee: " <<endl;
    cin >> a;
        if((a < 1) || (a > 9999))
        cout << "Saisie incorrecte!" <<endl;
    }while((a < 1) || (a > 9999));
    this->annee = a;
}

Date::~Date()
{
}

void Date::Afficher(ostream &out) const
{
    out << jour << "/" << mois << "/" << annee << endl;
}

void Date::Saisir(istream &in)
{
    // saisir jour
    do
    {
    cout << "Saisissez le jour: " <<endl;
    cin >> jour;
        if((jour < 1) || (jour > 31))
        cout << "Saisie incorrecte!" <<endl;
    }while((jour<1) || (jour > 31));
    // saisir mois
    do
    {
    cout << "Saisissez le mois: " <<endl;
    cin >> mois;
        if((mois < 1) || (mois > 12))
        cout << "Saisie incorrecte!" <<endl;
    }while((mois < 1) || (mois > 12));
    //  saisir annee
    do
    {
    cout << "Saisissez l annee: " <<endl;
    cin >> annee;
        if((annee < 1) || (annee > 9999))
        cout << "Saisie incorrecte!" <<endl;
    }while((annee < 1) || (annee > 9999));
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

istream &operator>>(istream &in, Date &D)
{
    D.Saisir(in);
    return in;
}
