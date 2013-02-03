/************************************************************************************
*	Fichier					: Film.cpp
*	Auteur					: Julien Aymong et Benjamin Brodeur
*	Description				: D�finition de la classe Videotheque
*	Date de cr�ation		: 22 janvier 2013
*	Date de modification	: 24 janvier 2013
************************************************************************************/

#include <iostream>
#include <string>

#include"Film.h"
#include"Date.h"
#include"Coffret.h"
#include"Videotheque.h"

using namespace std;

const int CAPACITE_DEBUT = 2; // Capacit� de d�part du tableau dynamique pour les coffrets

/************************************************************************************
*	Description :	Videotheque::Videotheque
*					Cette m�thode est le constructeur par d�faut de l'objet Videotheque.
*					Il cr�e un tableau dynamique de pointeur de type Coffret selon la
*					capacit� CAPACITE_DEBUT.
*	Param�tres :	Aucun
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Videotheque::Videotheque()
{
	contenuVideotheque_ = new Coffret*[CAPACITE_DEBUT];
	nbCoffret_ = 0; // Il y a aucun coffret ajout� par l'utilisateur � sa cr�ation
	capacite_ = CAPACITE_DEBUT;
}

/************************************************************************************
*	Description :	Videotheque::~Videotheque
*					Cette m�thode est le destructeur de l'objet. Il contient une boucle
*					qui d�truit tout les pointeurs dans le tableau et met les pointeurs
*					� z�ro, puis d�salloue le tableau et fait pointer le pointeur vers 0.
*	Param�tre :		Aucun
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
*					Cette m�thode permet d'ajouter un coffret par pointeur dans la vid�otheque.
*					Si le tableau dynamique repr�sentant la vid�oth�que est pleine,
*					un nouveau tableau avec une capacit� double est allou�.
*	Parametre :		Coffret* coffret : pointeur vers un coffret
*	Valeur de r�tour : Aucune
*	Remarque :		Aucune
************************************************************************************/
void Videotheque::ajouterCoffret(Coffret* coffret)
{
	if (nbCoffret_ < capacite_)
	{
		contenuVideotheque_[nbCoffret_] = coffret;
		nbCoffret_ ++;
	}
	else // Si le tableau est plein, allocation d'un nouveau tableau de capacit� double
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
*					Cette m�thode retounre � l'utilisateur le nombre de coffret pr�sent
*					dans la vid�oth�que.
*	Param�tre :		Aucun	
*	Valeur de retour : Unsigned int	
*	Remarque :		Ceci est une m�thode constante.
************************************************************************************/
unsigned int Videotheque::nombreCoffret() const
{
	return nbCoffret_;
}

/************************************************************************************
*	Description :	Videotheque::afficherVideotheque
					Cette m�thode permet d'afficher tous les coffrets pr�sents dans la
					vid�oth�que.
*	Param�tre :		Aucun
*	Valeur de retour : Aucune
*	Remarque :		Ceci est une m�thode constante.
************************************************************************************/
void Videotheque::afficherVideotheque() const
{
	for (int i = 0; i < nbCoffret_; i++)
	{
		contenuVideotheque_[i]->afficherCoffret();
	}
}