/************************************************************************************
*	Fichier					: Film.h
*	Auteur					: 
*	Description				: Definition de la classe Film
*	Date de cr»ation		: 10 Janvier 2013
*	Date de modification	: 
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
	Videotheque();
	~Videotheque();

	void ajouterCoffret(Coffret& coffret);
	unsigned int nombreCoffret()const;
	void afficherVideotheque()const;

private:
	Coffret* contenuVideotheque_;
	int nbCoffret_;
	int capacite_;
};

#endif