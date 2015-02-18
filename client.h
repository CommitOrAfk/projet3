/** client.h work in progress
**/
#include <iostream>
#include <string>

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
        Client();
        Client(int id = 0, int code = 0, string nom = "noname", string prenom = "noprenom", string adresse = "noadresse");
};
#endif // CLIENT_H
