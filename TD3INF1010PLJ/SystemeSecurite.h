#ifndef	SYSTEME_SECURITE_H
#define SYSTEME_SECURITE_H

#include "RegleAcces.h" 
#include "AgentSecurite.h"
#include "Professeur.h"
#include "Etudiant.h"
#include <vector>
#include <string>

using namespace std;

class SystemeSecurite
{
public:
	SystemeSecurite();

	bool accederLocal(const AgentSecurite& agent,	const string& local, const string& periode);
	bool accederLocal(const Professeur& prof,		const string& local, const string& periode);
	bool accederLocal(const Etudiant& etudiant,		const string& local, const string& periode);

	bool accederLocal(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode);

	bool ajouterRegle(const RegleAcces& regle);

	void imprimerJournal() const;

private:
	vector<RegleAcces>		regles_;
	vector<string>			journalAcces_;
};

#endif //DEPARTEMENT_H