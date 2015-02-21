/*************************************************************
Fichier: main.cpp
Auteurs: Pierre-Luc Jetté && Claire Quesnel
Date de création: Jeudi 19 février 2015
Dernière modification: Samedi 21 février 2015
Description: 
	Fichier central du programme. Ce programme 
	vise à tester l'implémentation correcte de nos classes 
	créées grâce à l'héritage. Ainsi, on crée un système
	de sécurité, plusieurs règles d'accès et des personnes
	ayants différents niveaux d'accès dans le système.
	Ensuite, on leur fait essayer d'accéder à différentes 
	salles au cours de la journée, puis on affiche le journal
	de ces entrées.
*************************************************************/

#include <iostream>
#include <string>
#include "Employe.h"
#include "Professeur.h"
#include "AgentSecurite.h"
#include "PirateInformatique.h"
#include "Etudiant.h"
#include "RegleAcces.h"
#include "SystemeSecurite.h"


using namespace std;

int main()
{
	SystemeSecurite systeme;
	
	systeme.ajouterRegle(RegleAcces(1, "L-3589", PERIODE_ACCES_MATIN));
	systeme.ajouterRegle(RegleAcces(1, "L-3587", PERIODE_ACCES_MATIN));
	systeme.ajouterRegle(RegleAcces(1, "L-3588", PERIODE_ACCES_MATIN));

	systeme.ajouterRegle(RegleAcces(5, "L-3589", PERIODE_ACCES_SOIR));
	systeme.ajouterRegle(RegleAcces(5, "L-3587", PERIODE_ACCES_SOIR));
	systeme.ajouterRegle(RegleAcces(5, "L-3588", PERIODE_ACCES_SOIR));
	
	systeme.ajouterRegle(RegleAcces(20, "L-3589", PERIODE_ACCES_NUIT));
	systeme.ajouterRegle(RegleAcces(20, "L-3587", PERIODE_ACCES_NUIT));
	systeme.ajouterRegle(RegleAcces(25, "L-3588", PERIODE_ACCES_NUIT));

	systeme.ajouterRegle(RegleAcces(10, "L-4489", PERIODE_ACCES_MATIN));
	systeme.ajouterRegle(RegleAcces(10, "L-4487", PERIODE_ACCES_MATIN));
	//
	systeme.ajouterRegle(RegleAcces(10, "L-4489", PERIODE_ACCES_SOIR));
	systeme.ajouterRegle(RegleAcces(10, "L-4487", PERIODE_ACCES_SOIR));
	//
	systeme.ajouterRegle(RegleAcces(20, "L-4489", PERIODE_ACCES_NUIT));
	systeme.ajouterRegle(RegleAcces(25, "L-4487", PERIODE_ACCES_NUIT));

	//Créer un agent de securite Garry Nelson
	AgentSecurite garryNelson("Nelson", "Garry");
	//Afficher l'agent
	cout << garryNelson;

	//Créer un professeur Janet Rion
	Professeur janetRios("Rios", "Janet");
	//Afficher le professeur
	cout << janetRios;
	
	//Créer un etudiant Ball Damon
	Etudiant damonBall("Ball", "Damon");
	//Afficher l'etudiant
	cout << damonBall;

	//Créer un Pirate Informatique lambda qui prends les informations de garryNelson
	PirateInformatique lambda(garryNelson);

	//Tentatives d'acces
	systeme.accederLocal(garryNelson, "L-3587", PERIODE_ACCES_NUIT);
	systeme.accederLocal(garryNelson, "L-4489", PERIODE_ACCES_SOIR);
	systeme.accederLocal(garryNelson, "L-4487", PERIODE_ACCES_NUIT);	

	systeme.accederLocal(janetRios, "L-3587", PERIODE_ACCES_MATIN);
	systeme.accederLocal(janetRios, "L-4489", PERIODE_ACCES_NUIT);
	systeme.accederLocal(janetRios, "L-4487", PERIODE_ACCES_SOIR);

	systeme.accederLocal(damonBall, "L-3589", PERIODE_ACCES_MATIN);
	systeme.accederLocal(damonBall, "L-4489", PERIODE_ACCES_NUIT);
	systeme.accederLocal(damonBall, "L-3589", PERIODE_ACCES_SOIR);

	systeme.accederLocal(lambda.getNom(), lambda.getPrenom(), lambda.getClasseEmploye(), lambda.getNiveauAcces(), "L-3587", PERIODE_ACCES_NUIT);
	systeme.accederLocal(lambda.getNom(), lambda.getPrenom(), lambda.getClasseEmploye(), lambda.getNiveauAcces(), "L-4489", PERIODE_ACCES_SOIR);
	systeme.accederLocal(lambda.getNom(), lambda.getPrenom(), lambda.getClasseEmploye(), lambda.getNiveauAcces(), "L-4487", PERIODE_ACCES_NUIT);

	//Imprime le journal des tentatives d'acces
	systeme.imprimerJournal();

	return 0;
}

/*	
	Réponse à la question à la fin du TD3:
	
	Employe* etudiant = new Etudiant("Christophe", "Jean");
	systeme.accederLocal(etudiant->getNom(), 
						 etudiant->getPrenom(), 
						 etudiant->getClasseEmploye(), 
						 etudiant->Employe::getNiveauAcces(), 
						 "L-3589", 
						 PERIODE_ACCES_SOIR);
	delete etudiant;

	Ce code fonctionne simplement parce ce que la classe Étudiant est héritée de la classe Employé. Comme la méthode 
	getNiveauAcces() d'Employé est publique et que la classe Étudiant hérite de ses methodes publiques, Étudiant peux
	utiliser la méthode d'Employé. Comme la méthode d'Employé retourne l'attribut private d'Employé accesEmployé_
	(qui est égal à 5), un objet de classe Étudiant a accès au niveau d'accès d'un Employé.
*/
