/********************************************************
Fichier: Employe.cpp
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Implémentation de la Employe
********************************************************/

#include <iostream>
#include <string>
#include "Employe.h"

using namespace std;

//Constructeur par paramètre
Employe::Employe(const string& nom, const string& prenom)
{ 
	nom_ = nom;
	prenom_ = prenom;
}

//Accesseur: retourne nom_
string Employe::getNom() const
{
	return nom_;
}

//Accesseur: retourne prenom_
string Employe::getPrenom() const
{ 
	return prenom_;
}

//Accesseur: retour accesEmploye_
unsigned int Employe::getNiveauAcces() const
{ 
	return accesEmploye_;
}

//Retourne le nom de la classe
string Employe::getClasseEmploye() const
{
	string temp;
	temp = typeid(Employe).name();
	temp.erase(0, 6); //Justifiable parce que sinon, temp serait égal à "class Employe"
	return temp;
}

//Affiche les informations relatives à l'objet lorsqu'il surcharge l'opérateur <<. 
ostream& operator<< (ostream& os, const Employe& employe){
	os << "Classe " << employe.getClasseEmploye() << endl << "Prenom: " << employe.getPrenom() << endl << "Nom: " << employe.getNom() << endl << "Niveau d'acces: " << employe.getNiveauAcces() << "\n\n";
	return os;
}