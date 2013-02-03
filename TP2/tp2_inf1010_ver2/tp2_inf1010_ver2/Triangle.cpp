/**********************************************************************
/* Fichier: Triangle.cpp
/* Date: 28 Janvier 2013
/* Auteur: Julien Aymong, Benjamin Brodeur Mathieu
/* Description: Impl�mentation de la classe Triangle
************************************************************************/

#include <iostream>
using namespace std;
#include "Triangle.h"
#include <vector>

// Constructeurs et Destructeur
/************************************************************************************
*	Description :	Triangle::Triangle()
*	Param�tre :		Cette m�thode est le constructeur par d�faut
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Triangle::Triangle()
		:taille_(1), donnees_(new int[1])
{
	int position = 0;
	for (int i = 0; i < taille_; i++)	// Pour chaque rang�es
	{
		vector<int> rangee;
		for (int j = 0; j < i+1; j++)
		{
			rangee.push_back(donnees_[position]); //On initialise les rang�es avec des 
			position++;                           //valeurs quelconques
		}
		triangle_.push_back(rangee);
	}
	 
}
/************************************************************************************
*	Description :	Triangle::Triangle(int taille)
*	Param�tre :		Cette m�thode intialise la taille du triangle lors de �a construction.
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Triangle::Triangle(int taille)
{
	taille_ = taille;
	
	//---Calcul du nombre de valeurs contenues dans le triangle---//
	int somme = grandeurTableau(taille_);
	
	donnees_ = new int[somme]; // Initialisation du tableau dynamique de la bonne taille

	int position = 0;
	for (int i = 0; i < taille_; i++) // Pour chaque rang�e
	{
		vector<int> rangee;
		for (int j = 0; j < i+1; j++)
		{
			rangee.push_back(donnees_[position]); //On initialise des valeurs quelconques
			position++;
		}
		triangle_.push_back(rangee);
	}	 
}
/************************************************************************************
*	Description :	Triangle::Triangle(int taille, int* donnees)
*	Param�tre :		Cette m�thode intialise la taille du triangle ainsi que les
*					valeurs qu'il contient.
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Triangle::Triangle(int taille, int* donnees)
{
	taille_ = taille;
	donnees_ = donnees;
	{
		int position = 0;
		for (int i = 0; i < taille_; i++) // Pour chaque rang�es
		{
			vector<int> rangee;
			for (int j = 0; j < i+1; j++)
			{
				rangee.push_back(donnees_[position]); // On remplie le bon nombre de case 
				position++;                           // avec les bonnes valeurs
			}
			triangle_.push_back(rangee);
		}	 
	}
}
/************************************************************************************
*	Description :	Triangle::Triangle(Triangle& t)
*	Param�tre :		Cette m�thode initialise un triangle par copie
*	Valeur de retour : -
*	Remarque :		Il y a deep copy du vecteur.
************************************************************************************/
Triangle::Triangle(Triangle& t)
{
	triangle_ = t.triangle_;
	taille_ = t.taille_;

	//----- Calcul du nombre de valeur du triangle -------//
	int somme = grandeurTableau(taille_);

	donnees_ = new int[somme]; // Cr�ation d'un tableau de la bonne taille

	for (int i = 0; i < somme; i++)
	{
		donnees_[i] = t.donnees_[i]; // Copie donn�e par donn�e dans le tableau.
	}
}
/************************************************************************************
*	Description :	Triangle::~Triangle()
*	Param�tre :		Cette m�thode est le destructeur par d�faut
*	Valeur de retour : -
*	Remarque :		Aucune
************************************************************************************/
Triangle::~Triangle()
{
	delete []donnees_; // D�salloue le tableau allou� dynamiquement
	donnees_ = 0;
}                                


// M�thode d'Acc�s
/************************************************************************************
*	Description :	Triangle::getTaille() const
*	Param�tre :		Cette m�thode retourne la taille du Triangle
*	Valeur de retour : INT taille du triangle
*	Remarque :		Aucune
************************************************************************************/
int Triangle::getTaille() const
{
	return taille_;
}


// Calcul du poids
/************************************************************************************
*	Description :	Triangle::poids() const
*	Param�tre :		Cette m�thode retourne la taille du Triangle
*	Valeur de retour : Double repr�sente le "poids" du triangle
*	Remarque :		Aucune
************************************************************************************/
double Triangle::poids() const
{
	double poids = 0;
	double somme = 0;
	
	for (int i = 0; i < taille_; i++) // pour chaque rang�e du triangle
	{
		for (unsigned int j = 0; j < triangle_[i].size(); j++) // Pour chaque valeur
		{
			poids += triangle_[i][j]; // on incr�mente le poids (de la rang�e)
		}
		
		poids /= (i+1); // on divise le poids de la rang�e par 1/n
		somme += poids; // on additionne le poid total
		poids = 0;		// on initialise le poid de la rang�e pour la rang�e suivante
	}
	return somme; // on retourne le poids
}

