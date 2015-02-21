/********************************************************
Fichier: AgentSecurite.h
Auteurs: Pierre-Luc Jett� && Claire Quesnel
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description:
********************************************************/

#ifndef AGENTSECURITE_H_
#define AGENTSECURITE_H_

#include <iostream>
#include <string>
#include "Employe.h"

using namespace std;

class AgentSecurite :public Employe{

public:
	AgentSecurite(const string& nom, const string& prenom);

	unsigned int getNiveauAcces() const;
	string getClasseEmploye() const;

	friend ostream& operator<< (ostream& os, const AgentSecurite& agentSecurite);

protected:
	const unsigned int accesAgentSecurite_ = 20;
};

#endif

//TODO: double check