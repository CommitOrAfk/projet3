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

void ECompte::Cloturer(const int *today)
{
    int date_today[3]; // date_today est un tableau de 3 entiers représentant la date du jour: date_today[0] est le jour, date_today[1] est le mois, date_today[2] est l'année
    int date_compte[3]; // la meme chose qu'au dessus mais pour la date d'ouverture du compte

    date_compte[0]=this->DateOuverture.jour;
    date_compte[1]=this->DateOuverture.mois;
    date_compte[2]=this->DateOuverture.annee;

    if(date_today[2]>=(date_compte[2]+2))        // Si le compte est ouvert depuis 2 ans il se cloture automatiquement
        if(date_today[1]>=date_compte[1])
            if(date_today[0]>=date_compte[0])
                Compte::Cloturer();

    if(isOpen)      // Petit if pour regler un cas particulier
    {
        if(date_today[2]>(date_compte[2]+2))
        Compte::Cloturer();
    }
}

/*void ECompte::CalculInterets(const int *today)
{
    double tauxInteret=0.045, tauxInteretNormal=0.015; //    tauxInteret=4.5% pendant 3 mois et tauxInteretNormal= taux annuel de 1.5%

    int anneeCreation, anneeEnCours,moisCreation,moisActuel;
    anneeCreation=this->DateOuverture.annee;
    anneeEnCours=today[2];
    moisCreation=this->DateOuverture.mois;
    moisActuel=today=[2];

    if((anneeEnCours==anneeCreation)&&(anneeEnCours + 1) < (anneeCreation +2))
    {
        this->solde = this->solde * txinteret;
    }
    else if(anneeEnCours>anneeCreation)
    {
        this->solde=this->solde*(1+tauxInteretNormal);
    }
    else if((anneeEnCours +3) > (anneeCreation + 2) && (anneeEnCours + 3) < (anneeCreation + 4))
    {
        this->solde = this->solde * (txinteret * txinteret * txinteret);
    }
    else
    {
        this->solde = this->solde * (txinteret * txinteret * txinteret * txinteret);
    }
}*/
