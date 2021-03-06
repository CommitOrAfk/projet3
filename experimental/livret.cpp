#include "livret.h"


Livret::Livret(): Compte(id, solde)
{
    this->taux_remuneration = 0.0125;
    this->plafond = 22000;
    this->isOpen=true;
}


Livret::~Livret()
{
    cout<<"Destructeur du livret"<<endl;
}

void Livret::Ajouter()
{
    cout <<"Entrer le montant à déposer dans le livret : ";
    double argent;
    cin>>argent;
    if(argent+solde<plafond)
    {
        solde=solde+argent;
    }
    else
    {
        cout<<"Montant Impossible ! "<<endl<<"Le montant est trop élevé par rapport au plafond"<<endl;
    }
}

double Livret::CalculInteret()
{
    // Calcul des intérêts sur l'année et non par mois
    // Pour calculer par mois, il faudrait qu'on sache à quel jour, mois et date que l'on ajoute de l'argent
    // Il faudrait aussi gérer le transfert d'argent entre le compte et le livret
    return (solde*taux_remuneration)/24*12;
}
