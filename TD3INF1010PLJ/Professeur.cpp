/********************************************************
Fichier: Professeur.cpp
Auteurs: Pierre-Luc Jett� && Claire Quesnel
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: Impl�mentation de la classe Professeur
********************************************************/

#include <iostream>
#include <string>
#include "Professeur.h"

using namespace std;

//Constructeur: Assigne le nom et pr�nom en param�tre � l'objet cr�e
Professeur::Professeur(const string& nom, const string& prenom) :Employe(nom, prenom)
{ 
	nom_ = nom;
	prenom_ = prenom;
}

//Retourne le niveau d'acc�s d'un professeur + celui d'un employ�
unsigned int Professeur::getNiveauAcces() const
{ 
	return accesProfesseur_ + Employe::getNiveauAcces();
}

//Retourne le nom de la classe Professeur
string Professeur::getClasseEmploye() const
{ 
	string temp;
	temp = typeid(Professeur).name();
	temp.erase(0, 6); //Justifiable parce que sinon, temp serait �gal � "class Professeur"
	return temp;
}

//Affiche les informations relatives � l'objet lorsqu'il surcharge l'op�rateur <<
ostream& operator<< (ostream& os, const Professeur& professeur)
{ 
	os << "Classe: " << professeur.getClasseEmploye() << endl << "Prenom: " << professeur.getPrenom() << endl << "Nom: " << professeur.getNom() << endl << "Niveau d'acces: " << professeur.getNiveauAcces() << "\n\n";
	return os;
}