// Surchage des op�rateurs
/************************************************************************************
*	Description :	Triangle::operator[]( int i ) const
*	Param�tre :		Cette m�thode permet d'acc�der � un �l�ment pr�cis dans le vecteur
*	Valeur de retour : vector<int>& la valeur stock� dans le vecteur � la position i
*	Remarque :		Aucune
************************************************************************************/
vector<int>& Triangle::operator[]( int i )
{
    return triangle_[i];
}

/************************************************************************************
*	Description :	Triangle::operator=( Triangle& t )
*	Param�tre :		Cette m�thode �galise tous le contenue du triangle de gauche avec
*					celui de droite.
*	Valeur de retour : Triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle& Triangle::operator=( Triangle& t )
{
	if (this != &t) // On v�rifie qu'il ne s'agit pas d'une copie avec soi-m�me
	{
		triangle_ = t.triangle_; // deep copy des vecteurs
		taille_ = t.taille_;	 // on passe la taille
	
		//---Calcul de la taille du triangle---//
		int somme = grandeurTableau(taille_);
		
		delete []donnees_;
		donnees_ = new int[somme];
	
		for (int i = 0; i < somme; i++)
		{
			donnees_[i] = t.donnees_[i]; // on copy une � une les donn�es
		}
	}
	return *this; // on retourne le triangle de gauche
}

/************************************************************************************
*	Description :	 Triangle::operator+( Triangle& t ) const
*	Param�tre :		Cette m�thode retourne un triangle dont les valeurs repr�sentent
*					la somme de deux triangles
*	Valeur de retour : Triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle Triangle::operator+( Triangle& t )
{
	//----- Calcul du nombre de donn�es du triangle -----//
	int somme = grandeurTableau(taille_);

	int* tableauResultat = new int[somme]; // Allocation dynamique d'un tableau de la bonne taille.

	for (int j = 0; j < somme; j++)
	{
		tableauResultat[j] = donnees_[j] + t.donnees_[j]; // On additionne les valeurs correspondantes des deux triangles en argument 
	}
	
	Triangle resultat(taille_, tableauResultat); // On cr�er le nouveau triangle

	return resultat; // qu'on retourne
}

/************************************************************************************
*	Description :	Triangle::operator*( Triangle& t ) const
*	Param�tre :		Cette m�thode retourne un triangle dont les valeur sont le 
*					r�sultat de la multiplication des valeurs correspondantes de deux
*					triangles.
*	Valeur de retour : Triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle Triangle::operator*( Triangle& t )
{
	//---Calcul du nombre de donn�es du triangle---//
	int somme = grandeurTableau(taille_);

	int* tableauResultat = new int[somme]; // Allocation dynamique d'un tableau de la bonne taille.

	for (int j = 0; j < somme; j++)
	{
		tableauResultat[j] = donnees_[j] * t.donnees_[j]; // On multiplie les valeurs correspondantes des deux triangles en arguments
	}
	Triangle resultat(taille_, tableauResultat); // On cr�er un nouveau triangle r�sultat

	return resultat; // On retourne le triangle r�sultat}
}

/************************************************************************************
*	Description :	Triangle::operator*( int a ) const 
*	Param�tre :		Cette m�thode retourne un triangle ou chaque valeur ont �t� multipli�es
*					par une constante a
*	Valeur de retour : Triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle Triangle::operator*( int a )
{
	//---Calcul du nombre de donn�es du triangle---//
	
	int somme = grandeurTableau(taille_);

	int* tableauResultat = new int[somme]; // Allocation dynamique d'un tableau de la bonne taille.

	for (int j = 0; j < somme; j++)
	{
		tableauResultat[j] = donnees_[j] * a; // On multiplie les valeurs du triangle par a
	}
	Triangle resultat(taille_, tableauResultat); // On cr�er un triangle r�sultat contenant les bonnes valeurs

	return resultat; // On retourne le triangle contenant les bonnes valeurs
}

/************************************************************************************
*	Description :	Triangle::operator+=( Triangle& t )
*	Param�tre :		Cette m�thode retourne un triangle dont les valeurs ont �t� incr�ment�es
*					par les valeurs correspondantes d'un autre triangle.
*	Valeur de retour : Triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle& Triangle::operator+=( Triangle& t )
{
	*this = *this + t; // on additionne gr�ce � l'op�rateur d'addition les valeurs des 
	return *this;	   // deux triangles.
}

/************************************************************************************
*	Description :	Triangle::operator*=( Triangle& t )
*	Param�tre :		Cette m�thode retourne un triangle dont les valeurs ont �t� multipli�es
*					par les valeurs correspondantes d'un autre triangle.
*	Valeur de retour : Triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle& Triangle::operator*=( Triangle& t )
{
	*this = *this * t; // on multiplie gr�ce � l'op�rateur de multiplication les valeurs
	return *this;	   // des deux triangles.
}

/************************************************************************************
*	Description :	Triangle::operator*=( int a )
*	Param�tre :		Cette m�thode retourne un triangle dont les valeurs ont �t� multipli�es
*					par un constante a.
*	Valeur de retour : Triangle
*	Remarque :		Aucune
************************************************************************************/
Triangle& Triangle::operator*=( int a )
{
	*this = *this * a; // on multiplie gr�ce � l'op�rateur de multiplication les valeurs
	return *this;      // des deux triangles.
}

