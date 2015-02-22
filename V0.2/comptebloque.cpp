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

    int j, m, a, ja, ma, aa;
    double diff;
    j = today[0];
    m = today[1];
    a = today[2];

    ja = Compte::getjour();
    ma = Compte::getmois();
    aa = Compte::getannee()  +4;  // 4 ans bloquee

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

   diff = difftime(ltime, rtime);

    if(diff < 86400)
    {
        cout << "Il reste moins d un jour" << endl;
    }
    else if(diff < 2419200)
    {
        int months = (int) diff/108000;
        int restemonths = (int) diff % 108000;
        int days = (int) restemonths / 3600;
        int restedays = (int) diff%86400;
        cout << "Il reste: " << months << " mois et " << days << " jours avant le debloquage." << endl;
    }
    else
    {
        int years = (int) diff/31536000;
        int resteyears = (int)diff%31536000;
        int months = (int) resteyears / 2635200;
        int restemonths = (int) resteyears % 2635200;
        int days = (int) restemonths/86400;
        cout << "Il reste: " << years << " annees, " << months << " mois et " << days << " jours avant le debloquage." << endl;
    }
}
