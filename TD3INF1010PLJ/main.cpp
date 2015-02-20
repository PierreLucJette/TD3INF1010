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
	SystemeSecurite systeme;

	//Ajout des règles d'accès
	RegleAcces l3589m(1, "L-3589", PERIODE_ACCES_MATIN);
	RegleAcces l3587m(1, "L-3587", PERIODE_ACCES_MATIN);
	RegleAcces l5388m(1, "L-3588", PERIODE_ACCES_MATIN);
	//
	RegleAcces l3589s(5, "L-3589", PERIODE_ACCES_SOIR);
	RegleAcces l3587s(5, "L-3587", PERIODE_ACCES_SOIR);
	RegleAcces l3588s(5, "L-3588", PERIODE_ACCES_SOIR);
	//
	RegleAcces l3589n(20, "L-3589", PERIODE_ACCES_NUIT);
	RegleAcces l3587n(20, "L-3587", PERIODE_ACCES_NUIT);
	RegleAcces l3588n(25, "L-3588", PERIODE_ACCES_NUIT);
	//
	RegleAcces l4489m(10, "L-4489", PERIODE_ACCES_MATIN);
	RegleAcces l4487m(10, "L-4487", PERIODE_ACCES_MATIN);
	//
	RegleAcces l4489s(10, "L-4489", PERIODE_ACCES_SOIR);
	RegleAcces l4487s(10, "L-4487", PERIODE_ACCES_SOIR);
	//
	RegleAcces l4489n(20, "L-4489", PERIODE_ACCES_NUIT);
	RegleAcces l4487n(25, "L-4487", PERIODE_ACCES_NUIT);
	//

	//Creer un agent de securite
	//
	//	nom: Nelson
	//  prenom: Garry
	AgentSecurite garryNelson("Nelson", "Garry");
	
    // afficher les infos de l'agent de sécurité (operator <<)
	cout << garryNelson;

	//Creer un professeur
	//
	//	nom: Rios
	//  prenom: Janet
	Professeur janetRios("Rios", "Janet");

	// afficher les infos du professeur (operator <<)
	cout << janetRios;

	//Creer un etudiant
	//
	//	nom: Ball
	//  prenom: Damon
	Etudiant damonBall("Ball", "Damon");
	// afficher les infos de l'étudiant (operator <<)
	cout << damonBall;


	//Cree un pirate Informatique qui prendra l'identite 
	//du gardien de securite
	PirateInformatique lambda(garryNelson);
	

	//L'agent de securite tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_NUIT
	//	"L-4489",	PERIODE_ACCES_SOIR
	//	"L-4487",	PERIODE_ACCES_NUIT
	//
	//
	systeme.accederLocal(garryNelson, "L-3587", PERIODE_ACCES_NUIT);
	systeme.accederLocal(garryNelson, "L-4489", PERIODE_ACCES_SOIR);
	systeme.accederLocal(garryNelson, "L-4487", PERIODE_ACCES_NUIT);	

	//Le professeur tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_MATIN
	//	"L-4489",	PERIODE_ACCES_NUIT
	//	"L-4487",	PERIODE_ACCES_SOIR
	//
	//
	systeme.accederLocal(janetRios, "L-3587", PERIODE_ACCES_MATIN);
	systeme.accederLocal(janetRios, "L-4489", PERIODE_ACCES_NUIT);
	systeme.accederLocal(janetRios, "L-4487", PERIODE_ACCES_SOIR);
	


	//L'etudiant tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3589",	PERIODE_ACCES_MATIN
	//	"L-4489",	PERIODE_ACCES_NUIT
	//	"L-3589",	PERIODE_ACCES_SOIR
	//
	//
	systeme.accederLocal(damonBall, "L-3589", PERIODE_ACCES_MATIN);
	systeme.accederLocal(damonBall, "L-4489", PERIODE_ACCES_NUIT);
	systeme.accederLocal(damonBall, "L-3589", PERIODE_ACCES_SOIR);


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
	systeme.accederLocal(lambda.getNom(), lambda.getPrenom(), lambda.getClasseEmploye(), lambda.getNiveauAcces(), "L-3587", PERIODE_ACCES_NUIT);
	systeme.accederLocal(lambda.getNom(), lambda.getPrenom(), lambda.getClasseEmploye(), lambda.getNiveauAcces(), "L-4489", PERIODE_ACCES_SOIR);
	systeme.accederLocal(lambda.getNom(), lambda.getPrenom(), lambda.getClasseEmploye(), lambda.getNiveauAcces(), "L-4487", PERIODE_ACCES_NUIT);

	//Afficher le journal d'acces du systeme de securite
	
	systeme.imprimerJournal();

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




