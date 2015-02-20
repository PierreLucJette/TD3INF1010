#include <iostream>
#include <string>
#include "PirateInformatique.h"
#include "AgentSecurite.h"
#include "Employe.h"

using namespace std;

PirateInformatique::PirateInformatique(const AgentSecurite& agentSecurite): AgentSecurite(agentSecurite.getNom(), agentSecurite.getPrenom()){

}

unsigned int PirateInformatique::getNiveauAcces() const{
	return AgentSecurite::getNiveauAcces();
}
