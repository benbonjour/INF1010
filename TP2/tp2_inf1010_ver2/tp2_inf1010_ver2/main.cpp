/**********************************************************************
/* Fichier: Main.cpp
/* Date:  28 Janvier 2013
/* Auteur: Julien Aymong, Benjamin Brodeur Mathieu
/* Description: Fichier principal du TP2
************************************************************************/

#include <iostream>
using namespace std;
#include "Triangle.h"

// Vérification pour les fuites de mémoires
#define _CRTDBG_MAP_ALLOC // Utilise les allocations avec débogage.
#include <stdlib.h>
#include <crtdbg.h>
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ ) // Ajoute le numéro de ligne au rapport de fuites.

int main()
{
	// Vérification pour les fuites de mémoires
	_CrtSetDbgFlag(0
	| _CRTDBG_ALLOC_MEM_DF    // Débogage d'allocation mémoire.
	| _CRTDBG_LEAK_CHECK_DF   // Rapport de fuites à la sortie du programme.
	| _CRTDBG_CHECK_ALWAYS_DF // Vérifie la corruption à chaque new/delete (lent).
	);

	/*************************************************************************
	*  Tester les opérateurs << et >> et constructeurs
	*************************************************************************/
	// 1 - Créer un triangle t = [1 ; -5 3 ; 2 -6 5]
	// Création par constructeur par paramètres
	int* tableauDonnee = new int [6];
	tableauDonnee[0] = 1;
	tableauDonnee[1] = -5;
	tableauDonnee[2] = 3;
	tableauDonnee[3] = 2;
	tableauDonnee[4] = -6;
	tableauDonnee[5] = 5;

	Triangle deuxTriangle(3, tableauDonnee);

	// 2 - Afficher le triangle t et modifier un élément
	cout << deuxTriangle;
	cin >> deuxTriangle;
	cout << deuxTriangle;

	// 3 - Afficher le poids du triangle t
	cout << deuxTriangle.poids();
	cout << endl << endl;

	/*************************************************************************
	*  Tester les différents opérateurs
	*************************************************************************/
	// 4 - Créer le triangle identité I = [ 1 ; 0 1 ; 0 0 1 ]
	// Création par >> : Créer un triangle de taille 3 et utiliser l'opérateur >> pour y insérer les valeurs
	/*
	Triangle troisTriangle(3);
	cin >> troisTriangle;
	cin >> troisTriangle;
	cin >> troisTriangle;
	cin >> troisTriangle;
	cin >> troisTriangle;
	cin >> troisTriangle;
	cout << troisTriangle;
	*/
	int* tableauDonneeTrois = new int [6];
	tableauDonneeTrois[0] = 1;
	tableauDonneeTrois[1] = 0;
	tableauDonneeTrois[2] = 1;
	tableauDonneeTrois[3] = 0;
	tableauDonneeTrois[4] = 0;
	tableauDonneeTrois[5] = 1;

	Triangle t(3, tableauDonneeTrois);


    // 5 - Créer un triangle v = t + I*2;
	Triangle v;
	v = deuxTriangle + t * 2;
	cout << v;

	
	// 6 - Réaliser l'opération suivante : t^2 + (v^2)*3 et afficher le resultat
	Triangle v2;
	v2 = t*t + (v*v)*3;
	cout << v2;

	/*************************Notez bien : **********************************/
	// t^2 = t*t ; t^3 = t^2*t;

	/*************************************************************************
	*  Tester les opérateurs de comparaison
	*************************************************************************/
	// 7 - Créer les triangles a = [ 5 ; -2 4 ; 3 -1 -6 ] et b = [ 4 ; 3 -1 ; 7 1 -3 ]
	int* tableauA = new int [6];
	tableauA[0] = 5;
	tableauA[1] = -2;
	tableauA[2] = 4;
	tableauA[3] = 3;
	tableauA[4] = -1;
	tableauA[5] = -6;

	Triangle a(3, tableauA);

	int* tableauB = new int [6];
	tableauB[0] = 4;
	tableauB[1] = 3;
	tableauB[2] = -1;
	tableauB[3] = 7;
	tableauB[4] = 1;
	tableauB[5] = -3;

	Triangle b(3, tableauB);

	// 8 - Tester tous les opérateurs de comparaisons entre a et b
	cout << boolalpha << (a < b) << endl;
	cout << boolalpha << (a > b) << endl;
	cout << boolalpha << (a == b) << endl;

	system("pause");
	return 0;
}