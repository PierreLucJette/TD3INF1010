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

Professeur::Professeur(const string& nom, const string& prenom) :Employe(nom, prenom){ //Constructeur: Assigne le nom et prénom en paramètre à l'objet crée
	nom_ = nom;
	prenom_ = prenom;
}

unsigned int Professeur::getNiveauAcces() const{ //Retour le niveau d'accès d'un professeur + d'un employé
	return accesProfesseur_ + Employe::getNiveauAcces();
}

string Professeur::getClasseEmploye() const{ //Retourne le nom de la classe Professeur
	string temp;
	temp = typeid(Professeur).name();
	temp.erase(0, 6); //Justifiable parce que sinon, temp serait égal à "class Professeur"
	return temp;
}

ostream& operator<< (ostream& os, const Professeur& professeur){ //Affiche les informations relatives à l'objet lorsqu'il surcharge l'opérateur <<
	os << "Classe: " << professeur.getClasseEmploye() << endl << "Prenom: " << professeur.getPrenom() << endl << "Nom: " << professeur.getNom() << endl << "Niveau d'acces: " << professeur.getNiveauAcces() << "\n\n";
	return os;
}