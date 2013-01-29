/**********************************************************************
/* Fichier: Main.cpp
/* Date: 
/* Auteur: 
/* Description: Fichier principal du TP2
************************************************************************/

#include <iostream>
using namespace std;
#include "Triangle.h"


int main()
{
	Triangle unTriangle, unAutreTriangle(7);
	cout << unTriangle.getTaille() << "  " << unAutreTriangle.getTaille() << endl;
	


	/*************************************************************************
	*  Tester les opérateurs << et >> et constructeurs
	*************************************************************************/
	// 1 - Créer un triangle t = [1 ; -5 3 ; 2 -6 5]
	// Création par constructeur par paramètres

	// 2 - Afficher le triangle t et modifier un élément

	// 3 - Afficher le poids du triangle t

	/*************************************************************************
	*  Tester les différents opérateurs
	*************************************************************************/
	// 4 - Créer le triangle identité I = [ 1 ; 0 1 ; 0 0 1 ]
	// Création par >> : Créer un triangle de taille 3 et utiliser l'opérateur >> pour y insérer les valeurs

    // 5 - Créer un triangle v = t + I*2;
	
	// 6 - Réaliser l'opération suivante : t^2 + (v^2)*3 et afficher le resultat

	/*************************Notez bien : **********************************/
	// t^2 = t*t ; t^3 = t^2*t;

	/*************************************************************************
	*  Tester les opérateurs de comparaison
	*************************************************************************/
	// 7 - Créer les triangles a = [ 5 ; -2 4 ; 3 -1 -6 ] et b = [ 4 ; 3 -1 ; 7 1 -3 ]

	// 8 - Tester tous les opérateurs de comparaisons entre a et b

	system("pause");
	return 0;
}