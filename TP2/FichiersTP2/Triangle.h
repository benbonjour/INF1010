/**********************************************************************
/* Fichier: Triangle.h
/* Date: 22 janvier 2013
/* Auteur: Benjamin De Leener
/* Description: Définition de la classe Triangle
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
	Triangle();
    Triangle( int taille );
	Triangle( int taille, int* donnees );
    Triangle( Triangle& t );
	~Triangle();
    int getTaille();
	double poids();
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
	friend std::ostream& operator<<( std::ostream& ostr, Triangle& t );
    friend std::istream& operator>>( std::istream& is, Triangle& t );
    	 
private:
	vector< vector<int> > triangle_;
};

#endif 
