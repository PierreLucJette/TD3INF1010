/********************************************************
Fichier: RegleAcces.h
Auteurs: Pierre-Luc Jett� && Claire Quesnel && 
Charg�s de TP d'INF1010
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: D�finition de la classe RegleAcces
********************************************************/

#ifndef REGLES_ACCES_H
#define	REGLES_ACCES_H

#include <string>

using namespace std;

const string PERIODE_ACCES_MATIN = "Matin";
const string PERIODE_ACCES_SOIR = "Soir";
const string PERIODE_ACCES_NUIT = "Nuit";


using namespace std;

class RegleAcces
{
public:
	//Constructeurs
	RegleAcces();
	RegleAcces(const unsigned int& niveau, const string& local, const string& periode); //CHANG�: Ajout� const devant unsigned int niveau

	//Accesseurs
	string			getLocal()				const;
	unsigned int	getNiveauAccesRequis()	const;
	string			getPeriode()			const;

	//Surcharge de l'op�rateur ==. Retour true si les deux r�gles compar�es sont les m�mes.
	bool operator==(const RegleAcces& regle) const;

private:
	string			local_;
	unsigned int	niveauAccesRequis_;
	string			periode_;
};

#endif