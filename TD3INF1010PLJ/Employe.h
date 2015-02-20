#ifndef EMPLOYE_H_
#define EMPLOYE_H_

#include <string>
#include <iostream>

using namespace std;

class Employe{

public:
	Employe(const string& nom, const string& prenom);

	string getNom() const;
	string getPrenom() const;
	unsigned int getNiveauAcces() const;
	string getClasseEmploye() const;

	friend ostream& operator<< (ostream& os, const Employe& employe);

protected:
	string nom_;
	string prenom_;

private:
	const unsigned int accesEmploye_ = 5;

};

#endif
