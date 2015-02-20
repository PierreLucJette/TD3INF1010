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
				if (agent.getNiveauAcces >= regles_[i].getNiveauAccesRequis())
					autorise = true;
			}
		}
	}
	//TODO: Continue Here
	journalAcces_.push_back(temporaire);
}

void SystemeSecurite::imprimerJournal() const{
	for (unsigned int i = 0; i < journalAcces_.size(); i++){
		cout << "Entree #" << i << endl << "Nom, Prenom: " << journalAcces_[i].nom << ", " << journalAcces_[i].prenom << endl << "Classe: " << journalAcces_[i].classeEmploye << endl << "Local: " << journalAcces_[i].local << endl << "Periode: <Matin, Soir ou Nuit> " << journalAcces_[i].periode << endl << "Acces: <Accorde ou Refuse> " << journalAcces_[i].acces << "\n\n";
	}
}