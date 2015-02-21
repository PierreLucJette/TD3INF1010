/********************************************************
Fichier: PirateInformatique.cpp
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Implémentation de la classe 
	PirateInformatique
********************************************************/

#include "PirateInformatique.h"
#include "AgentSecurite.h"

using namespace std;

PirateInformatique::PirateInformatique(const AgentSecurite& agentSecurite): AgentSecurite(agentSecurite.getNom(), agentSecurite.getPrenom()){} //Constructeur. Copie les attributs d'un agent de securité

unsigned int PirateInformatique::getNiveauAcces() const{ //Retourne le niveau d'accès d'un agent de securité.
	return AgentSecurite::getNiveauAcces();
}
