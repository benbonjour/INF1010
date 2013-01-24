/************************************************************************************
*	Fichier					: Coffret.h
*	Auteur					: 
*	Description				: Definition de la classe Coffret
*	Date de creation		: 
*	Date de modification	: 
************************************************************************************/
#ifndef _COFFRET_H_
#define _COFFRET_H_

#include <iostream>
#include <string>

// Include projet

#include "Date.h";
#include "Film.h";

using namespace std;

class Coffret
{
public:
	Coffret();
	Coffret(unsigned int identifiantCoffret, string titreCoffret, Date dateCreaftionCoffret/*, Film** contenuCoffret*/);
	~Coffret();

	unsigned int getIdentifiantCoffret()const;
	string getTitreCoffret()const;
	Date getDateCreationCoffret()const;

	void setIdentifiantCoffret(unsigned int identifiant);
	void setTitreCoffret(string& titreCoffret);
	void setDateCreation(Date& dateCreationCoffret);

	void ajouterFilmCoffret(Film* film);

	void afficherCoffret()const;

private:
	unsigned int identifiantCoffret_;
	string titreCoffret_;
	Date dateCreationCoffret_;
	Film** contenuCoffret_;
	unsigned int compteurFilm_;
};

#endif