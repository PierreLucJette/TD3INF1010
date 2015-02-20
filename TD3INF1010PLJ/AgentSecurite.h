#ifndef AGENTSECURITE_H_
#define AGENTSECURITE_H_

#include <iostream>
#include <string>
#include "Employe.h"

using namespace std;

class AgentSecurite :public Employe{

public:
	AgentSecurite(const string& nom, const string& prenom);
	virtual ~AgentSecurite();

	virtual unsigned int getNiveauAcces() const;
	virtual string getClasseEmploye() const;

	friend ostream& operator<< (ostream& os, const AgentSecurite& agentSecurite);

protected:
	const unsigned int accesAgentSecurite_ = 20;
};

#endif

//TODO: double check