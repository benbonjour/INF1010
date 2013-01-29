/**********************************************************************
/* Fichier: Main.cpp
/* Date: 28 Janvier 2013
/* Auteur: Julien Aymong, Benjamin Brodeur Mathieu
/* Description: Fichier principal du TP2
************************************************************************/

#include <iostream>
using namespace std;
#include "Triangle.h"
#include <vector>

// Constructeurs et Destructeur
/************************************************************************************
*	Description :	Triangle: Triangle()
*	Param�tre :		Cette m�thode est le constructeur par d�faut
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Triangle::Triangle():taille_(1), donnees_(new int[1]){}
/************************************************************************************
*	Description :	Triangle: Triangle(int taille)
*	Param�tre :		Cette m�thode intialise la taille du triangle
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Triangle::Triangle(int taille)
{
	taille_ = taille;
}
/************************************************************************************
*	Description :	Triangle: Triangle(int taille)
*	Param�tre :		Cette m�thode intialise la taille du triangle
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Triangle::Triangle(int taille)
{
	taille_ = taille;
}
/************************************************************************************
*	Description :	Triangle: Triangle(int taille, int* donnees)
*	Param�tre :		Cette m�thode intialise la taille et les donnees du triangle
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Triangle::Triangle(int taille, int* donnees)
{
	taille_ = taille;
	donnees_ = donnees;
}
/************************************************************************************
*	Description :	Triangle:~Triangle()
*	Param�tre :		Cette m�thode est le destructeur par d�faut
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
// TODO
Triangle::~Triangle()
{


}                                


// M�thode d'Acc�s
/************************************************************************************
*	Description :	Triangle: getTaille()
*	Param�tre :		Cette m�thode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
int Triangle::getTaille()
{
	return taille_;
}





