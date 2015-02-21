/********************************************************
Fichier: PirateInformatique.h
Auteurs: Pierre-Luc Jett� && Claire Quesnel
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: D�finition de la classe PirateInformatique
********************************************************/

#ifndef PIRATEINFORMATIQUE_H_
#define PIRATEINFORMATIQUE_H_

#include <iostream>
#include <string>
#include "AgentSecurite.h"

using namespace std;

class PirateInformatique : public AgentSecurite{

public:
	//Constructeur. Prends en param�tre un agent de s�curit� duquel il copie les informations.
	PirateInformatique(const AgentSecurite& agentSecurite);

	//Accesseur
	unsigned int getNiveauAcces() const;
};

#endif