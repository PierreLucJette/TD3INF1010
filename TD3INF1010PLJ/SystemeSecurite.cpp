/********************************************************
Fichier: SystemeSecurite.cpp
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Implémentation de la classe SystemeSecurite
********************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "SystemeSecurite.h"
#include "RegleAcces.h"
#include "AgentSecurite.h"
#include "Professeur.h"
#include "Etudiant.h"

using namespace std;

SystemeSecurite::SystemeSecurite()
{}

//Toutes les surcharges d'accederLocal vérifient si l'individu a accès au local à cette période. 
//Cela se fait en comparant les paramètres de la fonction aux règles dans le vecteur regles_. Retourne true si accès accordé.
bool SystemeSecurite::accederLocal(const AgentSecurite& agent, const string& local, const string& periode)
{
	bool estAutorise = false;
	Journal temporaire;
	for (unsigned int i = 0; i < regles_.size(); i++){ //On passe au travers du vecteur de règles pour trouver celle qui corresponds aux paramètres de la fonction.
		if ((local == regles_[i].getLocal()) &&
			(periode == regles_[i].getPeriode()) &&
			(agent.getNiveauAcces() >= regles_[i].getNiveauAccesRequis()))
				estAutorise = true; //Si la règle est trouvée et que l'Employé a le niveau d'accès requis, on l'autorise à entrer.
	}

	temporaire.nom = agent.getNom();
	temporaire.prenom = agent.getPrenom();
	temporaire.classeEmploye = agent.getClasseEmploye();
	temporaire.local = local;
	temporaire.periode = periode;

	if (estAutorise)
		temporaire.acces = "Autorise";

	else
		temporaire.acces = "Refuse";

	journalAcces_.push_back(temporaire); //Écriture dans le journal des informations sur la tentative d'accès

	return estAutorise; //On retourne true si l'accès est accordé
}

//Toutes les surcharges d'accederLocal vérifient si l'individu a accès au local à cette période. 
//Cela se fait en comparant les paramètres de la fonction aux règles dans le vecteur regles_. Retourne true si accès accordé.
bool SystemeSecurite::accederLocal(const Professeur& prof, const string& local, const string& periode)
{
	bool estAutorise = false;
	Journal temporaire;
	for (unsigned int i = 0; i < regles_.size(); i++){//On passe au travers du vecteur de règles pour trouver celle qui corresponds aux paramètres de la fonction.
		if ((local == regles_[i].getLocal()) &&
			(periode == regles_[i].getPeriode()) &&
			(prof.getNiveauAcces() >= regles_[i].getNiveauAccesRequis()))
			estAutorise = true; //Si la règle est trouvée et que l'Employé a le niveau d'accès requis, on l'autorise à entrer.
	}

	temporaire.nom = prof.getNom();
	temporaire.prenom = prof.getPrenom();
	temporaire.classeEmploye = prof.getClasseEmploye();
	temporaire.local = local;
	temporaire.periode = periode;

	if (estAutorise)
		temporaire.acces = "Autorise";

	else
		temporaire.acces = "Refuse";

	journalAcces_.push_back(temporaire); //Écriture dans le journal des informations sur la tentative d'accès

	return estAutorise;//On retourne true si l'accès est accordé
}

bool SystemeSecurite::accederLocal(const Etudiant& etudiant, const string& local, const string& periode){//Toutes les surcharges d'accederLocal vérifient si l'individu a accès au local à cette période. Cela se fait en comparant les paramètres de la fonction aux règles dans le vecteur regles_. Retourne true si accès accordé.
	bool estAutorise = false;
	Journal temporaire;
	for (unsigned int i = 0; i < regles_.size(); i++){//On passe au travers du vecteur de règles pour trouver celle qui corresponds aux paramètres de la fonction.
		if ((local == regles_[i].getLocal()) &&
			(periode == regles_[i].getPeriode()) &&
			(etudiant.getNiveauAcces() >= regles_[i].getNiveauAccesRequis()))
			estAutorise = true;//Si la règle est trouvée et que l'Employé a le niveau d'accès requis, on l'autorise à entrer.
	}

	temporaire.nom = etudiant.getNom();
	temporaire.prenom = etudiant.getPrenom();
	temporaire.classeEmploye = etudiant.getClasseEmploye();
	temporaire.local = local;
	temporaire.periode = periode;

	if (estAutorise)
		temporaire.acces = "Autorise";

	else
		temporaire.acces = "Refuse";

	journalAcces_.push_back(temporaire);//Écriture dans le journal des informations sur la tentative d'accès

	return estAutorise;//On retourne true si l'accès est accordé
}

bool SystemeSecurite::accederLocal(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode){//Toutes les surcharges d'accederLocal vérifient si l'individu a accès au local à cette période. Cela se fait en comparant les paramètres de la fonction aux règles dans le vecteur regles_. Retourne true si accès accordé.
	bool estAutorise = false;
	Journal temporaire;
	for (unsigned int i = 0; i < regles_.size(); i++){//On passe au travers du vecteur de règles pour trouver celle qui corresponds aux paramètres de la fonction.
		if (local == regles_[i].getLocal() &&
			periode == regles_[i].getPeriode()&&
			niveauAcces >= regles_[i].getNiveauAccesRequis())
				estAutorise = true;//Si la règle est trouvée et que l'Employé a le niveau d'accès requis, on l'autorise à entrer.	
	}

	temporaire.nom = nom;
	temporaire.prenom = prenom;
	temporaire.classeEmploye = fonction;
	temporaire.local = local;
	temporaire.periode = periode;

	if (estAutorise)
		temporaire.acces = "Autorise";

	else
		temporaire.acces = "Refuse";

	journalAcces_.push_back(temporaire);//Écriture dans le journal des informations sur la tentative d'accès
	return estAutorise;//On retourne true si l'accès est accordé
}

//Ajoute une regle au vecteur regles_ si elle n'y est pas deja présente et retourne si elle a bien ete ajoutee.
bool SystemeSecurite::ajouterRegle(const RegleAcces& regle)
{
	bool estDejaPrésente = false;
	for (unsigned int i = 0; i < regles_.size(); i++){ //On parcoure le vecteur regles_ et si l'on trouve la regle on change estDejaPrésente à vrai
		if (regle == regles_[i])
			estDejaPrésente = true;
	}

	if (!estDejaPrésente) //Si la règle n'est pas dans le vector, on l'ajoute au vector.
		regles_.push_back(regle);

	return !estDejaPrésente; //Retourne true si la règle d'était pas présente et as donc bien ete ajoutée.
}

//Parcoure le vecteur journalAcces_ et affiche les strings d'information à l'écran.
void SystemeSecurite::imprimerJournal() const{ 
	for (unsigned int i = 0; i < journalAcces_.size(); i++){
		cout << "====================================\n\n" << "Entree #" << i + 1 << endl << "Nom, Prenom: " << journalAcces_[i].nom << ", " << journalAcces_[i].prenom << endl << "Classe: " << journalAcces_[i].classeEmploye << endl << "Local: " << journalAcces_[i].local << endl << "Periode: <Matin, Soir ou Nuit> " << journalAcces_[i].periode << endl << "Acces: <Accorde ou Refuse> " << journalAcces_[i].acces << "\n\n";
	}
}