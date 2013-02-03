/************************************************************************************
*	Fichier					: Coffret.h
*	Auteur					: Benjamin Brodeur Mathieu et Julien Aymong
*	Description				: Impl�mentation de la classe Coffret
*	Date de creation		: 17 Janvier 2013
*	Date de modification	: 17 Janvier 2013
************************************************************************************/

#include <iostream>
#include <string>

#include "Date.h";
#include "Coffret.h";
#include "Film.h";

using namespace std;

/************************************************************************************
*	Description :
*	Param�tre :
*	Valeur de retour :
*	Remarque :
************************************************************************************/
Coffret::Coffret()
{
	contenuCoffret_ = new Film*[6];
	identifiantCoffret_ = 0;
	titreCoffret_ = "Coffret par defaut";
	compteurFilm_ = 0;
	dateCreationCoffret_ = Date();
}

/************************************************************************************
*	Description :
*	Param�tre :
*	Valeur de retour :
*	Remarque :
************************************************************************************/
Coffret::Coffret(unsigned int identifiantCoffret, string titreCoffret, Date dateCreationCoffret/*, Film** contenuCoffret*/)
	:identifiantCoffret_(identifiantCoffret), titreCoffret_(titreCoffret), dateCreationCoffret_(dateCreationCoffret)
{
	contenuCoffret_ = new Film*[6];
	compteurFilm_ = 0;
}

/************************************************************************************
*	Description :
*	Param�tre :
*	Valeur de retour :
*	Remarque :
************************************************************************************/
Coffret::~Coffret()
{
	
	for (unsigned int i = 0; i < compteurFilm_; i++)
	{
		delete contenuCoffret_[i];
		contenuCoffret_[i] = 0;
	}
	
	delete []contenuCoffret_;
	contenuCoffret_ = 0;
}

/************************************************************************************
*	Description :
*	Param�tre :
*	Valeur de retour :
*	Remarque :
************************************************************************************/
unsigned int Coffret::getIdentifiantCoffret()const
{
	return identifiantCoffret_;
}

/************************************************************************************
*	Description :
*	Param�tre :
*	Valeur de retour :
*	Remarque :
************************************************************************************/
string Coffret::getTitreCoffret()const
{
	return titreCoffret_;
}

/************************************************************************************
*	Description :
*	Param�tre :
*	Valeur de retour :
*	Remarque :
************************************************************************************/
Date Coffret::getDateCreationCoffret()const
{
	return dateCreationCoffret_;
}

/************************************************************************************
*	Description :
*	Param�tre :
*	Valeur de retour :
*	Remarque :
************************************************************************************/
void Coffret::setIdentifiantCoffret(unsigned int identifiant)
{
	identifiantCoffret_ = identifiant;
}

/************************************************************************************
*	Description :
*	Param�tre :
*	Valeur de retour :
*	Remarque :
************************************************************************************/
void Coffret::setTitreCoffret(string& titreCoffret)
{
	titreCoffret_ = titreCoffret;
}

/************************************************************************************
*	Description :
*	Param�tre :
*	Valeur de retour :
*	Remarque :
************************************************************************************/
void Coffret::setDateCreation(Date& dateCreationCoffret)
{
	dateCreationCoffret_ = dateCreationCoffret;
}

/************************************************************************************
*	Description :
*	Param�tre :
*	Valeur de retour :
*	Remarque :
************************************************************************************/
void Coffret::ajouterFilmCoffret(Film* film)
{
bool estPresent = false;
	if (compteurFilm_ != 0)
	{
		for(unsigned int i = 0; i< (compteurFilm_); i++)
		{
			if (contenuCoffret_[i]->getId() != film->getId() && contenuCoffret_[i]->getTitre() != film->getTitre())
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
	else
	{
		contenuCoffret_[compteurFilm_] = film;
		compteurFilm_++;
	}
		
}

/************************************************************************************
*	Description :
*	Param�tre :
*	Valeur de retour :
*	Remarque :
************************************************************************************/
void Coffret::afficherCoffret()const
{
	cout << "Identifiant : " << identifiantCoffret_ << endl;
	cout << "Titre du coffret : " << titreCoffret_ << endl;
	cout << "Date de cr�ation du coffret : ";
	dateCreationCoffret_.afficheDate();
	cout << endl;
	cout << "Contenu du coffret : " << endl;;
	
	for (unsigned int i = 0; i < compteurFilm_ ; i++)
	{
		cout << "Film num�ro : " << i+1 << endl;
		contenuCoffret_[i]->afficherInfoFilm();
	}
}