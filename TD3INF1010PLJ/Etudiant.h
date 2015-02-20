#ifndef ETUDIANT_H_
#define ETUDIANT_H_

#include <iostream>
#include <string>
#include "Employe.h"

using namespace std;

class Etudiant :public Employe{

public:
	Etudiant(const string& nom, const string& prenom);

	virtual unsigned int getNiveauAcces() const;
	virtual string getClasseEmploye() const;

	friend ostream& operator<< (ostream& os, const Etudiant& etudiant);

protected:
	const unsigned int accesEtudiant_ = 1;

};

#endif