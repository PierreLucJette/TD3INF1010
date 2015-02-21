/********************************************************
Fichier: PirateInformatique.cpp
Auteurs: Pierre-Luc Jett� && Claire Quesnel
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: Impl�mentation de la classe 
	PirateInformatique
********************************************************/

#include "PirateInformatique.h"
#include "AgentSecurite.h"

using namespace std;

//Constructeur. Copie les attributs d'un agent de securit�
PirateInformatique::PirateInformatique(const AgentSecurite& agentSecurite): AgentSecurite(agentSecurite.getNom(), agentSecurite.getPrenom())
{}

//Retourne le niveau d'acc�s d'un agent de securit�.
unsigned int PirateInformatique::getNiveauAcces() const
{ 
	return AgentSecurite::getNiveauAcces();
}
