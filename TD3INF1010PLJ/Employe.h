/********************************************************
Fichier: Employe.h
Auteurs: Pierre-Luc Jett� && Claire Quesnel
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: D�finition de la classe Employe
********************************************************/

#ifndef EMPLOYE_H_
#define EMPLOYE_H_

#include <string>
#include <iostream>

using namespace std;

class Employe{

public:
	//Constructeur
	Employe(const string& nom, const string& prenom);

	//Accesseurs
	string getNom() const;
	string getPrenom() const;
	unsigned int getNiveauAcces() const;
	string getClasseEmploye() const;

	//Surcharge de l'op�rateur <<. Retourne le nom, pr�nom, le nom de la classe et le niveau d'acc�s de l'objet
	friend ostream& operator<< (ostream& os, const Employe& employe);

protected:
	string nom_;
	string prenom_;

private:
	const unsigned int accesEmploye_ = 5;

};

#endif
