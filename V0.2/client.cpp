#include "client.h"

/*Client::Client()
{
    identifiant=(int)(this);
    if(identifiant < 0)
    {
        identifiant=identifiant * -1;
    }
    codesecret=0000;
    nom="MARTIN";
    prenom="Paul";
    adresse="15 rue de la paix";
}*/

Client::Client(int id, int code, string nom, string prenom, string adresse)
{
    string poubelle;        // on cree un string qui nous servira juste pour regler un probleme de tampon memoire
    identifiant=id;
    this->identifiant = (int)(this);
    if(this->identifiant < 0)
    {
        this->identifiant = this->identifiant * -1;
    }

    do{
        cout << "code secret : ";
        cin >> code;
        }while(code < 0 || code > 9999);
    this->codesecret=code;
    getline(cin,poubelle);  // getline pour regler le probleme de tampon
    cout << "nom : ";
    getline(cin,nom);
    this->nom=nom;
    cout << "prenom : ";
    getline(cin,prenom);
    this->prenom=prenom;
    cout << "adresse : ";
    getline(cin,adresse);
    this->adresse=adresse;

}

void Client::Afficher(ostream &out) const
{
    out << "id : " << identifiant << "\t" << setfill('0')  << "code : " << setw(4) << codesecret << endl;
    out << "nom : " << nom << "\t" << "prenom : " << prenom << endl;
    out << "adresse : " << adresse << endl;
}

void Client::Saisir(istream &in)
{
    string poubelle;        // on cree un string qui nous servira juste pour regler un probleme de tampon memoire

    cout << "Saisir les informations relatives au client : \n";
    identifiant = (int)(this);
    if(this->identifiant < 0)
    {
        this->identifiant = this->identifiant * -1;
    }
    cout << "code secret : ";
    in >> codesecret;
    getline(in,poubelle);  // getline pour regler le probleme de tampon
    cout << "nom : ";
    getline(in,nom);
    cout << "prenom : ";
    getline(in,prenom);
    cout << "adresse : ";
    getline(in,adresse);
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
