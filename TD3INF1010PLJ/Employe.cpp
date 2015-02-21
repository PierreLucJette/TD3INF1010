/********************************************************
Fichier: Employe.cpp
Auteurs: Pierre-Luc Jett� && Claire Quesnel
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: Impl�mentation de la Employe
********************************************************/

#include <iostream>
#include <string>
#include "Employe.h"

using namespace std;

Employe::Employe(const string& nom, const string& prenom){ //Constructeur par param�tre
	nom_ = nom;
	prenom_ = prenom;
}

string Employe::getNom() const{ //Accesseur: retourne nom_
	return nom_;
}

string Employe::getPrenom() const{ //Accesseur: retourne prenom_
	return prenom_;
}

unsigned int Employe::getNiveauAcces() const{ //Accesseur: retour accesEmploye_
	return accesEmploye_;
}

string Employe::getClasseEmploye() const{//Retourne le nom de la classe
	string temp;
	temp = typeid(Employe).name();
	temp.erase(0, 6); //Justifiable parce que sinon, temp serait �gal � "class Employe"
	return temp;
}

ostream& operator<< (ostream& os, const Employe& employe){//Affiche les informations relatives � l'objet lorsqu'il surcharge l'op�rateur <<
	os << "Classe " << employe.getClasseEmploye() << endl << "Prenom: " << employe.getPrenom() << endl << "Nom: " << employe.getNom() << endl << "Niveau d'acces: " << employe.getNiveauAcces() << "\n\n";
	return os;
}