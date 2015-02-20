#include <iostream>
#include <string>
#include "Etudiant.h"

using namespace std;

Etudiant::Etudiant(const string& nom, const string& prenom) : Employe(nom, prenom){
	nom_ = nom; 
	prenom_ = prenom;
}

unsigned int Etudiant::getNiveauAcces() const{
	return accesEtudiant_;
}

string Etudiant::getClasseEmploye() const{
	string temp;
	temp = typeid(Etudiant).name();
	temp.erase(0, 6);
	return temp;
}

ostream& operator<< (ostream& os, const Etudiant& etudiant){
	os << "Classe: " << etudiant.getClasseEmploye() << endl << "Prenom: " << etudiant.getPrenom() << endl << "Nom: " << etudiant.getNom() << endl << "Niveau d'acces: " << etudiant.getNiveauAcces() << "\n\n";
	return os;
}