/************************************************************************************
*	Fichier					: Film.h
*	Auteur					: 
*	Description				: Definition de la classe Film
*	Date de cr»ation		: 10 Janvier 2013
*	Date de modification	: 
************************************************************************************/


#ifndef FILM_H
#define FILM_H

#include<string>
#include<iostream>

#include"Date.h"

using namespace std;

class Film
{
public:
	Film();
	Film(unsigned int id, string titre, string descript, unsigned int duree, Date acquisition);
	~Film();

	void setId(unsigned int id);
	void setTitre(string titre);
	void setDescript(string descript);
	void setDuree(unsigned int duree);
	void setDate(Date acquisition);

	unsigned int getId()const;
	string getTitre()const;
	string getDescript()const;
	unsigned int getDuree()const;
	Date getDate()const;

	void afficherInfoFilm()const;


private:
	unsigned int identifiant_;
	string titre_;
	string description_;
	unsigned int duree_;
	Date date_;
};

#endif // FILM_H