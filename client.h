#include <iostream>
#include <ostream>
#include <string>
#include <iomanip>

using namespace std;

#ifndef CLIENT_H
#define CLIENT_H

class Client
{
protected:
    int identifiant;
    int codesecret;
    string nom;
    string prenom;
    string adresse;

    public:
        // constructeurs/destructeur
        Client();
        Client(int id = 0, int code = 0, string nom = "noname", string prenom = "noprenom", string adresse = "noadresse");
        ~Client(){}
        // fonctions membres
        void Afficher(ostream &out) const;
        void Saisir(istream &in);
};

ostream &operator<<(ostream &out, const Client &C);
istream &operator>>(istream &in, Client &C);

#endif // CLIENT_H
