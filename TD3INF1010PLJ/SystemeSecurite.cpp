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

}

void SystemeSecurite::imprimerJournal() const{
	for (unsigned int i = 0; i < journalAcces_.size(); i++){
		cout << "Entree #" << i << endl << "Nom, Prenom: " << journalAcces_[i].lambda->getNom() << ", " << journalAcces_[i].lambda->getPrenom() << endl << "Classe: " << journalAcces_[i].lambda->getClasseEmploye << endl << "Local: " << journalAcces_[i].local << endl << "Periode: <Matin, Soir ou Nuit> " << journalAcces_[i].periode << endl << "Acces: <Accorde ou Refuse> " << journalAcces_[i].acces << "\n\n";
	}
}