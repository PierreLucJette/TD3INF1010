#include <iostream>
#include <string>
#include <typeinfo>
#include "Employe.h"

using namespace std;

Employe::Employe(const string& nom, const string& prenom){
	nom_ = nom;
	prenom_ = prenom;
}

string Employe::getNom() const{
	return nom_;
}

string Employe::getPrenom() const{
	return prenom_;
}

unsigned int Employe::getNiveauAcces() const{
	return accesEmploye_;
}

string Employe::getClasseEmploye() const{
	string temp;
	temp = typeid(Employe).name();
	temp.erase(0, 6); //Oui c'est bâtard, mais typeid aussi c'est bâtard
	return temp;
}

ostream& operator<< (ostream& os, const Employe& employe){
	os << "Classe " << employe.getClasseEmploye() << endl << "Prenom: " << employe.getPrenom() << endl << "Nom: " << employe.getNom() << endl << "Niveau d'acces: " << employe.getNiveauAcces() << "\n\n";
	return os;
}