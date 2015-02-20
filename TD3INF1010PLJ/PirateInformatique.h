#ifndef PIRATEINFORMATIQUE_H_
#define PIRATEINFORMATIQUE_H_

#include <iostream>
#include <string>
#include "Employe.h"
#include "AgentSecurite.h"

using namespace std;

class PirateInformatique :public Employe{

public:
	PirateInformatique(const AgentSecurite& agentsecurite);
	virtual ~PirateInformatique();

	virtual unsigned int getNiveauAcces() const;

};

#endif