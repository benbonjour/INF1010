/**********************************************************************
/* Fichier: Main.cpp
/* Date: 
/* Auteur: 
/* Description: Fichier principal du TP2
************************************************************************/

#include <iostream>
using namespace std;
#include "Triangle.h"
#include <vector>

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
*	Description :	Triangle: getTaille()
*	Param�tre :		Cette m�thode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
int Triangle::getTaille()
{
	return taille_;
}



/************************************************************************************
*	Description :	Triangle:~Triangle()
*	Param�tre :		Cette m�thode est le destructeur par d�faut
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Triangle::~Triangle()
{


}