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

//Constructeur. Copie les attributs d'un agent de securité
PirateInformatique::PirateInformatique(const AgentSecurite& agentSecurite): AgentSecurite(agentSecurite.getNom(), agentSecurite.getPrenom())
{}

//Retourne le niveau d'accès d'un agent de securité.
unsigned int PirateInformatique::getNiveauAcces() const
{ 
	return AgentSecurite::getNiveauAcces();
}
