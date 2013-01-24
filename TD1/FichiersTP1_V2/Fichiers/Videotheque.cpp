/************************************************************************************
*	Fichier					: Film.cpp
*	Auteur					: Julien Aymong et Benjamin Brodeur
*	Description				: Définition de la classe Videotheque
*	Date de création		: 22 janvier 2013
*	Date de modification	: 24 janvier 2013
************************************************************************************/

#include <iostream>
#include <string>

#include"Film.h"
#include"Date.h"
#include"Coffret.h"
#include"Videotheque.h"

using namespace std;

const int CAPACITE_DEBUT = 2; // Capacité de départ du tableau dynamique pour les coffrets

/************************************************************************************
*	Description :	Videotheque::Videotheque
*					Cette méthode est le constructeur par défaut de l'objet Videotheque.
*					Il crée un tableau dynamique de pointeur de type Coffret selon la
*					capacité CAPACITE_DEBUT.
*	Paramètres :	Aucun
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Videotheque::Videotheque()
{
	contenuVideotheque_ = new Coffret*[CAPACITE_DEBUT];
	nbCoffret_ = 0; // Il y a aucun coffret ajouté par l'utilisateur à sa création
	capacite_ = CAPACITE_DEBUT;
}

/************************************************************************************
*	Description :	Videotheque::~Videotheque
*					Cette méthode est le destructeur de l'objet. Il contient une boucle
*					qui détruit tout les pointeurs dans le tableau et met les pointeurs
*					à zéro, puis désalloue le tableau et fait pointer le pointeur vers 0.
*	Paramètre :		Aucun
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Videotheque::~Videotheque()
{
	for (int i = 0; i < nbCoffret_; i++) // Destruction de tous les pointeurs contenus dans le tableau
	{
		delete contenuVideotheque_[i];
		contenuVideotheque_[i] = 0;
	}
	delete []contenuVideotheque_;
	contenuVideotheque_ = 0;
}

/************************************************************************************
*	Description :	Videotheque::ajouterCoffret
*					Cette méthode permet d'ajouter un coffret par pointeur dans la vidéotheque.
*					Si le tableau dynamique représentant la vidéothèque est pleine,
*					un nouveau tableau avec une capacité double est alloué.
*	Parametre :		Coffret* coffret : pointeur vers un coffret
*	Valeur de rètour : Aucune
*	Remarque :		Aucune
************************************************************************************/
void Videotheque::ajouterCoffret(Coffret* coffret)
{
	if (nbCoffret_ < capacite_)
	{
		contenuVideotheque_[nbCoffret_] = coffret;
		nbCoffret_ ++;
	}
	else // Si le tableau est plein, allocation d'un nouveau tableau de capacité double
	{
		capacite_ *= 2;
		Coffret** tempVideotheque = new Coffret*[capacite_];

		for (int i = 0; i < nbCoffret_; i++)
		{
			tempVideotheque[i] = contenuVideotheque_[i];
		}
		delete []contenuVideotheque_;
		contenuVideotheque_ = tempVideotheque;
		tempVideotheque = 0;

		contenuVideotheque_[nbCoffret_] = coffret;
		nbCoffret_ ++;
	}
}

/************************************************************************************
*	Description :	Videotheque::nombreCoffret
*					Cette méthode retounre à l'utilisateur le nombre de coffret présent
*					dans la vidéothèque.
*	Paramètre :		Aucun	
*	Valeur de retour : Unsigned int	
*	Remarque :		Ceci est une méthode constante.
************************************************************************************/
unsigned int Videotheque::nombreCoffret() const
{
	return nbCoffret_;
}

/************************************************************************************
*	Description :	Videotheque::afficherVideotheque
					Cette méthode permet d'afficher tous les coffrets présents dans la
					vidéothèque.
*	Paramètre :		Aucun
*	Valeur de retour : Aucune
*	Remarque :		Ceci est une méthode constante.
************************************************************************************/
void Videotheque::afficherVideotheque() const
{
	for (int i = 0; i < nbCoffret_; i++)
	{
		contenuVideotheque_[i]->afficherCoffret();
	}
}