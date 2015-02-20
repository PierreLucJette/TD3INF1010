#include <iostream>
#include <string>
#include <vector>
#include "SystemeSecurite.h"
#include "RegleAcces.h"
#include "AgentSecurite.h"
#include "Professeur.h"
#include "Etudiant.h"

using namespace std;

SystemeSecurite::SystemeSecurite(){}

bool SystemeSecurite::accederLocal(const AgentSecurite& agent, const string& local, const string& periode){
	bool autorise = false;
	Journal temporaire;
	for (unsigned int i = 0; i < regles_.size(); i++){
		if (local == regles_[i].getLocal()){
			if (periode == regles_[i].getPeriode()){
				if (agent.getNiveauAcces() >= regles_[i].getNiveauAccesRequis())
					autorise = true;
			}
		}
	}

	temporaire.nom = agent.getNom();
	temporaire.prenom = agent.getPrenom();
	temporaire.classeEmploye = agent.getClasseEmploye();
	temporaire.local = local;
	temporaire.periode = periode;
	if (autorise)
		temporaire.acces = "Autorise";
	else
		temporaire.acces = "Refuse";
	journalAcces_.push_back(temporaire);
	return autorise;
}

bool SystemeSecurite::accederLocal(const Professeur& prof, const string& local, const string& periode){
	bool autorise = false;
	Journal temporaire;
	for (unsigned int i = 0; i < regles_.size(); i++){
		if (local == regles_[i].getLocal()){
			if (periode == regles_[i].getPeriode()){
				if (prof.getNiveauAcces() >= regles_[i].getNiveauAccesRequis())
					autorise = true;
			}
		}
	}
	temporaire.nom = prof.getNom();
	temporaire.prenom = prof.getPrenom();
	temporaire.classeEmploye = prof.getClasseEmploye();
	temporaire.local = local;
	temporaire.periode = periode;
	if (autorise)
		temporaire.acces = "Autorise";
	else
		temporaire.acces = "Refuse";
	journalAcces_.push_back(temporaire);
	return autorise;
}

bool SystemeSecurite::accederLocal(const Etudiant& etudiant, const string& local, const string& periode){
	bool autorise = false;
	Journal temporaire;
	for (unsigned int i = 0; i < regles_.size(); i++){
		if (local == regles_[i].getLocal()){
			if (periode == regles_[i].getPeriode()){
				if (etudiant.getNiveauAcces() >= regles_[i].getNiveauAccesRequis())
					autorise = true;
			}
		}
	}
	temporaire.nom = etudiant.getNom();
	temporaire.prenom = etudiant.getPrenom();
	temporaire.classeEmploye = etudiant.getClasseEmploye();
	temporaire.local = local;
	temporaire.periode = periode;
	if (autorise)
		temporaire.acces = "Autorise";
	else
		temporaire.acces = "Refuse";
	journalAcces_.push_back(temporaire);
	return autorise;
}

bool SystemeSecurite::accederLocal(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode){
	bool autorise = false;
	Journal temporaire;
	for (unsigned int i = 0; i < regles_.size(); i++){
		if (local == regles_[i].getLocal()){
			if (periode == regles_[i].getPeriode()){
				if (niveauAcces >= regles_[i].getNiveauAccesRequis())
					autorise = true;
			}
		}
	}
	temporaire.nom = nom;
	temporaire.prenom = prenom;
	temporaire.classeEmploye = fonction;
	temporaire.local = local;
	temporaire.periode = periode;
	if (autorise)
		temporaire.acces = "Autorise";
	else
		temporaire.acces = "Refuse";
	journalAcces_.push_back(temporaire);
	return autorise;
}

bool SystemeSecurite::ajouterRegle(const RegleAcces& regle){
	bool dejaLa = false;
	if (regles_.size() >= 0){
		for (int i = 0; i < regles_.size(); i++){
			if (regle == regles_[i])
				dejaLa = true;
		}
	}
	if (!dejaLa)
		regles_.push_back(regle);
	return dejaLa;
}

void SystemeSecurite::imprimerJournal() const{
	for (unsigned int i = 0; i < journalAcces_.size(); i++){
		cout << "Entree #" << i + 1 << endl << "Nom, Prenom: " << journalAcces_[i].nom << ", " << journalAcces_[i].prenom << endl << "Classe: " << journalAcces_[i].classeEmploye << endl << "Local: " << journalAcces_[i].local << endl << "Periode: <Matin, Soir ou Nuit> " << journalAcces_[i].periode << endl << "Acces: <Accorde ou Refuse> " << journalAcces_[i].acces << "\n\n";
	}
}