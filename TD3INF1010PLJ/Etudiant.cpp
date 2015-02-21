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

//Constructeur par param�tre
Etudiant::Etudiant(const string& nom, const string& prenom) : Employe(nom, prenom)
{ 
	nom_ = nom; 
	prenom_ = prenom;
}

//Accesseur: retourne acc�sEtudiant_
unsigned int Etudiant::getNiveauAcces() const
{ 
	return accesEtudiant_;
}

//Retourne le nom de la classe
string Etudiant::getClasseEmploye() const
{
	string temp;
	temp = typeid(Etudiant).name();
	temp.erase(0, 6);//Justifiable parce que sinon, temp serait �gal � "class Etudiant"
	return temp;
}

//Affiche les informations relatives � l'objet lorsqu'il surcharge l'op�rateur <<
ostream& operator<< (ostream& os, const Etudiant& etudiant)
{
	os << "Classe: " << etudiant.getClasseEmploye() << endl << "Prenom: " << etudiant.getPrenom() << endl << "Nom: " << etudiant.getNom() << endl << "Niveau d'acces: " << etudiant.getNiveauAcces() << "\n\n";
	return os;
}