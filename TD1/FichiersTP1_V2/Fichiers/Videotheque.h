/************************************************************************************
*	Fichier					: Film.h
*	Auteur					: Julien Aymong et Benjamin Brodeur
*	Description				: Headers de la classe Videotheque
*	Date de création		: 22 janvier 2013
*	Date de modification	: 24 janvier 2013
************************************************************************************/

#ifndef VIDEOTHEQUE_H
#define VIDEOTHEQUE_H

#include<string>
#include<iostream>

#include"Date.h"
#include"Film.h"
#include"Coffret.h"

using namespace std;

class Videotheque
{
public:
	// Constructeurs et déconstructeurs
	Videotheque();
	~Videotheque();

	// Méthodes de la classe
	void ajouterCoffret(Coffret* coffret);
	unsigned int nombreCoffret()const;
	void afficherVideotheque()const;

private:
	//Attribus
	Coffret** contenuVideotheque_;
	int nbCoffret_;
	int capacite_;
};

#endif