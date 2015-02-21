

#include <iostream>
#include <string>
#include "RegleAcces.h"

RegleAcces::RegleAcces(){
	niveauAccesRequis_ = 1;
	local_ = "";
	periode_ = PERIODE_ACCES_MATIN;
}

RegleAcces::RegleAcces(const unsigned int& niveau, const string& local, const string& periode){
	niveauAccesRequis_ = niveau;
	local_ = local;
	periode_ = periode;
}

string RegleAcces::getLocal() const{
	return local_;
}

unsigned int RegleAcces::getNiveauAccesRequis() const{
	return niveauAccesRequis_;
}

string RegleAcces::getPeriode() const{
	return periode_;
}

bool RegleAcces::operator== (const RegleAcces& regle) const{
	return (this->getLocal() == regle.getLocal() && this->getNiveauAccesRequis() == regle.getNiveauAccesRequis() && this->getPeriode() == regle.getPeriode());
}