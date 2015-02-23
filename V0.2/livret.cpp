#include "livret.h"


Livret::Livret(): Compte(id, solde)
{
    this->taux_remuneration = 0.0125;
    this->plafond = 22000;
    this->isOpen=true;
}


Livret::~Livret()
{
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

void Livret::Afficher() const
{
    cout<<"*** Livret Epargne ***\n";
    Compte::Afficher();
    cout<<"Taux de rémunération: "<< setprecision(2) <<this->taux_remuneration<<endl;
    cout<<"Le plafond: "<< setprecision(2) <<this->plafond<<endl;
}

void Livret::Saisir()
{
    this->id = (int)(this);
    if(this->id < 0)
    {
        id = id*-1;
    }
    this->taux_remuneration = 0.0125;
    this->plafond = 22000;
    this->isOpen=true;

}

void Livret::Cloturer()
{
    //Appel de la fonction dans compte, pas de surcharge
}

double Livret::Consulter()
{
    return this->solde;
}

void Livret::EstOuvert()
{
    //Appel de la fonction dans compte, pas de surcharge
}


