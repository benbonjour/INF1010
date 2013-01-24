/* Fichier: main.cpp
 Noms: 
 Date de crÈation: 10 Janvier 2013
 Date de modification: 
 Description: Programme de gestion des Coffrets de films. Permet de regrouper 
			  plusieurs Coffrets en Videotheque
*/

#include <iostream>
#include <string>
#include "Film.h"
#include "Coffret.h"
#include "Videotheque.h"

// Vérification pour les fuites de mémoires
#define _CRTDBG_MAP_ALLOC // Utilise les allocations avec débogage.
#include <stdlib.h>
#include <crtdbg.h>
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ ) // Ajoute le numéro de ligne au rapport de fuites.

using namespace std;

int main()	

{
	// Vérification pour les fuites de mémoires
	_CrtSetDbgFlag(0
	| _CRTDBG_ALLOC_MEM_DF    // Débogage d'allocation mémoire.
	| _CRTDBG_LEAK_CHECK_DF   // Rapport de fuites à la sortie du programme.
	| _CRTDBG_CHECK_ALWAYS_DF // Vérifie la corruption à chaque new/delete (lent).
	);

	//1) Créer un objet Film(unFilm) avec constructeur par défaut ;
	Film unFilm;
	
	//2) Création d'un objet Film (unAutreFilm) avec constructeur par paramètre
	//Utiliser les arguments suivants : id = 2, titre = "Tentation (New Moon)", description = "Il s'agit du deuxième volet de l'adaptation cinématographique de la série de romans de Stephenie Meyer" duree 120, Date: 1/1/2010
	Date uneDate(1, 1, 2010);
	Film* unAutreFilm = new Film(2, "Tentation (New Moon)", "Il s'agit du deuxieme volet de l'adaptation cinematographique de la serie de romans de Stephenie Meyer", 120, uneDate);
	
	//3) Modifier tous les attributs du Film créée dans 1) ;
	//utilisant les arguments suivants: id =1 titre = "Fascination (Twilight)", description = "Fascination est le premier roman de la saga twilight"  et duree = 120, Date: 12/10/2009
	Date dateTwilight1(12,10,2009);
	unFilm.setId(1);
	unFilm.setTitre("Fascination (Twilight)");
	unFilm.setDescript("Fascination est le premier roman de la saga Twilight");
	unFilm.setDuree(120);
	unFilm.setDate(dateTwilight1);

	//4) Allouer dynamiquement un Film utilisant le constructeur par défaut ;
	//nom de l'objet : (unFilmDynamique)
	Film* unTableauFilm = new Film;
	
	//5) Allouer dynamiquement une Film utilisant le constructeur par paramètres ;
	//Utiliser les arguments suivants : id = 4 ,titre = "Twilight, chapitre IV : Révélation", description = "Le mariage tant attendu a lieu"et durée = 120, , Date: 1,1,2013
	uneDate.setJ(1);
	uneDate.setM(1);
	uneDate.setA(2013);
	Film* deuxTableauFilm = new Film(4,"Twilight, chapitre IV : Revelation","Le mariage tant attendu a lieu",120, uneDate);
	
	//6) Modifier les attributs de Film créée dans 4) ;
	//Appel des fonctions de modification l'objet unFilmDynamique
	//Utiliser les arguments suivants :id = 3, titre = "Twilight, chapitre III : Hésitation", desciption = "La famille Cullen est de retour à Forks" et duree = 120, Date: 2/3/2012	
	Date dateTwilight3(2,3,2012);
	unTableauFilm->setId(3);
	unTableauFilm->setTitre("Twilight, chapitre III : Hesitation");
	unTableauFilm->setDescript("La famille Cullen est de retour a Forks");
	unTableauFilm->setDuree(120);
	unTableauFilm->setDate(dateTwilight3);


	//Première section terminée
	cout<<endl<<"***************Affichage des attributs de uneFilmDynamique***************"<<endl;
	

	//7) Afficher les informations du Film créée dans 4) ;
	unTableauFilm->afficherInfoFilm();

	//8) Allouer dynamiquement un tableau de 4 Films ;
	//Allocation dynamique d'un tableau de Films de 4 elements
	Film* quatreTableauFilm;
	quatreTableauFilm = new Film[4]; 

	//9) Remplir le tableau crée dans 8) avec les Films créées précédemment* ;
	Film* unFilmPointe = new Film;	// Ces deux instructions supplémentaires sont nécessaires. En effet, en incluant un élément non-alloué dynamiquement dans le tableau cause une erreur lors de l'appel du destructeur de ce dernier, puisqu'il tente de désallouer une mémoire qu'il n'a pas été alloué dynamiquement.
	*unFilmPointe = unFilm;			// Ainsi, nous créons un nouveau film pointeur avec les mêmes informations que le film statique pour l'inclure dans le tableau dynamique.
	
	quatreTableauFilm[0] = *unFilmPointe;
	quatreTableauFilm[1] = *unAutreFilm;
	quatreTableauFilm[2] = *unTableauFilm;
	quatreTableauFilm[3] = *deuxTableauFilm;

	
	// Deuxième section terminée
	cout<<endl<<"***************affichage du tableau de Films***************"<<endl;
	

	//10) Afficher les informations des Films du tableau ;
	quatreTableauFilm[0].afficherInfoFilm();
	quatreTableauFilm[1].afficherInfoFilm();
	quatreTableauFilm[2].afficherInfoFilm();
	quatreTableauFilm[3].afficherInfoFilm();

	// //11) Créer un objet Coffret (CoffretSagaTwilight)
	//Utiliser l'id = 1 et le titre "Saga Twilight", Date:10/12/2012
	uneDate.setJ(1);
	uneDate.setM(1);
	uneDate.setA(2013);
	Coffret* CoffretSagaTwilight = new Coffret(1, "Saga Twilight", uneDate);

	//12) Ajouter les Films du tableau dans le Coffret ;
	//Copier les Films contenues dans le tableau tableauFilm 
	//dans l'Coffret CoffretSagaTwilight
	CoffretSagaTwilight->ajouterFilmCoffret(unFilmPointe);
	CoffretSagaTwilight->ajouterFilmCoffret(unAutreFilm);
	CoffretSagaTwilight->ajouterFilmCoffret(unTableauFilm);
	CoffretSagaTwilight->ajouterFilmCoffret(deuxTableauFilm);

	//13 creer 7 autres coffrets de votre choix avec les films de votre choix(pour simplifier les choses, deux film par cofret)
	// Création des dates pour les films et coffrets
	Date Taxi1Date(1,2,3), Taxi2Date(3,4,5), CoffretTaxi(02,03,2006),
		 Matrice1Date(6,7,8), Matrice2Date(9,10,11), CoffretMatrice(01,06,2001),
		 Titanic1Date(12,1,2001), Titanic2Date(23, 11,2120), CoffretTitanic(24,12,1999),
		 BackToTheFuture1Date(31, 02,2013), BackToTheFuture2Date(43,03,23), CoffretBackToTheFuture(05,06,1608),
		 Poulet1Date(21,12,2123), Poulet2Date(30, 10, 2013), CoffretPoulet(04,07,2008),
		 Dinde1Date(12,23,4094), Dinde2Date(12,39,2039), CoffretDinde(14,07,2004),
		 MCCEN1Date(2,5,2012), MCCEN2Date(10,12,2048), CoffretMMCEN(21,01,2013);

	// Création des films (2 par coffrets)
	Film* Taxi1 = new Film(1, "Taxi 1", "Un film avec un taxi", 90, Taxi1Date);
	Film* Taxi2 = new Film(2, "Taxi2", "Un film avec deux taxis", 97, Taxi2Date);
	Film* Matrice1 = new Film(23, "Matrice", "Un lapin avec une pilule bleu et une autre rouge et une fille et des effets speciaux", 120, Matrice1Date); 
	Film* Matrice2 = new Film(24, "Matrice Revolution", "Plus d'effets speciaux", 123, Matrice2Date);
	Film* Titanic1 = new Film(12, "Titanic", "un bateau coule", 600, Titanic1Date);
	Film* Titanic2 = new Film(13, "Titanic 2", "Un autre bateau qui coule", 797, Titanic2Date);
	Film* BackToTheFuture1 = new Film(123, "Back To The Future 1", "Un retour dans le future", 120, BackToTheFuture1Date);
	Film* BackToTheFuture2 = new Film(124, "Back To The Future 2", "Un autre retour dans le future", 123, BackToTheFuture2Date);
	Film* Poulet1 = new Film(3, "Poulet 1", "Un poulet s'echappe d'un asile", 10, Poulet1Date);
	Film* Poulet2 = new Film(4, "Poulet 2", "Un poulet atteri dans un asile", 150, Poulet2Date);
	Film* Dinde1 = new Film(5, "Dinde 1 ", "Une dinde se fait manger par un poulet", 129, Dinde1Date);
	Film* Dinde2 = new Film(6, "Dinde 2", "Une dinde se fait manger et pousse un poulet a la demence", 120, Dinde2Date);
	Film* MCCEN1 = new Film(7,"MCCEN", "Je ne connais pas beaucoup de film", 120, MCCEN1Date);
	Film* MCCEN2 = new Film(8, "MCCEN2", "Ma culture cinematographique est nulle", 320, MCCEN2Date);

	// Création des coffrets
	Coffret* Taxi = new Coffret(2, "Taxi", CoffretTaxi);
	Coffret* Matrice = new Coffret(3, "La Matrice", CoffretMatrice);
	Coffret* Titanic = new Coffret(4, "Titanic", CoffretTitanic);
	Coffret* BackToTheFuture = new Coffret(5, "Back to the Future", CoffretBackToTheFuture);
	Coffret* Poulet = new Coffret(6, "L'histoire de Poulet", CoffretPoulet);
	Coffret* Dinde = new Coffret(7, "L'histoire de Dinde", CoffretDinde);
	Coffret* MCCEN = new Coffret(8, "MCCEN", CoffretMMCEN);

	//Ajouts des films par coffret
	Taxi->ajouterFilmCoffret(Taxi1);
	Taxi->ajouterFilmCoffret(Taxi2);
	
	Matrice->ajouterFilmCoffret(Matrice1);
	Matrice->ajouterFilmCoffret(Matrice2);

	Titanic->ajouterFilmCoffret(Titanic1);
	Titanic->ajouterFilmCoffret(Titanic2);

	BackToTheFuture->ajouterFilmCoffret(BackToTheFuture1);
	BackToTheFuture->ajouterFilmCoffret(BackToTheFuture2);

	Poulet->ajouterFilmCoffret(Poulet1);
	Poulet->ajouterFilmCoffret(Poulet2);

	Dinde->ajouterFilmCoffret(Dinde1);
	Dinde->ajouterFilmCoffret(Dinde2);

	MCCEN->ajouterFilmCoffret(MCCEN1);
	MCCEN->ajouterFilmCoffret(MCCEN2);
 

	// Troisième section terminée
	cout<<endl<<"***************Afficher les Films d'un Coffret***************"<<endl;
	

	//14 Afficher les film du premier coffret crée
	Taxi->afficherCoffret();

	// 15) Créer un objet Videotheque ;
	//Creation d'une Videotheque (maVideotheque)
	Videotheque maVideotheque;

	//16) Ajouter tous les coffrets crées précédemment à la Videotheque
	maVideotheque.ajouterCoffret(CoffretSagaTwilight);
	maVideotheque.ajouterCoffret(Taxi);
	maVideotheque.ajouterCoffret(Matrice);
	maVideotheque.ajouterCoffret(Titanic);
	maVideotheque.ajouterCoffret(BackToTheFuture);
	maVideotheque.ajouterCoffret(Poulet);
	maVideotheque.ajouterCoffret(Dinde);
	maVideotheque.ajouterCoffret(MCCEN);


	// Quatrième section terminée
	cout<<endl<<"*******Afficher Coffrets et Films de la Videotheque*******"<<endl;
	

	//17) Afficher les titres et les informations de tous les films de tous les Coffrets de la Videotheque ;
	maVideotheque.afficherVideotheque();
	

	//Fin du programme
	return 0;
	
}