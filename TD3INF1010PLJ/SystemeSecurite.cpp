/********************************************************
Fichier: SystemeSecurite.cpp
Auteurs: Pierre-Luc Jett� && Claire Quesnel
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: Impl�mentation de la classe SystemeSecurite
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

//Toutes les surcharges d'accederLocal v�rifient si l'individu a acc�s au local � cette p�riode. 
//Cela se fait en comparant les param�tres de la fonction aux r�gles dans le vecteur regles_. Retourne true si acc�s accord�.
bool SystemeSecurite::accederLocal(const AgentSecurite& agent, const string& local, const string& periode)
{
	bool estAutorise = false;
	Journal temporaire;
	for (unsigned int i = 0; i < regles_.size(); i++){ //On passe au travers du vecteur de r�gles pour trouver celle qui corresponds aux param�tres de la fonction.
		if ((local == regles_[i].getLocal()) &&
			(periode == regles_[i].getPeriode()) &&
			(agent.getNiveauAcces() >= regles_[i].getNiveauAccesRequis()))
				estAutorise = true; //Si la r�gle est trouv�e et que l'Employ� a le niveau d'acc�s requis, on l'autorise � entrer.
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

	journalAcces_.push_back(temporaire); //�criture dans le journal des informations sur la tentative d'acc�s

	return estAutorise; //On retourne true si l'acc�s est accord�
}

//Toutes les surcharges d'accederLocal v�rifient si l'individu a acc�s au local � cette p�riode. 
//Cela se fait en comparant les param�tres de la fonction aux r�gles dans le vecteur regles_. Retourne true si acc�s accord�.
bool SystemeSecurite::accederLocal(const Professeur& prof, const string& local, const string& periode)
{
	bool estAutorise = false;
	Journal temporaire;
	for (unsigned int i = 0; i < regles_.size(); i++){//On passe au travers du vecteur de r�gles pour trouver celle qui corresponds aux param�tres de la fonction.
		if ((local == regles_[i].getLocal()) &&
			(periode == regles_[i].getPeriode()) &&
			(prof.getNiveauAcces() >= regles_[i].getNiveauAccesRequis()))
			estAutorise = true; //Si la r�gle est trouv�e et que l'Employ� a le niveau d'acc�s requis, on l'autorise � entrer.
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

	journalAcces_.push_back(temporaire); //�criture dans le journal des informations sur la tentative d'acc�s

	return estAutorise;//On retourne true si l'acc�s est accord�
}

bool SystemeSecurite::accederLocal(const Etudiant& etudiant, const string& local, const string& periode){//Toutes les surcharges d'accederLocal v�rifient si l'individu a acc�s au local � cette p�riode. Cela se fait en comparant les param�tres de la fonction aux r�gles dans le vecteur regles_. Retourne true si acc�s accord�.
	bool estAutorise = false;
	Journal temporaire;
	for (unsigned int i = 0; i < regles_.size(); i++){//On passe au travers du vecteur de r�gles pour trouver celle qui corresponds aux param�tres de la fonction.
		if ((local == regles_[i].getLocal()) &&
			(periode == regles_[i].getPeriode()) &&
			(etudiant.getNiveauAcces() >= regles_[i].getNiveauAccesRequis()))
			estAutorise = true;//Si la r�gle est trouv�e et que l'Employ� a le niveau d'acc�s requis, on l'autorise � entrer.
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

	journalAcces_.push_back(temporaire);//�criture dans le journal des informations sur la tentative d'acc�s

	return estAutorise;//On retourne true si l'acc�s est accord�
}

bool SystemeSecurite::accederLocal(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode){//Toutes les surcharges d'accederLocal v�rifient si l'individu a acc�s au local � cette p�riode. Cela se fait en comparant les param�tres de la fonction aux r�gles dans le vecteur regles_. Retourne true si acc�s accord�.
	bool estAutorise = false;
	Journal temporaire;
	for (unsigned int i = 0; i < regles_.size(); i++){//On passe au travers du vecteur de r�gles pour trouver celle qui corresponds aux param�tres de la fonction.
		if (local == regles_[i].getLocal() &&
			periode == regles_[i].getPeriode()&&
			niveauAcces >= regles_[i].getNiveauAccesRequis())
				estAutorise = true;//Si la r�gle est trouv�e et que l'Employ� a le niveau d'acc�s requis, on l'autorise � entrer.	
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

	journalAcces_.push_back(temporaire);//�criture dans le journal des informations sur la tentative d'acc�s
	return estAutorise;//On retourne true si l'acc�s est accord�
}

//Ajoute une regle au vecteur regles_ si elle n'y est pas deja pr�sente et retourne si elle a bien ete ajoutee.
bool SystemeSecurite::ajouterRegle(const RegleAcces& regle)
{
	bool estDejaPr�sente = false;
	for (unsigned int i = 0; i < regles_.size(); i++){ //On parcoure le vecteur regles_ et si l'on trouve la regle on change estDejaPr�sente � vrai
		if (regle == regles_[i])
			estDejaPr�sente = true;
	}

	if (!estDejaPr�sente) //Si la r�gle n'est pas dans le vector, on l'ajoute au vector.
		regles_.push_back(regle);

	return !estDejaPr�sente; //Retourne true si la r�gle d'�tait pas pr�sente et as donc bien ete ajout�e.
}

//Parcoure le vecteur journalAcces_ et affiche les strings d'information � l'�cran.
void SystemeSecurite::imprimerJournal() const{ 
	for (unsigned int i = 0; i < journalAcces_.size(); i++){
		cout << "====================================\n\n" << "Entree #" << i + 1 << endl << "Nom, Prenom: " << journalAcces_[i].nom << ", " << journalAcces_[i].prenom << endl << "Classe: " << journalAcces_[i].classeEmploye << endl << "Local: " << journalAcces_[i].local << endl << "Periode: <Matin, Soir ou Nuit> " << journalAcces_[i].periode << endl << "Acces: <Accorde ou Refuse> " << journalAcces_[i].acces << "\n\n";
	}
}