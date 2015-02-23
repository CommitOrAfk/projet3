#include "compte.h"

/*Compte::Compte()
{

}*/

//Compte::Compte(int id, double solde):DateOuverture(j, m, a), ClientCompte(id, code, nom, prenom, adresse)
Compte::Compte(int id, double solde):DateOuverture(1,1,1970)
{
	this->id =id;
	this->id = (int)(this);
	if(this->id < 0)
	{
		this->id = this->id * -1;
	}

	this->solde =0;
	this->solde = solde;
	isOpen      = true;
}

Compte::~Compte()
{
}

//A mettre dans client
/*void Compte::ChangerCoordonnes()
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
}*/

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

void Compte::Afficher() const
{
	if (isOpen)
	{
		cout<<"Identifiant du compte: "<<this->id<<endl;
		cout<<"Solde :"<< fixed << setprecision(2) << solde << endl;
		DateOuverture.Afficher(cout);
	}
	else
	{
		cout << "Ce compte est cloturé, impossible de faire une quelconque action." << endl;
	}
}


int Compte::CalculIntervalle(const int *today, const int *date, int &resJours, int &resMois, int &resAns)
{

    int j, m, a, ja, ma, aa; // j, m, a sont les variables de la date actuelle, ja, ma, aa de la date de creation du compte
    double diff; // detient la difference en secondes des deux dates
    // on va chercher les dates actuelles
	j  = today[0];
	m  = today[1];
	a  = today[2];

	// on va chercher les dates de creation du compte
	ja = date[0];
	ma = date[1];
	aa = date[2];  // 4 ans bloquee

    // creation de la date de creation du compte
    time_t ltime;
    tm *timecreation;

	ltime        = time(NULL);
	timecreation = localtime(&ltime);

	timecreation->tm_year =  aa -1900;
	timecreation->tm_mon  =  ma -1;
	timecreation->tm_mday = ja;
	timecreation->tm_hour = 0;
	timecreation->tm_min  = 0;
	timecreation->tm_sec  = 0;

    ltime = mktime(timecreation);

    // creation de la date de actuelle
    time_t rtime;
    tm *timeactuel;

	rtime      = time(NULL);
	timeactuel = localtime(&rtime);

	timeactuel->tm_year = a -1900;
	timeactuel->tm_mon  = m - 1;
	timeactuel->tm_mday = j;
	timeactuel->tm_hour = 0;
	timeactuel->tm_min  = 0;
	timeactuel->tm_sec  = 0;

    rtime = mktime(timeactuel);

	// difference des deux dates
	diff = difftime(ltime, rtime);

	// conversion des secondes en duree
	// d abord la plus petite valeur: moins d un jour
    if(diff < 86400)
    {
		resJours = 0;
		resMois  = 0;
		resAns   = 0;
        // cout << "Il reste moins d un jour" << endl;
        return 1;
    }
    else if(diff < 2419200) // il reste moins d un an, donc mois et jours:
    {
		resMois         = (int) diff / 108000;
		int restemonths = (int) diff % 108000;
		resJours        = (int) restemonths / 3600;
		// int restedays   = (int) diff%86400;
        // cout << "Il reste: " << months << " mois et " << days << " jours avant le debloquage." << endl;
        return 2;
    }
    else // il reste au moins un an, donc an, mois et jours
    {
		resAns          = (int) diff / 31536000;
		int resteyears  = (int) diff % 31536000;
		resMois         = (int) resteyears / 2635200;
		int restemonths = (int) resteyears % 2635200;
		resJours        = (int) restemonths / 86400;
        //cout << "Il reste: " << years << " annees, " << months << " mois et " << days << " jours avant le debloquage." << endl;
        return 3;
    }
    return 0;
}

bool Compte::EstOuvert()  const
{
	return isOpen;
}

 int Compte::getjour()
 {
    return DateOuverture.jour;
 }
int Compte::getmois()
{
    return DateOuverture.mois;
}
int Compte::getannee()
{
    return DateOuverture.annee;
}
