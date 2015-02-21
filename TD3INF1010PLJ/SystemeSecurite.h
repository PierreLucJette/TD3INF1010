/********************************************************
Fichier: SystemeSecurite.h
Auteurs: Pierre-Luc Jetté && Claire Quesnel &&
Chargés de TP d'INF1010
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Définition de la classe SystemeSecurite
********************************************************/

#ifndef	SYSTEME_SECURITE_H
#define SYSTEME_SECURITE_H

#include "RegleAcces.h"
#include "AgentSecurite.h"
#include "Professeur.h"
#include "Etudiant.h"
#include "Employe.h"
#include <vector>
#include <string>

using namespace std;

struct Journal{
	string nom = "";
	string prenom = "";
	string classeEmploye = "";
	string local = "";
	string periode = "";
	string acces = "";
	/*
		Nous justifions l'utilisation d'une structure Journal par rapport à streamstring par les faits que
		l'utilisation d'une structure est plus intuitive tant à l'écriture qu'à la lecture du code et que 
		la structure utilise plus efficacement les ressources du système qu'un streamstring.
	*/
};

class SystemeSecurite
{
public:
	//Constructeur
	SystemeSecurite();

	//Toutes les surcharges d'accederLocal vérifient si l'individu a accès au local à cette période. Cela se fait en comparant les paramètres de la fonction aux règles dans le vecteur regles_. Retourne true si accès accordé. 
	bool accederLocal(const AgentSecurite& agent,	const string& local, const string& periode);
	bool accederLocal(const Professeur& prof,		const string& local, const string& periode);
	bool accederLocal(const Etudiant& etudiant,		const string& local, const string& periode);
	bool accederLocal(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode);

	//Mutateur. Ajoute une regle au vecteur regles_ si pas déjà présent
	bool ajouterRegle(const RegleAcces& regle);

	//Affiche le journal d'accès
	void imprimerJournal() const;

private:
	vector<RegleAcces>		regles_;
	vector<Journal>			journalAcces_; //Changé vector<string> à vector<Journal>. Voir justification sous la définition de la structure, plus haut, Line 30.
};

#endif