/************************************************************************************
*	Description :	Triangle::operator<( Triangle& t ) const
*	Param�tre :		Cette m�thode v�rifie que le poids du triangle de gauche est 
*					inf�rieur � celui du triangle de droite.
*	Valeur de retour : Bool
*	Remarque :		Aucune
************************************************************************************/
bool Triangle::operator<( Triangle& t ) const
{
	if (this->poids() < t.poids())
		return true;
	else
		return false;
}

/************************************************************************************
*	Description :	Triangle::operator>( Triangle& t ) const
*	Param�tre :		Cette m�thode v�rifie que le poids du triangle de gauche est 
*					sup�rieur � celui du triangle de droite.
*	Valeur de retour : Bool
*	Remarque :		Aucune
************************************************************************************/
bool Triangle::operator>( Triangle& t ) const
{
	if (this->poids() > t.poids())
		return true;
	else
		return false;
}

/************************************************************************************
*	Description :	Triangle::operator==( Triangle& t ) const
*	Param�tre :		Cette m�thode v�rifie que le poids du triangle de gauche est 
*					�gal � celui du triangle de droite.
*	Valeur de retour : Bool
*	Remarque :		Aucune
************************************************************************************/
bool Triangle::operator==( Triangle& t ) const
{
	if (this->poids() == t.poids())
		return true;
	else
		return false;
}

// Fonction ami
/************************************************************************************
*	Description :	friend std::ostream&
*	Param�tre :		Cette m�thode permet d'afficher les informations gr�ce � l'op�rateur 
*	Valeur de retour : ostream&
*	Remarque :		Aucune
************************************************************************************/
std::ostream& operator<<( std::ostream& ostr, Triangle& t )
{
	for (int i = 0; i < t.taille_; i++) // pour chaque rang�e
	{
		for (unsigned int j = 0; j < t.triangle_[i].size(); j++)
		{
			ostr << t.triangle_[i][j]; // On affiche toutes les valeurs
			ostr << " "; // s�par�es par un espace
		}
		ostr << endl; // On fait un saute de ligne apr�s chaque rang�e
	}
	ostr << endl; // un saut de ligne apr�s l'affichage du triangle
	return ostr;
}

/************************************************************************************
*	Description :	friend std::istream&
*	Param�tre :		Cette m�thode permet d'ins�rer des valeurs dans le triangle aux 
*					endroits voulus. 
*	Valeur de retour : ostream&
*	Remarque :		Il est n�cessaire de suivre les instructions.
*					Le premier �l�ment d'une rang�e/colonne est � la position 0.
*					Ainsi, si l'on veut modifier le premier �l�ment du triangle, les
*					coordonn�es seraient 0 en x et 0 en y.
************************************************************************************/
std::istream& operator>>( std::istream& is, Triangle& t )
{
	int i=0, j=0, valeur=0;
	cout << "Indiquez les coordonnees de la valeur a modifier en x et y, puis la nouvelle valeur" << endl;
	cout << "Coordonnees en x : ";
	cin >> i;
	cout << "Coordonnees en y : ";
	cin >> j;
	cout << "Valeur a inserer : ";
	cin >> valeur;
	t.triangle_[i][j] = valeur;
	
	//---Calcul de la position dans le tableau dynamique pour y ins�rer la valeur---//
	int somme = 0;
	for (int k = 0; k < i; k++)
	{
		somme += (k + 1);
	}
	somme = somme + j;

	t.donnees_[somme] = valeur;
	
	return is;
}

// Fonction privee (de calcul du nombre de donnees du triangle pour le tableau)
/************************************************************************************
*	Description :	Triangle::grandeurTableau( int taille) const
*	Param�tre :		Cette m�thode permet de calculer le nombre de valeurs qui sont
*					contenues dans le triangle
*	Valeur de retour : INT nombre d'�l�ments dans le triangle
*	Remarque :		Aucune
************************************************************************************/
int Triangle::grandeurTableau( int taille) const
{
	int somme = 0;

	for (int k = 0; k < taille_; k++)
	{
		somme += (k + 1);
	}

	return somme;
}