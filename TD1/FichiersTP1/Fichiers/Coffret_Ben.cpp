/************************************************************************************
*	Fichier					: Coffret.h
*	Auteur					: Benjamin Brodeur Mathieu
*	Description				: Impl�mentation de la classe Coffret
*	Date de creation		: 17 Janvier 2013
*	Date de modification	: 17 Janvier 2013
************************************************************************************/

#include <iostream>
#include <string>

// Include projet

#include "Date.h";
#include "Coffret.h";
#include "Film.h";

using namespace std;

	

	//Constructeurs et Destructeurs
	Coffret::Coffret()
		:dateCreation_()
	{
		contenuCoffret_ = new Film[6]; // Taille maximum sp�cifi�e
		identifiant_ = 0;
		titre_ = "Coffret par D�faut";
	}
	Coffret::Coffret(unsigned int identifiant, string titre, Date dateCreation, Film* contenuCoffret)
	{
		contenuCoffret_ = contenuCoffret;
		identifiant_ = identifiant;
		titre_ = titre;
		dateCreation_ = dateCreation;
	}
	Coffret::~Coffret()
	{
		delete [] contenuCoffret_;
		contenuCoffret_ = 0;
	}

	//M�thodes d'acc�s

	unsigned int Coffret::getIdentifiant()
	{
		return identifiant_;
	}
	string Coffret::getTitre()
	{
		return titre_;
	}
	Date Coffret::getDateCreation()
	{
		return dateCreation_;
	}

	//M�thodes de modification
	
	void Coffret::setIdentifiant(unsigned int identifiant)
	{
		identifiant_ = identifiant;
	}
	void Coffret::setTitre(string titre)
	{
		titre_ = titre;
	}
	void Coffret::getDateCreation(Date dateCreation)
	{
		dateCreation_ = dateCreation;
	}


	int compteurFilm = 0;
	void Coffret::ajouterFilm(Film film)
	{
		contenuCoffret[compteurFilm] = film;
		compteurFilm++;
	}

	//M�thodes d'affichages

	void Coffret::afficher()
	{
		cout << "Identifiant : " << identifiant_ << endl;
		cout << "Titre du coffret : " << titre_ << endl;
		cout << "Date de cr�ation du coffret : " << dateCreation_ << endl;
		cout << "Contenu du coffret : ";
		
		for (int i = 0; i < compteurFilm ; i++)
		{
			cout << "Film num�ro : " << i+1;
			cout << contenuCoffret[i].afficherInfoFilm();
		}
	}


