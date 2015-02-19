#include "compte.h"

/*Compte::Compte()
{

}*/

//Compte::Compte(int id, double solde):DateOuverture(j, m, a), ClientCompte(id, code, nom, prenom, adresse)
Compte::Compte(int id, double solde):DateOuverture(1,1,1970), ClientCompte(1111,0000,"nom","prenom", "adresse")
{
	this->id =id;
	this->id = (int)(this);
	if(this->id < 0)
	{
		this->id = this->id * -1;
	}

	cout<<"Saisir le solde du compte: ";
	cin>>solde;

	this->solde =solde;
	isOpen      = true;
}

Compte::~Compte()
{
	cout<<"Destructeur du compte"<<endl;
}

void Compte::ChangerCoordonnes()
{
	if (isOpen)
	{
		string poubelle;
		cout<<"Changer vos coordonnées"<<endl;
		cout <<"Entrer une nouvelle adresse : ";
		getline(cin, poubelle);
		getline(cin,ClientCompte.adresse);	
	}
	else
	{
		cout << "Ce compte est cloturé, impossible de faire une quelconque action." << endl;
	}
}

double Compte::Consulter()
{
	return solde;
}

void Compte::Cloturer()
{
	isOpen = false;
	solde  = 0.0;
	cout<<"Cloture du compte.\n";
}

void Compte::Afficher()
{
	if (isOpen)
	{
		cout<<"Identifiant du compte: "<<this->id<<endl;
		cout<<"Solde :"<<this->solde<<endl;
		ClientCompte.Afficher(cout);
		DateOuverture.Afficher(cout);
	}
	else
	{
		cout << "Ce compte est cloturé, impossible de faire une quelconque action." << endl;	
	}
}

bool Compte::EstOuvert()
{
	return isOpen;
}
