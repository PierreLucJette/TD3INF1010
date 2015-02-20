#ifndef EMPLOYE_H_
#define EMPLOYE_H_

#include <string>
#include <iostream>

using namespace std;

class Employe{

public:
	Employe(const string& nom, const string& prenom);
	virtual ~Employe();

	virtual string getNom() const;
	virtual string getPrenom() const;
	virtual unsigned int getNiveauAcces() const;
	virtual string getClasseEmploye() const;

	virtual friend void operator<< (ostream& os, const Employe& employe);

protected:
	string nom_;
	string prenom_;

private:
	const unsigned int accesEmploye_ = 5;

};

#endif
