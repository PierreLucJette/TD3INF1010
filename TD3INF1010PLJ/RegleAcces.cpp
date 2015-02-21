/********************************************************
Fichier: RegleAcces.cpp
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: Implémentation de la classe RegleAcces
********************************************************/

#include <string>
#include "RegleAcces.h"

RegleAcces::RegleAcces(){ //Constructeur par défaut
	niveauAccesRequis_ = 1;
	local_ = "";
	periode_ = PERIODE_ACCES_MATIN;
}

RegleAcces::RegleAcces(const unsigned int& niveau, const string& local, const string& periode){ //Constructeur par paramètre
	niveauAccesRequis_ = niveau;
	local_ = local;
	periode_ = periode;
}

string RegleAcces::getLocal() const{ //Accesseur: retour local_
	return local_;
}

unsigned int RegleAcces::getNiveauAccesRequis() const{//Accesseur: retourne niveauAccèsRequis
	return niveauAccesRequis_;
}

string RegleAcces::getPeriode() const{//Accesseur: retourne periode_
	return periode_;
}

bool RegleAcces::operator== (const RegleAcces& regle) const{ //Surcharge de l'opérateur ==. Vérifie l'égalité entre les deux RegleAcces en cause. Retourne true si égal
	return (this->getLocal() == regle.getLocal() && this->getNiveauAccesRequis() == regle.getNiveauAccesRequis() && this->getPeriode() == regle.getPeriode());
}