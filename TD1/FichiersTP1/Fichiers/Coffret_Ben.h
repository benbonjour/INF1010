/************************************************************************************
*	Fichier					: Coffret.h
*	Auteur					: Benjamin Brodeur Mathieu
*	Description				: Definition de la classe Coffret
*	Date de creation		: 17 Janvier 2013
*	Date de modification	: 17 Janvier 2013
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
	//Constructeurs et Destructeurs
	Coffret();
	Coffret(unsigned int identifiant, string titre, Date dateCreation, Film* contenuCoffret);
	~Coffret();

	//Méthodes d'accès

	unsigned int getIdentifiant();
	string getTitre();
	Date getDateCreation();

	//Méthodes de modification
	
	void setIdentifiant(unsigned int identifiant);
	void setTitre(string titre);
	void getDateCreation(Date dateCreation);

	void ajouterFilm(Film film);

	//Méthodes d'affichages

	void afficher();

private:
	//Attributs
	unsigned int identifiant_;
	string titre_;
	Date dateCreation_;
	Film* contenuCoffret_;
};

#endif


