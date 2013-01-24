/************************************************************************************
*	Fichier					: Film.cpp
*	Auteur					: 
*	Description				: Definition de la classe Film
*	Date de crÈation		:
*	Date de modification	: 
************************************************************************************/
#include <iostream>
#include <string>

#include"Film.h"
#include"Date.h"

using namespace std;

/************************************************************************************
*	Description :
*	Paramètre :
*	Valeur de retour :
*	Remarque :
************************************************************************************/
Film::Film()
{
	identifiant_ = 0;
	titre_ = "*vide*";
	description_ = "*vide*";
	duree_ = 0;
	date_ = Date();
}

Film::Film(unsigned int id, string titre, string descript, unsigned int duree, Date acquisition)
	:identifiant_(id), titre_(titre), description_(descript), duree_(duree), date_(acquisition)
{

}

Film::~Film()
{

}

void Film::setId(unsigned int id)
{
	identifiant_ = id;
}

void Film::setTitre(string titre)
{
	titre_ = titre;
}

void Film::setDescript(string descript)
{
	description_ = descript;
}

void Film::setDuree(unsigned int duree)
{
	duree_ = duree;
}

void Film::setDate(Date acquisition)
{
	date_ = acquisition;
}


unsigned int Film::getId()const
{
	return identifiant_;
}

string Film::getTitre()const
{
	return titre_;
}

string Film::getDescript()const
{
	return description_;
}

unsigned int Film::getDuree()const
{
	return duree_;
}

Date Film::getDate()const
{
	return date_;
}

void Film::afficherInfoFilm()const
{
	cout << "Identifiant : " << getId() << endl;
	cout << "Titre du film : " << getTitre() << endl;
	cout << "Description du film : " << getDescript() << endl;
	cout << "Durée du film : " << getDuree() << endl;
	cout << "Date d'acquisition : ";
	date_.afficheDate();
	cout << endl;
}