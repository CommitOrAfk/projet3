#include "pel.h"

Pel::Pel(double tauxEmprunt, double tauxRemu, double montantMensuel, int id, int solde): Compte(id, solde)//, Compte::Date(int jour, int mois, int annee), Compte::Client(int id, int code, string nom, string prenom, string adresse)
{
	this->tauxRemu       = 0;
	this->tauxRemu       = tauxRemu;
	this->tauxEmprunt    = 0;
	this->tauxEmprunt    = tauxEmprunt;
	this->montantMensuel = 0;
	this->montantMensuel = montantMensuel;
	this->isOpen         = true;
	this->interetsAcquis = 0.0;
}

/*Pel::Pel(Pel &P): Compte(P)
{
	tauxRemu       = P.tauxRemu;
	tauxEmprunt    = P.tauxEmprunt;
	montantMensuel = P.montantMensuel;
	montantTotal   = P.montantTotal;
	interetsAcquis = P.interetsAcquis;
	isOpen         = P.isOpen;
}*/

void Pel::Afficher() const
{
	if (isOpen)
	{	
		cout<<"*** PEL ***\n";
		Compte::Afficher();
		cout << "Taux de rémunération: " << tauxRemu << " %." << endl;
		cout << "Taux d'emprunt (après 4ans): " << tauxEmprunt << " %." << endl;
		cout << "Montant du versement mensuel: " << montantMensuel << " €." << endl;
	}
	else
	{
		cout << "Ce compte est fermé, impossible d'y accéder." << endl;
	}
}

double Pel::Consulter()
{
	if (isOpen)
	{
		return solde;
	}
	else
	{
		cout << "Ce compte est fermé, impossible d'y accéder." << endl;
	}
	return -1.0;
}

void Pel::Saisir(istream &in)
{
	double saisieMontant; // va être saisie
	double saisieMensuel; // idem, pour le montant mensuel

	if (solde < 225)
	{
		cout << "Dans le cas du PEL, le premier virement doit être supérieur ou égal à 225€." << endl;
		cout << "Or il est actuellement à " << solde << " €." << endl;
		// saisie d'un premier virement valide
		do
		{
			cout << "Saisissez le montant du premier virement." << endl;
			in >> saisieMontant;

			if (saisieMontant < 225)
				cout << "Le montant du premier virement doit être supérieur ou égal à 225€." << endl;
			else
				solde = saisieMontant;

		}
		while(saisieMontant < 225);
	}

	do
	{
		cout << "Saisisse le montant du versement mensuel (doit être supérieur ou égal à 45€):" << endl;
		in >> saisieMensuel;

			if (saisieMensuel < 45)
				cout << "Vous devez verser un minimum de 45€ par mois sur votre PEL." << endl;
			else
				montantMensuel = saisieMensuel;
	}
	while(saisieMensuel < 45);

	anneeDebutRetrait = Compte::getannee() + PEL_DUREE_VERSEMENTS;
	anneeCloture      = Compte::getannee() + PEL_DUREE_VERSEMENTS + PEL_DUREE_RETRAITS;
}

int Pel::Deposer(const int *today, double montant)
{
	int date_compte[3];
	int resJ, resM, resA; // vont stocker respectivement une différence entre 2 dates en Jours, Mois et Années
	// première vérif obligatoire
	if (isOpen)
	{
		//deuxième vérif nécéssaire
		if ((solde + montant) > PEL_PLAFOND)
		{
			cout << "Impossible de verser le montant " << montant << " car le plafond est à " << PEL_PLAFOND << '.' << endl;
			return -2;
		}

		date_compte[0] = Compte::getjour();
		date_compte[1] = Compte::getmois();
		date_compte[2] = Compte::getannee() + PEL_DUREE_VERSEMENTS; // 4 ans de blocage dans le cas du PEL

		// conversion des secondes en duree
		Compte::CalculIntervalle(today, date_compte, resJ, resM, resA);
		//si il reste au moins un jour, un moins ou une année avant la fin de la période de dépôt
		if (resJ > 0 || resJ > 0 || resA > 0)
		{
			solde += montant;
			cout << "Versement accepté. Votre nouveau solde est: " << solde << " €." << endl;
			return 0;
		}
		// sinon on est dans la période de retrait
		else
		{
			cout << "Versement refusé, la période de dépôt est terminée." << endl;
			return -3;
		}
	}
	else
	{
		cout << "Ce compte est fermé, impossible d'y accéder." << endl;
	}
	return -1.0; // si on arrive là le compte est fermé
}

int Pel::Retirer(const int *today, double montant)
{
	int date_compte[3];
	int resJ, resM, resA; // vont stocker respectivement une différence entre 2 dates en Jours, Mois et Années
	// première vérif obligatoire
	if (isOpen)
	{
		date_compte[0] = Compte::getjour();
		date_compte[1] = Compte::getmois();
		date_compte[2] = Compte::getannee() + PEL_DUREE_VERSEMENTS; // 4 ans de blocage dans le cas du PEL

		// conversion des secondes en duree
		Compte::CalculIntervalle(today, date_compte, resJ, resM, resA);
		//si il plus de temps on peut retirer
		if (resJ == 0  && resJ == 0 && resA == 0)
		{
			solde -= montant;
			cout << "Retrait accepté. Votre nouveau solde est: " << solde << " €." << endl;
			return 0;
		}
		// sinon on est dans la période de retrait
		else
		{
			cout << "Versement refusé, la période de retrait n'a pas encore commencée." << endl;
			return -3;
		}
	}
	else
	{
		cout << "Ce compte est fermé, impossible d'y accéder." << endl;
	}
	return -1.0; // si on arrive là le compte est fermé
}

