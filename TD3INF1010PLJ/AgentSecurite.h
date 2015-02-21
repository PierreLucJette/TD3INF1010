/********************************************************
Fichier: AgentSecurite.h
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description:
********************************************************/

#ifndef AGENTSECURITE_H_
#define AGENTSECURITE_H_

#include <iostream>
#include <string>
#include "Employe.h"

using namespace std;

class AgentSecurite : public Employe{

public:
	//Constructeur
	AgentSecurite(const string& nom, const string& prenom);

	//Accesseurs
	unsigned int getNiveauAcces() const;
	string getClasseEmploye() const;

	//Surcharge de l'opérateur <<. Retourne le nom, prénom, le nom de la classe et le niveau d'accès de l'objet
	friend ostream& operator<< (ostream& os, const AgentSecurite& agentSecurite);

protected:
	const unsigned int accesAgentSecurite_ = 20;
};

#endif
