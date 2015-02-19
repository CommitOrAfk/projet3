#include "client.h"

Client::Client()
{
    identifiant=(int)(this);
    codesecret=0000;
    nom="MARTIN";
    prenom="Paul";
    adresse="15 rue de la paix";
}

Client::Client(int id, int code, string nom, string prenom, string adresse)
{
    identifiant=id;
    this->identifiant = (int)(this);
    if(this->identifiant < 0)
    {
        this->identifiant = this->identifiant * -1;
    }
    codesecret=code;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
}

void Client::Afficher(ostream &out) const
{
    out << "id : " << identifiant << "\t" << "code : " << codesecret << endl;
    out << "nom : " << nom << "\t" << "prenom : " << prenom << endl;
    out << "adresse : " << adresse << endl;
}

void Client::Saisir(istream &in)
{
    cout << "Saisir les informations relatives au client : \n";
    cout << "ID : ";
    cin >> identifiant;
    identifiant = (int)(this);
    if(this->identifiant < 0)
    {
        this->identifiant = this->identifiant * -1;
    }
    cout << "code secret : ";
    cin >> codesecret;
    cout << "nom : ";
    getline(cin,nom);
    cout << "prenom : ";
    getline(cin,prenom);
    cout << "adresse : ";
    getline(cin,adresse);
}

ostream &operator<<(ostream &out, const Client &C)
{
    C.Afficher(out);
    return out;
}

istream &operator>>(istream &in, Client &C)
{
    C.Saisir(in);
    return in;
}
