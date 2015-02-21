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

class AgentSecurite : public Employe{

public:
	//Constructeur
	AgentSecurite(const string& nom, const string& prenom);

	//Accesseurs
	unsigned int getNiveauAcces() const;
	string getClasseEmploye() const;

	//Surcharge de l'op�rateur <<. Retourne le nom, pr�nom, le nom de la classe et le niveau d'acc�s de l'objet
	friend ostream& operator<< (ostream& os, const AgentSecurite& agentSecurite);

protected:
	const unsigned int accesAgentSecurite_ = 20;
};

#endif
