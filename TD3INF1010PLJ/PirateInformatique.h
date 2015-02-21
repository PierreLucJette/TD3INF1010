/********************************************************
Fichier: PirateInformatique.h
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Définition de la classe PirateInformatique
********************************************************/

#ifndef PIRATEINFORMATIQUE_H_
#define PIRATEINFORMATIQUE_H_

#include <iostream>
#include <string>
#include "AgentSecurite.h"

using namespace std;

class PirateInformatique : public AgentSecurite{

public:
	//Constructeur. Prends en paramètre un agent de sécurité duquel il copie les informations.
	PirateInformatique(const AgentSecurite& agentSecurite);

	//Accesseur
	unsigned int getNiveauAcces() const;
};

#endif