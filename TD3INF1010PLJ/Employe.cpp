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

//Constructeur par param�tre
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
	temp.erase(0, 6); //Justifiable parce que sinon, temp serait �gal � "class Employe"
	return temp;
}

//Affiche les informations relatives � l'objet lorsqu'il surcharge l'op�rateur <<. 
ostream& operator<< (ostream& os, const Employe& employe){
	os << "Classe " << employe.getClasseEmploye() << endl << "Prenom: " << employe.getPrenom() << endl << "Nom: " << employe.getNom() << endl << "Niveau d'acces: " << employe.getNiveauAcces() << "\n\n";
	return os;
}