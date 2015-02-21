/********************************************************
Fichier: RegleAcces.cpp
Auteurs: Pierre-Luc Jett� && Claire Quesnel
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: Impl�mentation de la classe RegleAcces
********************************************************/

#include <string>
#include "RegleAcces.h"

RegleAcces::RegleAcces(){ //Constructeur par d�faut
	niveauAccesRequis_ = 1;
	local_ = "";
	periode_ = PERIODE_ACCES_MATIN;
}

RegleAcces::RegleAcces(const unsigned int& niveau, const string& local, const string& periode){ //Constructeur par param�tre
	niveauAccesRequis_ = niveau;
	local_ = local;
	periode_ = periode;
}

string RegleAcces::getLocal() const{ //Accesseur: retour local_
	return local_;
}

unsigned int RegleAcces::getNiveauAccesRequis() const{//Accesseur: retourne niveauAcc�sRequis
	return niveauAccesRequis_;
}

string RegleAcces::getPeriode() const{//Accesseur: retourne periode_
	return periode_;
}

bool RegleAcces::operator== (const RegleAcces& regle) const{ //Surcharge de l'op�rateur ==. V�rifie l'�galit� entre les deux RegleAcces en cause. Retourne true si �gal
	return (this->getLocal() == regle.getLocal() && this->getNiveauAccesRequis() == regle.getNiveauAccesRequis() && this->getPeriode() == regle.getPeriode());
}