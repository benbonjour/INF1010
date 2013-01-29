/**********************************************************************
/* Fichier: Triangle.h
/* Date: 22 janvier 2013
/* Auteur: Benjamin De Leener
/* Description: D�finition de la classe Triangle
************************************************************************/

#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

class Triangle
{
 
public:
	// Constructeurs et Destructeur
	Triangle();                                     // par d�fault
    Triangle( int taille );                         // par taille
	Triangle( int taille, int* donnees );           // par taille et donnees
    Triangle( Triangle& t );                        // par copie
	~Triangle();                                    // Destructeur

	// M�thode d'Acc�s 
    int getTaille();
	
	// Calcul du poid
	double poids();

	// Surcharge des op�rateurs
	vector<int>& operator[]( int i );
    Triangle& operator=( Triangle& t );
    Triangle operator+( Triangle& t );
    Triangle operator*( Triangle& t );
	Triangle operator*( int a );
    Triangle& operator+=( Triangle& t );
    Triangle& operator*=( Triangle& t );
	Triangle& operator*=( int a );
	bool operator<( Triangle& t );
    bool operator>( Triangle& t );
	bool operator==( Triangle& t );

	// Fonction amis (op�rateurs d'extraction in d'insertion)
	friend std::ostream& operator<<( std::ostream& ostr, Triangle& t );
    friend std::istream& operator>>( std::istream& is, Triangle& t );
    	 
private:
	vector< vector<int> > triangle_;
	int taille_;
	int* donnees_;

};

#endif 
