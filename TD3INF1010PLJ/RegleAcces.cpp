/********************************************************
Fichier: RegleAcces.cpp
Auteurs: Pierre-Luc Jett� && Claire Quesnel
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: Impl�mentation de la classe RegleAcces
********************************************************/

#include <string>
#include "RegleAcces.h"

//Constructeur par d�faut
RegleAcces::RegleAcces()
{ 
	niveauAccesRequis_ = 1;
	local_ = "";
	periode_ = PERIODE_ACCES_MATIN;
}

//Constructeur par param�tre
RegleAcces::RegleAcces(const unsigned int& niveau, const string& local, const string& periode)
{ 
	niveauAccesRequis_ = niveau;
	local_ = local;
	periode_ = periode;
}

//Accesseur: retour local_
string RegleAcces::getLocal() const
{ 
	return local_;
}

//Accesseur: retourne niveauAcc�sRequis
unsigned int RegleAcces::getNiveauAccesRequis() const
{
	return niveauAccesRequis_;
}

//Accesseur: retourne la periode
string RegleAcces::getPeriode() const
{
	return periode_;
}

//Surcharge de l'op�rateur ==. V�rifie l'�galit� entre les deux RegleAcces en cause. Retourne true si �gal
bool RegleAcces::operator== (const RegleAcces& regle) const
{ 
	return (this->getLocal() == regle.getLocal() && 
		this->getNiveauAccesRequis() == regle.getNiveauAccesRequis() && 
		this->getPeriode() == regle.getPeriode());
}