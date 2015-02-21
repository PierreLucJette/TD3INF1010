/********************************************************
Fichier: Etudiant.cpp
Auteurs: Pierre-Luc Jett� && Claire Quesnel
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: Impl�mentation de la classe Etudiant
********************************************************/

#include <iostream>
#include <string>
#include "Etudiant.h"

using namespace std;

Etudiant::Etudiant(const string& nom, const string& prenom) : Employe(nom, prenom){ //Constructeur par param�tre
	nom_ = nom; 
	prenom_ = prenom;
}

unsigned int Etudiant::getNiveauAcces() const{ //Accesseur: retourne acc�sEtudiant_
	return accesEtudiant_;
}

string Etudiant::getClasseEmploye() const{//Retourne le nom de la classe
	string temp;
	temp = typeid(Etudiant).name();
	temp.erase(0, 6);//Justifiable parce que sinon, temp serait �gal � "class Etudiant"
	return temp;
}

ostream& operator<< (ostream& os, const Etudiant& etudiant){//Affiche les informations relatives � l'objet lorsqu'il surcharge l'op�rateur <<
	os << "Classe: " << etudiant.getClasseEmploye() << endl << "Prenom: " << etudiant.getPrenom() << endl << "Nom: " << etudiant.getNom() << endl << "Niveau d'acces: " << etudiant.getNiveauAcces() << "\n\n";
	return os;
}