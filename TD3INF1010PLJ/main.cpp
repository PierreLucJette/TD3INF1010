#include "Employe.h"
#include "Professeur.h"
#include "AgentSecurite.h"
#include "PirateInformatique.h"
#include "Etudiant.h"
#include "RegleAcces.h"
#include "SystemeSecurite.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//Creer le systeme de securite

	/////////////////////////////////////////////////////////////
	//Ajouter les regles suivantes:
	//
	//	niveau d'acces	Local		Periode
	//
	//	1,				"L-3589",	PERIODE_ACCES_MATIN
	//	1,				"L-3587",	PERIODE_ACCES_MATIN
	//	1,				"L-3588",	PERIODE_ACCES_MATIN
	//
	//	5,				"L-3589",	PERIODE_ACCES_SOIR
	//	5,				"L-3587",	PERIODE_ACCES_SOIR
	//	5,				"L-3588",	PERIODE_ACCES_SOIR
	//
	//	20,				"L-3589",	PERIODE_ACCES_NUIT
	//	20,				"L-3587",	PERIODE_ACCES_NUIT
	//	25,				"L-3588",	PERIODE_ACCES_NUIT
	//
	//	10,				"L-4489",	PERIODE_ACCES_MATIN
	//	10,				"L-4487",	PERIODE_ACCES_MATIN
	//
	//	10,				"L-4489",	PERIODE_ACCES_SOIR
	//	10,				"L-4487",	PERIODE_ACCES_SOIR
	//
	//	20,				"L-4489",	PERIODE_ACCES_NUIT
	//	25,				"L-4487",	PERIODE_ACCES_NUIT
	//
	////////////////////////////////////////////////////////////

	


	//Creer un agent de securite
	//
	//	nom: Nelson
	//  prenom: Garry
	//
	
    // afficher les infos de l'agent de sécurité (operator <<)

	//Creer un professeur
	//
	//	nom: Rios
	//  prenom: Janet
	//
	// afficher les infos du professeur (operator <<)

	//Creer un etudiant
	//
	//	nom: Ball
	//  prenom: Damon
	//
	// afficher les infos de l'étudiant (operator <<)


	//Cree un pirate Informatique qui prendra l'identite 
	//du gardien de securite
	

	//L'agent de securite tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_NUIT
	//	"L-4489",	PERIODE_ACCES_SOIR
	//	"L-4487",	PERIODE_ACCES_NUIT
	//
	//
	
	

	//Le professeur tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_MATIN
	//	"L-4489",	PERIODE_ACCES_NUIT
	//	"L-4487",	PERIODE_ACCES_SOIR
	//
	//
	


	//L'etudiant tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3589",	PERIODE_ACCES_MATIN
	//	"L-4489",	PERIODE_ACCES_NUIT
	//	"L-3589",	PERIODE_ACCES_SOIR
	//
	//
	


	//Le pirate informatique tente d'acceder aux locaux suivants a l'aide de la fonction suivante:
	//
	//	bool accederLocal(string nom, string prenom, string fonction, unsigned int niveauAcces, string local, string periode);
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_NUIT
	//	"L-4489",	PERIODE_ACCES_SOIR
	//	"L-4487",	PERIODE_ACCES_NUIT
	//
	//
	


	//Afficher le journal d'acces du systeme de securite
	


	return 0;
}


//Reponse a la question:
//	
//	
//	Employe* etudiant = new Etudiant("Ball", "Damon");
//
//	sysSecu.accederLocal	(	etudiant->getNom(), 
//								etudiant->getPrenom(), 
//								etudiant->getFonction(), 
//								etudiant->getNiveauAcces(), 
//								"L-3589", 
//								PERIODE_ACCES_NUIT
//							);
//
//	delete etudiant;
//	
//	
//	
//	




