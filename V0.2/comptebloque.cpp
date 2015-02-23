#include "comptebloque.h"
#include <ctime>

// variable static
int CompteBloque::dureeblocage = 48;
// constructeur
CompteBloque::CompteBloque(double tx, int dureeouverture)
{
    txinteret = tx;
    this->dureeouverture = dureeouverture;
}

void CompteBloque::Afficher()
{
    cout << "Taux interet: " << setprecision(1) << txinteret << endl;
    Compte::Afficher();
}

void CompteBloque::TempsRestant(const int *today)
{

	int date_compte[3];
	int resJ, resM, resA; // vont stocker respectivement une différence entre 2 dates en Jours, Mois et Années
	int resDiff; // resultat de la fonction Compte::TempsRestant (1, 2 ou 3)

	date_compte[0] = Compte::getjour();
	date_compte[1] = Compte::getmois();
	date_compte[2] = Compte::getannee() + 4; // 4 ans de blocage dans le cas du CompteBloque

	// conversion des secondes en duree
	resDiff = Compte::CalculIntervalle(today, date_compte, resJ, resM, resA);

	// d abord la plus petite valeur: moins d un jour
    if(resDiff == 1)
    {
        cout << "Il reste moins d un jour" << endl;
    }
    else if(resDiff == 2) // il reste moins d un an, donc mois et jours:
    {
        cout << "Il reste: " << resM << " mois et " << resJ << " jours avant le debloquage." << endl;
    }
    else // il reste au moins un an, donc an, mois et jours
    {
        cout << "Il reste: " << resA << " annees, " << resM << " mois et " << resJ << " jours avant le debloquage." << endl;
    }
}

void CompteBloque::CalculInterets(const int *today)
{
    int anneecreation, anneeactuel;
    anneecreation = Compte::getannee();
    anneeactuel =  today[2];

    if((anneeactuel +1) > anneecreation && (anneeactuel + 1) < (anneecreation +2))
    {
        this->solde = this->solde * txinteret;
    }
    else if((anneeactuel +2) > (anneecreation +1) && (anneeactuel +2) < (anneecreation +3))
    {
        this->solde = this->solde * (txinteret * txinteret);
    }
    else if((anneeactuel +3) > (anneecreation + 2) && (anneeactuel + 3) < (anneecreation + 4))
    {
        this->solde = this->solde * (txinteret * txinteret * txinteret);
    }
    else
    {
        this->solde = this->solde * (txinteret * txinteret * txinteret * txinteret);
    }
}

void CompteBloque::TempsOuvert(const int *today)
{
    int j, m, a, ja, ma, aa; // j, m, a sont les variables de la date actuelle, ja, ma, aa de la date de creation du compte
    double diff; // detient la difference en secondes des deux dates
    // on va chercher les dates actuelles
    j = today[0];
    m = today[1];
    a = today[2];

    // on va chercher les dates de creation du compte
    ja = Compte::getjour();
    ma = Compte::getmois();
    aa = Compte::getannee();

    // creation de la date de creation du compte
    time_t ltime;
    tm *timecreation;

    ltime = time(NULL);
    timecreation = localtime(&ltime);

    timecreation->tm_year =  aa -1900;
    timecreation->tm_mon =  ma -1;
    timecreation->tm_mday = ja;
    timecreation->tm_hour = 0;
    timecreation->tm_min = 0;
    timecreation->tm_sec = 0;

    ltime = mktime(timecreation);

    // creation de la date de actuelle
    time_t rtime;
    tm *timeactuel;

    rtime = time(NULL);
    timeactuel = localtime(&rtime);

    timeactuel->tm_year = a -1900;
    timeactuel->tm_mon = m - 1;
    timeactuel->tm_mday = j;
    timeactuel->tm_hour = 0;
    timeactuel->tm_min = 0;
    timeactuel->tm_sec = 0;

    rtime = mktime(timeactuel);

    // difference des deux dates
   diff = difftime(ltime, rtime);

   // conversion des secondes en duree
   // d abord la plus petite valeur: moins d un jour
    if(diff < 86400)
    {
        cout << "Le compte est ouvert depuis moins d un jour." << endl;
    }
    else if(diff < 2419200) // il reste moins d un an, donc mois et jours:
    {
        int months = (int) diff/108000;
        int restemonths = (int) diff % 108000;
        int days = (int) restemonths / 3600;
        // int restedays = (int) diff%86400;
        cout << "Le compte est ouvert depuis " << months << " mois et " << days << " jours." << endl;
    }
    else // il reste au moins un an, donc an, mois et jours
    {
        int years = (int) diff/31536000;
        int resteyears = (int)diff%31536000;
        int months = (int) resteyears / 2635200;
        int restemonths = (int) resteyears % 2635200;
        int days = (int) restemonths/86400;
        cout << "Le compte est ouvert depuis: " << years << " annees, " << months << " mois et " << days << " jours." << endl;
    }
}