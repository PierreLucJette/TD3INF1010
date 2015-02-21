/********************************************************
Fichier: Employe.h
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Définition de la classe Employe
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

	//Surcharge de l'opérateur <<. Retourne le nom, prénom, le nom de la classe et le niveau d'accès de l'objet
	friend ostream& operator<< (ostream& os, const Employe& employe);

protected:
	string nom_;
	string prenom_;

private:
	const unsigned int accesEmploye_ = 5;

};

#endif
