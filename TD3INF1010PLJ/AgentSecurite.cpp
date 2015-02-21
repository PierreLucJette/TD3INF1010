/********************************************************
Fichier: AgentSecurite.cpp
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Implémentation de la AgentSecurite
********************************************************/

#include <iostream>
#include <string>
#include "AgentSecurite.h"

using namespace std;

AgentSecurite::AgentSecurite(const string& nom, const string& prenom): Employe(nom, prenom){ //Constructeur par paramètre
	nom_ = nom;
	prenom_ = prenom;
}

unsigned int AgentSecurite::getNiveauAcces() const{ //Accesseur: retour le niveau d'accès d'agent de sécurite + employé
	return accesAgentSecurite_ + Employe::getNiveauAcces();
}

string AgentSecurite::getClasseEmploye() const{//Retourne le nom de la classe
	string temp;
	temp = typeid(AgentSecurite).name();
	temp.erase(0, 6);//Justifiable parce que sinon, temp serait égal à "class AgentSecurite"
	return temp;
}

ostream& operator<< (ostream& os, const AgentSecurite& agentSecurite){//Affiche les informations relatives à l'objet lorsqu'il surcharge l'opérateur <<
	cout << "Classe: " << agentSecurite.getClasseEmploye() << endl << "Prenom: " << agentSecurite.getPrenom() << endl << "Nom: " << agentSecurite.getNom() << endl << "Niveau d'acces: " << agentSecurite.getNiveauAcces() << "\n\n";
	return os;
}