#ifndef PROFESSEUR_H_
#define PROFESSEUR_H_

#include <iostream>
#include <string>
#include "Employe.h"

using namespace std;

class Professeur :public Employe{

public:
	Professeur(const string& nom, const string& prenom);
	virtual ~Professeur();

	virtual unsigned int getNiveauAcces() const;
	virtual string getClasseEmploye() const;

	 friend ostream& operator<< (ostream& os, const Professeur& professeur);

private:
	const unsigned int accesProfesseur_ = 10;
};

#endif