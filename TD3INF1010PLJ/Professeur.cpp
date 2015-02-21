/********************************************************
Fichier: Professeur.cpp
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Implémentation de la classe Professeur
********************************************************/

#include <iostream>
#include <string>
#include "Professeur.h"

using namespace std;

//Constructeur: Assigne le nom et prénom en paramètre à l'objet crée
Professeur::Professeur(const string& nom, const string& prenom) :Employe(nom, prenom)
{ 
	nom_ = nom;
	prenom_ = prenom;
}

//Retourne le niveau d'accès d'un professeur + celui d'un employé
unsigned int Professeur::getNiveauAcces() const
{ 
	return accesProfesseur_ + Employe::getNiveauAcces();
}

//Retourne le nom de la classe Professeur
string Professeur::getClasseEmploye() const
{ 
	string temp;
	temp = typeid(Professeur).name();
	temp.erase(0, 6); //Justifiable parce que sinon, temp serait égal à "class Professeur"
	return temp;
}

//Affiche les informations relatives à l'objet lorsqu'il surcharge l'opérateur <<
ostream& operator<< (ostream& os, const Professeur& professeur)
{ 
	os << "Classe: " << professeur.getClasseEmploye() << endl << "Prenom: " << professeur.getPrenom() << endl << "Nom: " << professeur.getNom() << endl << "Niveau d'acces: " << professeur.getNiveauAcces() << "\n\n";
	return os;
}