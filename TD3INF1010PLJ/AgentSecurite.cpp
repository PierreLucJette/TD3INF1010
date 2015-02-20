#include <iostream>
#include <string>
#include "AgentSecurite.h"

using namespace std;

AgentSecurite::AgentSecurite(const string& nom, const string& prenom): Employe(nom, prenom){
	nom_ = nom;
	prenom_ = prenom;
}

unsigned int AgentSecurite::getNiveauAcces() const{
	return accesAgentSecurite_ + Employe::getNiveauAcces();
}

string AgentSecurite::getClasseEmploye() const{
	string temp;
	temp = typeid(AgentSecurite).name();
	temp.erase(0, 6);
	return temp;
}

ostream& operator<< (ostream& os, const AgentSecurite& agentSecurite){
	cout << "Classe: " << agentSecurite.getClasseEmploye() << endl << "Prenom: " << agentSecurite.getPrenom() << endl << "Nom: " << agentSecurite.getNom() << endl << "Niveau d'acces: " << agentSecurite.getNiveauAcces() << "\n\n";
	return os;
}