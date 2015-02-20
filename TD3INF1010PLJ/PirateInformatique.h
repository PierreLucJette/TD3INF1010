#ifndef PIRATEINFORMATIQUE_H_
#define PIRATEINFORMATIQUE_H_

#include <iostream>
#include <string>
#include "Employe.h"
#include "AgentSecurite.h"

using namespace std;

class PirateInformatique :public AgentSecurite{

public:
	PirateInformatique(const AgentSecurite& agentSecurite);
	virtual ~PirateInformatique();

	virtual unsigned int getNiveauAcces() const;

};

#endif