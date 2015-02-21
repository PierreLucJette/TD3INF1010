/********************************************************
Fichier: Etudiant.h
Auteurs: Pierre-Luc Jett� && Claire Quesnel
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: D�finition de la classe Etudiant
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

	//Surcharge de l'op�rateur <<. Retourne le nom, pr�nom, le nom de la classe et le niveau d'acc�s de l'objet
	friend ostream& operator<< (ostream& os, const Etudiant& etudiant);

private:
	const unsigned int accesEtudiant_ = 1;
};

#endif