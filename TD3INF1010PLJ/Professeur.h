/********************************************************
Fichier: Professeur.h
Auteurs: Pierre-Luc Jett� && Claire Quesnel
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: D�finition de la classe Professeur
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

	//Surcharge de l'op�rateur <<. Retourne le nom, pr�nom, le nom de la classe et le niveau d'acc�s de l'objet
	friend ostream& operator<< (ostream& os, const Professeur& professeur);

private:
	const unsigned int accesProfesseur_ = 10;
};

#endif