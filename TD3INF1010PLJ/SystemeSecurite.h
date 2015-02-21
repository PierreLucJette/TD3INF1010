/********************************************************
Fichier: SystemeSecurite.h
Auteurs: Pierre-Luc Jett� && Claire Quesnel &&
Charg�s de TP d'INF1010
Date de cr�ation: Jeudi 19 f�vrier 2015
Derni�re modification: Samedi 21 f�vrier 2015
Description: D�finition de la classe SystemeSecurite
********************************************************/

#ifndef	SYSTEME_SECURITE_H
#define SYSTEME_SECURITE_H

#include "RegleAcces.h"
#include "AgentSecurite.h"
#include "Professeur.h"
#include "Etudiant.h"
#include "Employe.h"
#include <vector>
#include <string>

using namespace std;

struct Journal{
	string nom = "";
	string prenom = "";
	string classeEmploye = "";
	string local = "";
	string periode = "";
	string acces = "";
	/*
		Nous justifions l'utilisation d'une structure Journal par rapport � streamstring par les faits que
		l'utilisation d'une structure est plus intuitive tant � l'�criture qu'� la lecture du code et que 
		la structure utilise plus efficacement les ressources du syst�me qu'un streamstring.
	*/
};

class SystemeSecurite
{
public:
	//Constructeur
	SystemeSecurite();

	//Toutes les surcharges d'accederLocal v�rifient si l'individu a acc�s au local � cette p�riode. Cela se fait en comparant les param�tres de la fonction aux r�gles dans le vecteur regles_. Retourne true si acc�s accord�. 
	bool accederLocal(const AgentSecurite& agent,	const string& local, const string& periode);
	bool accederLocal(const Professeur& prof,		const string& local, const string& periode);
	bool accederLocal(const Etudiant& etudiant,		const string& local, const string& periode);
	bool accederLocal(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode);

	//Mutateur. Ajoute une regle au vecteur regles_ si pas d�j� pr�sent
	bool ajouterRegle(const RegleAcces& regle);

	//Affiche le journal d'acc�s
	void imprimerJournal() const;

private:
	vector<RegleAcces>		regles_;
	vector<Journal>			journalAcces_; //Chang� vector<string> � vector<Journal>. Voir justification sous la d�finition de la structure, plus haut, Line 30.
};

#endif