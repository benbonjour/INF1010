/************************************************************************************
*	Fichier					: Coffret.h
*	Auteur					: Benjamin Brodeur Mathieu
*	Description				: Implémentation de la classe Coffret
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
Coffret::Coffret():dateCreation_()
{
	contenuCoffret_ = new Film[6]; // Taille maximum spécifiée
	identifiant_ = 0;
	titre_ = "Coffret par Defaut";
	compteurFilm_ = 0;
}

Coffret::Coffret(unsigned int identifiant, string titre, Date dateCreation)
{
	contenuCoffret_ = new Film[6];
	identifiant_ = identifiant;
	titre_ = titre;
	dateCreation_ = dateCreation;
	compteurFilm_ = 0;
}

Coffret::~Coffret()
{
	
	delete []contenuCoffret_;
	contenuCoffret_ = 0;
	
}

//Méthodes d'accès

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

//Méthodes de modification

void Coffret::setIdentifiant(unsigned int& identifiant)
{
	identifiant_ = identifiant;
}
void Coffret::setTitre(string& titre)
{
	titre_ = titre;
}
void Coffret::setDateCreation(Date& dateCreation)
{
	dateCreation_ = dateCreation;
}


void Coffret::ajouterFilm(Film* film)
{
	bool estPresent = false;
	for(int i = 0; i< (compteurFilm_+1); i++)
	{
		if (contenuCoffret_[i].getId() != film->getId() && contenuCoffret_[i].getTitre() != film->getTitre())
		{
			
		}
		else
		{
			estPresent = true;
		}
	}

	if (estPresent == false)
	{
		contenuCoffret_[compteurFilm_] = film;
		compteurFilm_++;
	}
	else
	{
		cout << "Le film que vous tentez d'ajouter au coffret y est deja present." << endl;
	}
	
}

//Méthodes d'affichages

void Coffret::afficher()
{
	cout << "Identifiant : " << identifiant_ << endl;
	cout << "Titre du coffret : " << titre_ << endl;
	cout << "Date de création du coffret : ";
	dateCreation_.afficheDate();
	cout << endl;
	cout << "Contenu du coffret : " << endl;;
	
	for (int i = 0; i < compteurFilm_ ; i++)
	{
		cout << "Film numéro : " << i+1 << endl;
		contenuCoffret_[i].afficherInfoFilm();
	}
	
}