void Pel::AvancerAnnees(const int *date)
{
	// cloturer si nécéssaire
	int date_compte[3];
	int resJ, resM, resA; // vont stocker respectivement une différence entre 2 dates en Jours, Mois et Années
	int years, i; // nb d'années dont il faut calculer les intérêts
	static int lastYearInterets = 0; // va contenir l'année de la dernière fois qu'on a calculé les intérêts
	date_compte[0] = Compte::getjour();
	date_compte[1] = Compte::getmois();
	date_compte[2] = anneeCloture; // 4 ans de blocage dans le cas du PEL

	if (isOpen) {
		// conversion des secondes en duree
		Compte::CalculIntervalle(date, date_compte, resJ, resM, resA);
		//si il n'y a plus de temps on peut cloturer
		if (resJ == 0  && resJ == 0 && resA == 0)
		{
			Compte::Cloturer();
		}

		// si c'est la première fois qu'on calcule les intérêts
		if (lastYearInterets == 0)
			lastYearInterets = Compte::getannee();

		// si le compte a été cloturé, on ne prend les années avant l'année de cloture.
		if (!isOpen)
			years = anneeCloture - lastYearInterets;
		//si non on prend tout depuis la dernière fois qu'on a calculé les intérêts
		else
			years = date[2] - lastYearInterets;

		if (years > 0)
		{
			// on calcule les intérets
			for (i = 0; i < years; i++)
			{
				solde += montantMensuel * 12; // mise à jour du solde
				CalculerInterets();
			}
		}
		lastYearInterets = date[2];
	}
}

void Pel::TempsRestantAvantEmprunt(const int *today)
{
	int date_compte[3];
	int resJ, resM, resA; // vont stocker respectivement une différence entre 2 dates en Jours, Mois et Années
	int resDiff; // resultat de la fonction Compte::TempsRestant (1, 2 ou 3)
	// première vérif obligatoire
	if (isOpen)
	{
		date_compte[0] = Compte::getjour();
		date_compte[1] = Compte::getmois();
		date_compte[2] = Compte::getannee() + PEL_DUREE_VERSEMENTS; // 4 ans de période de dépôt

		// conversion des secondes en duree
		resDiff = Compte::CalculIntervalle(today, date_compte, resJ, resM, resA);

		// d abord la plus petite valeur: moins d un jour
		if(resDiff == 1)
		{
			cout << "Il reste moins d un jour avant que vous puissiez emprunter." << endl;
		}
		else if(resDiff == 2) // il reste moins d un an, donc mois et jours:
		{
			cout << "Il reste " << resM << " mois et " << resJ << " jours avant un possible emprunt." << endl;
		}
		else // il reste au moins un an, donc an, mois et jours
		{
			cout << "Il reste " << resA << " annees, " << resM << " mois et " << resJ << " jours avant un possible emprunt." << endl;
		}
	}
	else
	{
		cout << "Ce compte est fermé, impossible d'emprunter." << endl;
	}
}

void Pel::CalculerInterets()
{
	int interets = ((solde / 100) * tauxRemu);
	interetsAcquis += interets;
	solde += interets;
}

void Pel::CalculerEmprunt(const int *today)
{
	int date_compte[3];
	int resJ, resM, resA; // vont stocker respectivement une différence entre 2 dates en Jours, Mois et Années
	double emprunt, interetsEmprunt, empruntTotal;
	// première vérif obligatoire
	if (isOpen)
	{
		date_compte[0] = Compte::getjour();
		date_compte[1] = Compte::getmois();
		date_compte[2] = Compte::getannee() + PEL_DUREE_VERSEMENTS; // 4 ans de blocage dans le cas du PEL

		// conversion des secondes en duree
		Compte::CalculIntervalle(today, date_compte, resJ, resM, resA);
		//si il plus de temps on peut retirer
		if (resJ == 0  && resJ == 0 && resA == 0)
		{
			emprunt         = (solde * 5) - interetsAcquis; // n'est pas la vraie fonction de calcul d'un emprunt!
			interetsEmprunt = (emprunt/100) * tauxEmprunt;
			empruntTotal    = emprunt + interetsEmprunt;
			cout << "Vous pouvez emprunter " <<  emprunt << " € à un taux de " << tauxEmprunt << " %, pour un coût total de " << empruntTotal << " €." << endl;
		}
		// sinon on est dans la période de dépôt
		else
		{
			cout << "Calcul d'emprunt refusé, vous êtes toujours dans la période de dépôt." << endl;
		}
	}
	else
	{
		cout << "Ce compte est fermé, impossible de calculer un emprunt." << endl;
	}
}

istream& operator>>(istream &in, Pel &P)
{
	P.Saisir(in);
	return in;
}
