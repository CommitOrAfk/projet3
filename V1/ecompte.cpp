/**
* @author Sofian HAMADACHE
**/

#include "ecompte.h"

ECompte::ECompte()
{
    this->mail="trololo@yahoo.co.uk";
    this->numTel="118712-3615-36656565";
}

ECompte::ECompte(string mail, string num): Compte(id, solde)
{
    this->mail = "";
    this->numTel = "";
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

void ECompte::Afficher() const
{
    cout<<"*** E-Compte ***\n";
    Compte::Afficher();
    if(isOpen)      // Si le compte est ouvert
    {
        cout<<"Adresse email : "<<mail<<endl;
        cout<<"Numero de telephone : "<<numTel<<endl;
    }
}

void ECompte::Cloturer(const int *today)
{
    int date_compte[3]; // la meme chose qu'au dessus mais pour la date d'ouverture du compte

    date_compte[0]=this->DateOuverture.jour;
    date_compte[1]=this->DateOuverture.mois;
    date_compte[2]=this->DateOuverture.annee;

    if(today[2]>=(date_compte[2]+2))        // Si le compte est ouvert depuis 2 ans il se cloture automatiquement
        if(today[1]>=date_compte[1])
            if(today[0]>=date_compte[0])
                Compte::Cloturer();

    if(isOpen)      // Petit if pour regler un cas particulier
    {
        if(today[2]>(date_compte[2]+2))
        Compte::Cloturer();
    }
}


void ECompte::CalculInterets(const int *today)
{
    double tauxInteret3Mois=0.045, tauxInteretNormal=0.015; //    tauxInteret=4.5% pendant 3 mois et tauxInteretNormal= taux annuel de 1.5%
    double interets=0;

    int anneeCreation, anneeEnCours,moisCreation,moisEnCours;
    anneeCreation=this->DateOuverture.annee;
    anneeEnCours=today[2];
    moisCreation=this->DateOuverture.mois;
    moisEnCours=today[2];

    int i=0,limit;

    while(anneeCreation<=anneeEnCours)
    {
    	if (anneeCreation == anneeEnCours)
        {
            limit = moisEnCours;
        }
    	else
        {
            limit = 12;
        }

        while(moisCreation<=limit)
        {
            if(i<24)
            {
                if(i<3)
                {
                    interets=interets+this->solde*(tauxInteret3Mois/12);
                }
                else
                    interets=interets+this->solde*(tauxInteretNormal/12);
                i++;
                moisCreation++;
            }
        }
        anneeCreation++;
        moisCreation = 1;
    }
    this->solde=this->solde+interets;
}
