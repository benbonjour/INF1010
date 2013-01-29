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
	*  Tester les op�rateurs << et >> et constructeurs
	*************************************************************************/
	// 1 - Cr�er un triangle t = [1 ; -5 3 ; 2 -6 5]
	// Cr�ation par constructeur par param�tres

	// 2 - Afficher le triangle t et modifier un �l�ment

	// 3 - Afficher le poids du triangle t

	/*************************************************************************
	*  Tester les diff�rents op�rateurs
	*************************************************************************/
	// 4 - Cr�er le triangle identit� I = [ 1 ; 0 1 ; 0 0 1 ]
	// Cr�ation par >> : Cr�er un triangle de taille 3 et utiliser l'op�rateur >> pour y ins�rer les valeurs

    // 5 - Cr�er un triangle v = t + I*2;
	
	// 6 - R�aliser l'op�ration suivante : t^2 + (v^2)*3 et afficher le resultat

	/*************************Notez bien : **********************************/
	// t^2 = t*t ; t^3 = t^2*t;

	/*************************************************************************
	*  Tester les op�rateurs de comparaison
	*************************************************************************/
	// 7 - Cr�er les triangles a = [ 5 ; -2 4 ; 3 -1 -6 ] et b = [ 4 ; 3 -1 ; 7 1 -3 ]

	// 8 - Tester tous les op�rateurs de comparaisons entre a et b

	system("pause");
	return 0;
}