/********************************************************
Fichier: Professeur.h
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Définition de la classe Professeur
********************************************************/

#ifndef PROFESSEUR_H_
#define PROFESSEUR_H_

#include <string>
#include "Employe.h"

using namespace std;

class Professeur : public Employe{

public:
	//Constructeur
	Professeur(const string& nom, const string& prenom);

	//Accesseurs
	unsigned int getNiveauAcces() const;
	string getClasseEmploye() const;

	//Surcharge de l'opérateur <<. Retourne le nom, prénom, le nom de la classe et le niveau d'accès de l'objet
	friend ostream& operator<< (ostream& os, const Professeur& professeur);

private:
	const unsigned int accesProfesseur_ = 10;
};

#endif