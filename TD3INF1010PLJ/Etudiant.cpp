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

//Constructeur par paramètre
Etudiant::Etudiant(const string& nom, const string& prenom) : Employe(nom, prenom)
{ 
	nom_ = nom; 
	prenom_ = prenom;
}

//Accesseur: retourne accèsEtudiant_
unsigned int Etudiant::getNiveauAcces() const
{ 
	return accesEtudiant_;
}

//Retourne le nom de la classe
string Etudiant::getClasseEmploye() const
{
	string temp;
	temp = typeid(Etudiant).name();
	temp.erase(0, 6);//Justifiable parce que sinon, temp serait égal à "class Etudiant"
	return temp;
}

//Affiche les informations relatives à l'objet lorsqu'il surcharge l'opérateur <<
ostream& operator<< (ostream& os, const Etudiant& etudiant)
{
	os << "Classe: " << etudiant.getClasseEmploye() << endl << "Prenom: " << etudiant.getPrenom() << endl << "Nom: " << etudiant.getNom() << endl << "Niveau d'acces: " << etudiant.getNiveauAcces() << "\n\n";
	return os;
}