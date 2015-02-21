/********************************************************
Fichier: Etudiant.cpp
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Implémentation de la classe Etudiant
********************************************************/

#include <iostream>
#include <string>
#include "Etudiant.h"

using namespace std;

Etudiant::Etudiant(const string& nom, const string& prenom) : Employe(nom, prenom){ //Constructeur par paramètre
	nom_ = nom; 
	prenom_ = prenom;
}

unsigned int Etudiant::getNiveauAcces() const{ //Accesseur: retourne accèsEtudiant_
	return accesEtudiant_;
}

string Etudiant::getClasseEmploye() const{//Retourne le nom de la classe
	string temp;
	temp = typeid(Etudiant).name();
	temp.erase(0, 6);//Justifiable parce que sinon, temp serait égal à "class Etudiant"
	return temp;
}

ostream& operator<< (ostream& os, const Etudiant& etudiant){//Affiche les informations relatives à l'objet lorsqu'il surcharge l'opérateur <<
	os << "Classe: " << etudiant.getClasseEmploye() << endl << "Prenom: " << etudiant.getPrenom() << endl << "Nom: " << etudiant.getNom() << endl << "Niveau d'acces: " << etudiant.getNiveauAcces() << "\n\n";
	return os;
}