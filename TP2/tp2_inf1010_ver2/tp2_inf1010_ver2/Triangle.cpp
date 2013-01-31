/**********************************************************************
/* Fichier: Main.cpp
/* Date: 28 Janvier 2013
/* Auteur: Julien Aymong, Benjamin Brodeur Mathieu
/* Description: Fichier principal du TP2
************************************************************************/

#include <iostream>
using namespace std;
#include "Triangle.h"
#include <vector>

// Constructeurs et Destructeur
/************************************************************************************
*	Description :	Triangle: Triangle()
*	Paramètre :		Cette méthode est le constructeur par défaut
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Triangle::Triangle()
		:taille_(1), donnees_(new int[1])
{
	int position = 0;
	for (int i = 0; i < taille_; i++)
	{
		vector<int> rangee;
		for (int j = 0; j < i+1; j++)
		{
			rangee.push_back(donnees_[position]);
			position++;
		}
		triangle_.push_back(rangee);
	}
	 
}
/************************************************************************************
*	Description :	Triangle: Triangle(int taille)
*	Paramètre :		Cette méthode intialise la taille du triangle
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Triangle::Triangle(int taille)
{
	taille_ = taille;
	int somme = 0;

	for (int k = 0; k < taille_; k++)
	{
		somme += (k + 1);
	}

	donnees_ = new int[somme];

	int position = 0;
	for (int i = 0; i < taille_; i++)
	{
		vector<int> rangee;
		for (int j = 0; j < i+1; j++)
		{
			rangee.push_back(donnees_[position]);
			position++;
		}
		triangle_.push_back(rangee);
	}	 
}
/************************************************************************************
*	Description :	Triangle: Triangle(int taille)
*	Paramètre :		Cette méthode intialise la taille du triangle
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Triangle::Triangle(int taille, int* donnees)
{
	taille_ = taille;
	donnees_ = donnees;
	{
		int position = 0;
		for (int i = 0; i < taille_; i++)
		{
			vector<int> rangee;
			for (int j = 0; j < i+1; j++)
			{
				rangee.push_back(donnees_[position]);
				position++;
			}
			triangle_.push_back(rangee);
		}	 
	}
}
/************************************************************************************
*	Description :	Triangle: Triangle(int taille, int* donnees)
*	Paramètre :		Cette méthode intialise la taille et les donnees du triangle
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Triangle::Triangle(Triangle& t)
{
	triangle_ = t.triangle_;
	taille_ = t.taille_;

	int somme = 0;

	for (int k = 0; k < taille_; k++)
	{
		somme += (k + 1);
	}

	donnees_ = new int[somme];

	for (int i = 0; i < somme; i++)
	{
		donnees_[i] = t.donnees_[i];
	}
}
/************************************************************************************
*	Description :	Triangle:~Triangle()
*	Paramètre :		Cette méthode est le destructeur par défaut
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
// TODO
Triangle::~Triangle()
{
	delete []donnees_;
	donnees_ = 0;
}                                


// Méthode d'Accès
/************************************************************************************
*	Description :	Triangle: getTaille()
*	Paramètre :		Cette méthode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
int Triangle::getTaille()
{
	return taille_;
}


// Calcul du poids
/************************************************************************************
*	Description :	Triangle: getTaille()
*	Paramètre :		Cette méthode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
double Triangle::poids() const
{
	double poids = 0;
	double somme = 0;
	for (int i = 0; i < taille_; i++)
	{
		for (unsigned int j = 0; j < triangle_[i].size(); j++)
		{
			poids += triangle_[i][j];
		}
		poids /= (i+1);
		somme += poids;
		poids = 0;
	}
	return somme;
}

// Surchage des opérateurs J<aime pas tant ton GO
/************************************************************************************
*	Description :	Triangle: getTaille()
*	Paramètre :		Cette méthode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle& Triangle::operator=( Triangle& t )
{
	if (this != &t)
	{
		triangle_ = t.triangle_;
		taille_ = t.taille_;
	
		int somme = 0;
	
		for (int k = 0; k < taille_; k++)
		{
			somme += (k + 1);
		}
		
		delete []donnees_;
		donnees_ = new int[somme];
	
		for (int i = 0; i < somme; i++)
		{
			donnees_[i] = t.donnees_[i];
		}
	}
	return *this;
}

/************************************************************************************
*	Description :	Triangle: getTaille()
*	Paramètre :		Cette méthode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle Triangle::operator+( Triangle& t )
{
	int somme = 0;

	for (int k = 0; k < taille_; k++)
	{
		somme += (k + 1);
	}

	int* tableauResultat = new int[somme];

	for (int j = 0; j < somme; j++)
	{
		tableauResultat[j] = donnees_[j] + t.donnees_[j];
	}
	Triangle resultat(taille_, tableauResultat);

	return resultat;
}

/************************************************************************************
*	Description :	Triangle: getTaille()
*	Paramètre :		Cette méthode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle Triangle::operator*( Triangle& t )
{
	int somme = 0;

	for (int k = 0; k < taille_; k++)
	{
		somme += (k + 1);
	}

	int* tableauResultat = new int[somme];

	for (int j = 0; j < somme; j++)
	{
		tableauResultat[j] = donnees_[j] * t.donnees_[j];
	}
	Triangle resultat(taille_, tableauResultat);

	return resultat;
}

/************************************************************************************
*	Description :	Triangle: getTaille()
*	Paramètre :		Cette méthode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle Triangle::operator*( int a )
{
	int somme = 0;

	for (int k = 0; k < taille_; k++)
	{
		somme += (k + 1);
	}

	int* tableauResultat = new int[somme];

	for (int j = 0; j < somme; j++)
	{
		tableauResultat[j] = donnees_[j] * a;
	}
	Triangle resultat(taille_, tableauResultat);

	return resultat;
}

/************************************************************************************
*	Description :	Triangle: getTaille()
*	Paramètre :		Cette méthode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle& Triangle::operator+=( Triangle& t )
{
	*this = *this + t;
	return *this;
}

/************************************************************************************
*	Description :	Triangle: getTaille()
*	Paramètre :		Cette méthode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle& Triangle::operator*=( Triangle& t )
{
	*this = *this * t;
	return *this;
}

/************************************************************************************
*	Description :	Triangle: getTaille()
*	Paramètre :		Cette méthode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle& Triangle::operator*=( int a )
{
	*this = *this * a;
	return *this;
}

/************************************************************************************
*	Description :	Triangle: getTaille()
*	Paramètre :		Cette méthode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
bool Triangle::operator<( Triangle& t )
{
	if (this->poids() < t.poids())
		return true;
	else
		return false;
}

/************************************************************************************
*	Description :	Triangle: getTaille()
*	Paramètre :		Cette méthode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
bool Triangle::operator>( Triangle& t )
{
	if (this->poids() > t.poids())
		return true;
	else
		return false;
}

/************************************************************************************
*	Description :	Triangle: getTaille()
*	Paramètre :		Cette méthode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
bool Triangle::operator==( Triangle& t )
{
	if (this->poids() == t.poids())
		return true;
	else
		return false;
}












// Fonction ami
/************************************************************************************
*	Description :	friend std::ostream&
*	Paramètre :		Cette méthode permet d'afficher les informations voulu
*	Valeur de retour : ostream&
*	Remarque :		Aucune
************************************************************************************/
std::ostream& operator<<( std::ostream& ostr, Triangle& t )
{
	for (int i = 0; i < t.taille_; i++)
	{
		for (int j = 0; j < t.triangle_[i].size(); j++)
		{
			ostr << t.triangle_[i][j];
			ostr << " ";
		}
		ostr << endl;
	}
	ostr << endl;
	return ostr;
}

/************************************************************************************
*	Description :	friend std::istream&
*	Paramètre :		Cette méthode permet d'afficher les informations voulu
*	Valeur de retour : ostream&
*	Remarque :		Aucune
************************************************************************************/
std::istream& operator>>( std::istream& is, Triangle& t )
{
	int i=0, j=0;
	cout << "Indiquez les coordonnees de la valeur a modifier en x et y, puis la nouvelle valeur" << endl;
	cin >> i;
	cin >> j;
	cin >> t.triangle_[i][j];
	return is;
}