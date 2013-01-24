/************************************************************************************
*	Fichier					: Film.cpp
*	Auteur					: 
*	Description				: Definition de la classe Film
*	Date de cr»ation		:
*	Date de modification	: 
************************************************************************************/

#include <iostream>
#include <string>

#include"Film.h"
#include"Date.h"
#include"Coffret.h"
#include"Videotheque.h"

using namespace std;

const int CAPACITE_DEBUT = 2;

Videotheque::Videotheque()
{
	contenuVideotheque_ = new Coffret[CAPACITE_DEBUT];
	nbCoffret_ = 0;
	capacite_ = CAPACITE_DEBUT;
}

Videotheque::~Videotheque()
{
	delete []contenuVideotheque_;
	contenuVideotheque_ = 0;
}

void Videotheque::ajouterCoffret(Coffret& coffret)
{
	if (nbCoffret_ < capacite_)
	{
		contenuVideotheque_[nbCoffret_] = coffret;
		nbCoffret_ ++;
	}
	else
	{
		capacite_ *= 2;
		Coffret* tempVideotheque = new Coffret[capacite_];

		for (int i = 0; i < nbCoffret_; i++)
		{
			tempVideotheque[i] = contenuVideotheque_[i];
		}
		delete []contenuVideotheque_;
		contenuVideotheque_ = tempVideotheque;
		tempVideotheque = 0;

		/*
		capacite_ *= 2;
		contenuVideotheque_ = new Coffret[capacite_];
		for (int i = 0; i < nbCoffret_; i++)
		{
			contenuVideotheque_[i] = tempVideotheque[i];
		}
		delete []tempVideotheque;
		*/

		contenuVideotheque_[nbCoffret_] = coffret;
		nbCoffret_ ++;
	}
}

unsigned int Videotheque::nombreCoffret() const
{
	return nbCoffret_;
}

void Videotheque::afficherVideotheque()const
{
	for (int i = 0; i < nbCoffret_; i++)
	{
		contenuVideotheque_[i].afficher();
	}
}