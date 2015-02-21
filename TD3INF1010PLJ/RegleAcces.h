/********************************************************
Fichier: RegleAcces.h
Auteurs: Pierre-Luc Jetté && Claire Quesnel && 
Chargés de TP d'INF1010
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Définition de la classe RegleAcces
********************************************************/

#ifndef REGLES_ACCES_H
#define	REGLES_ACCES_H

#include <string>

using namespace std;

const string PERIODE_ACCES_MATIN = "Matin";
const string PERIODE_ACCES_SOIR = "Soir";
const string PERIODE_ACCES_NUIT = "Nuit";


using namespace std;

class RegleAcces
{
public:
	//Constructeurs
	RegleAcces();
	RegleAcces(const unsigned int& niveau, const string& local, const string& periode); //CHANGÉ: Ajouté const devant unsigned int niveau

	//Accesseurs
	string			getLocal()				const;
	unsigned int	getNiveauAccesRequis()	const;
	string			getPeriode()			const;

	//Surcharge de l'opérateur ==. Retour true si les deux règles comparées sont les mêmes.
	bool operator==(const RegleAcces& regle) const;

private:
	string			local_;
	unsigned int	niveauAccesRequis_;
	string			periode_;
};

#endif