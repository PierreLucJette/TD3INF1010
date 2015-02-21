/********************************************************
Fichier: Etudiant.h
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Définition de la classe Etudiant
********************************************************/

#ifndef ETUDIANT_H_
#define ETUDIANT_H_

#include <iostream>
#include <string>
#include "Employe.h"

using namespace std;

class Etudiant : public Employe{

public:
	//Constructeur
	Etudiant(const string& nom, const string& prenom);

	//Accesseurs
	unsigned int getNiveauAcces() const;
	string getClasseEmploye() const;

	//Surcharge de l'opérateur <<. Retourne le nom, prénom, le nom de la classe et le niveau d'accès de l'objet
	friend ostream& operator<< (ostream& os, const Etudiant& etudiant);

private:
	const unsigned int accesEtudiant_ = 1;
};

#endif