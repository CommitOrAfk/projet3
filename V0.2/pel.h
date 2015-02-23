#include "compte.h"

#ifndef PEL_H
#define PEL_H

#define PEL_TAUX_REMU        2.0
#define PEL_TAUX_EMPRUNT     3.2
#define PEL_PLAFOND          61200.0  
#define PEL_DUREE_VERSEMENTS 4
#define PEL_DUREE_RETRAITS   3

class Pel: public Compte
{
private:
	double tauxRemu;
	double tauxEmprunt;
	double montantMensuel;
	double montantTotal;
	double interetsAcquis;
	int anneeDebutRetrait;
	int anneeCloture;
	void CalculerInterets();
public:
	Pel(double tauxEmprunt = PEL_TAUX_EMPRUNT, double tauxRemu = PEL_TAUX_REMU, double montantMensuel = 45.0, int id = 1, int solde = 0);
	Pel(Pel &P);
	~Pel() {};
	void Afficher();
	void Saisir(istream &in);
	double Consulter();
	void TempsRestantAvantEmprunt(const int *today);
	int Deposer(const int *today, double montant);
	int Retirer(const int *today, double montant);
	void AvancerAnnees(const int *date);
	void CalculerEmprunt(const int *today);
};

istream& operator>>(istream &in, Pel &P);

#endif
