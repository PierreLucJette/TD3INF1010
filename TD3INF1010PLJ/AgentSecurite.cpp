/********************************************************
Fichier: AgentSecurite.cpp
Auteurs: Pierre-Luc Jett� && Claire Quesnel
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: Impl�mentation de la AgentSecurite
********************************************************/

#include <iostream>
#include <string>
#include "AgentSecurite.h"

using namespace std;

AgentSecurite::AgentSecurite(const string& nom, const string& prenom): Employe(nom, prenom){ //Constructeur par param�tre
	nom_ = nom;
	prenom_ = prenom;
}

unsigned int AgentSecurite::getNiveauAcces() const{ //Accesseur: retour le niveau d'acc�s d'agent de s�curite + employ�
	return accesAgentSecurite_ + Employe::getNiveauAcces();
}

string AgentSecurite::getClasseEmploye() const{//Retourne le nom de la classe
	string temp;
	temp = typeid(AgentSecurite).name();
	temp.erase(0, 6);//Justifiable parce que sinon, temp serait �gal � "class AgentSecurite"
	return temp;
}

ostream& operator<< (ostream& os, const AgentSecurite& agentSecurite){//Affiche les informations relatives � l'objet lorsqu'il surcharge l'op�rateur <<
	cout << "Classe: " << agentSecurite.getClasseEmploye() << endl << "Prenom: " << agentSecurite.getPrenom() << endl << "Nom: " << agentSecurite.getNom() << endl << "Niveau d'acces: " << agentSecurite.getNiveauAcces() << "\n\n";
	return os;
}