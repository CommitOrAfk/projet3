#include "ecompte.h"

ECompte::ECompte()
{
    this->mail="trololo@yahoo.co.uk";
    this->numTel="118712-3615-36656565";
}

ECompte::ECompte(string mail, string num): Compte(id, solde)
{
    this->mail=mail;
    numTel=num;
    this->solde=solde+50;   //50 euros offert à l'ouverture
}

void ECompte::Ajouter()
{
    double montant;

    if (isOpen)     //Si le compte est ouvert
	{
        do
        {
            cout<<"Combien d'argent voulez vous ajouter ?"<<endl;
            cin>>montant;

            if(montant<0)       //Si le montant saisie est negatif
                cout<<"Veuillez saisir un montant positif s'il vout plait"<<endl;
        }
        while(montant<0);       //Tant que le montant saisie est negatif

        solde=solde+montant;
    }
	else
	{
		cout << "Ce compte est cloturé, impossible de faire une quelconque action." << endl;
	}
}

void ECompte::Retrait()
{
    double montant;
    if (isOpen)     // Si le compte est ouvert
	{
        do
        {
            cout<<"Combien d'argent voulez vous retirer?"<<endl;
            cin>>montant;

            if(solde-montant<10)        // Si le solde moins le montant est inferieur a 10
            {
                cout<<"Operation impossible, vous devez laisser au minimum 10 euros sur le compte"<<endl;
                cout<<"Actuellement vous pouvez retirer au maximum "<<fixed<<setprecision(2)<<(solde-10)<<" euros."<<endl;
            }

            if(montant<0)               // Si le montant saisie est negatif
                cout<<"Veuillez saisir un montant positif s'il vout plait"<<endl;
        }
        while((solde-montant<10) || (montant<0));       // Tant que le solde moins le montant est inferieur a 10 ou que le montant est negatif

        cout<<"Retrait de "<<fixed<<setprecision(2)<<montant<<" euros bien effectue."<<endl;

        solde=solde-montant;
    }
	else
	{
		cout << "Ce compte est cloturé, impossible de faire une quelconque action." << endl;
	}
}

void ECompte::ChangerCoordonnes()
{
    if (isOpen)     // Si le compte est ouvert
	{
		Compte::ChangerCoordonnes();
		cout<<"Changer vos coordonnées"<<endl;
		cout <<"Entrer une nouvelle adresse email : ";
		cin>>mail;
		cout<<"Entrer un nouveau numero de telephone : ";
		cin>>numTel;
	}
	else
	{
		cout << "Ce compte est cloturé, impossible de faire une quelconque action." << endl;
	}
}

void ECompte::Afficher()
{
    Compte::Afficher();
    if(isOpen)      // Si le compte est ouvert
    {
        cout<<"Adresse email : "<<mail<<endl;
        cout<<"Numero de telephone : "<<numTel<<endl;
    }
}
