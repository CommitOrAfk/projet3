#include "compte.h"

/*Compte::Compte()
{

}*/

//Compte::Compte(int id, double solde):DateOuverture(j, m, a), ClientCompte(id, code, nom, prenom, adresse)
Compte::Compte(int id, double solde):DateOuverture(1,1,1970), ClientCompte(1111,0000,"nom","prenom", "adresse")
{
    this->id=id;
    this->id = (int)(this);
    if(this->id < 0)
    {
        this->id = this->id * -1;
    }
    cout<<"Saisir le solde du compte: ";
    cin>>solde;
    this->solde=solde;

}

Compte::~Compte()
{
    cout<<"Destructeur du compte"<<endl;
}

void Compte::ChangerCoordonnes()
{
    cout<<"Changer vos coordonnées"<<endl;
    cout <<"Entrer une nouvelle adresse : ";
    cin>>ClientCompte.adresse;
}

void Compte::Consulter()
{
    cout<<"consultation compte\n";
}

void Compte::Cloturer()
{
    cout<<"cloture compte\n";
}

void Compte::Afficher()
{
    cout<<"Identifiant du compte: "<<this->id<<endl;
    cout<<"Solde :"<<this->solde<<endl;
    ClientCompte.Afficher(cout);
    DateOuverture.Afficher(cout);
}

