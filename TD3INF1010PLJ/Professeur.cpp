#include <iostream>
#include <string>
#include "Professeur.h"

using namespace std;

Professeur::Professeur(const string& nom, const string& prenom) :Employe(nom, prenom){
	nom_ = nom;
	prenom_ = prenom;
}

Professeur::~Professeur(){}

unsigned int Professeur::getNiveauAcces() const{
	return accesProfesseur_;
}

string Professeur::getClasseEmploye() const{
	string temp;
	temp = typeid(Professeur).name();
	temp.erase(0, 6); //Oui c'est bâtard, mais typeid aussi c'est bâtard
	return temp;
}

ostream& operator<< (ostream& os, const Professeur& professeur){
	os << "Classe " << professeur.getClasseEmploye() << endl << "Prenom: " << professeur.getPrenom() << endl << "Nom: " << professeur.getNom() << endl << "Niveau d'acces: " << professeur.getNiveauAcces() << "\n\n";
	return os;
}