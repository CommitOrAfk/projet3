#include "compte.h"

Compte::Compte()
{
    
}

Compte::Compte(int id, double solde)
{
    this->id=id;
    this->solde=solde;
}

Compte::~Compte()
{
    cout<<"Destructeur du compte"<<endl;
}

void Compte::ChangerCoordonnes() 
{
    int choix, reponse;
    
    reponse=1;
    do
    {
        
    
        cout<<"Changer vos coordonnées"<<endl;

        cout<<"1. Nom"<<endl<<"2. Prénom"<<endl<<"3. Adresse"<<endl;

        cout<<"Entrer les coordonées à changer : ";
        cin >>choix;
        while(choix<1 || choix>3)
        {
            cout<<"Erreur ! Entrer un chiffre entre 1 et 3 : ";
            cin >>choix;
        }
        switch(choix)
        {
            case 1: cout<<"Entrer un nouveau nom : ";
                    cin>>ClientCompte.nom;
                    break;

            case 2: cout<<"Entrer un nouveau prénom : ";
                    cin >>ClientCompte.prenom;
                    break;
            case 3: cout <<"Entrer une nouvelle adresse : ";
                    cin>>ClientCompte.adresse;
                    break;
        }
        cout<<"Voulez-vous changer à nouveau vos coordonnées : ";
        cin>>reponse;
        while (reponse<1 || reponse >2)
        {
            cout<<"Erreur ! Entrer un chifrre entre 1 et 2 : ";
            cin>>reponse;
        }
    }while(reponse==1);
}

