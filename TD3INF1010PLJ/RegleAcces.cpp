/********************************************************
Fichier: RegleAcces.cpp
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Implémentation de la classe RegleAcces
********************************************************/

#include <string>
#include "RegleAcces.h"

//Constructeur par défaut
RegleAcces::RegleAcces()
{ 
	niveauAccesRequis_ = 1;
	local_ = "";
	periode_ = PERIODE_ACCES_MATIN;
}

//Constructeur par paramètre
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

//Accesseur: retourne niveauAccèsRequis
unsigned int RegleAcces::getNiveauAccesRequis() const
{
	return niveauAccesRequis_;
}

//Accesseur: retourne la periode
string RegleAcces::getPeriode() const
{
	return periode_;
}

//Surcharge de l'opérateur ==. Vérifie l'égalité entre les deux RegleAcces en cause. Retourne true si égal
bool RegleAcces::operator== (const RegleAcces& regle) const
{ 
	return (this->getLocal() == regle.getLocal() && 
		this->getNiveauAccesRequis() == regle.getNiveauAccesRequis() && 
		this->getPeriode() == regle.getPeriode());
}