/* Fichier: main.cpp
 Noms: Benjamin Brodeur Mathieu & Julien Aymong
 Date de crÈation: 10 Janvier 2013
 Date de modification: 17 Janvier 2013
 Description: Programme de gestion des Coffrets de films. Permet de regrouper 
			  plusieurs Coffrets en Videotheque
*/

#include <iostream>
#include <string>

#include "Film.h"
#include "Coffret.h"
#include "Videotheque.h"

using namespace std;

int main()	

{
	Videotheque uneVideotheque;
	Date uneDate(1,2,3);
	Date deuxDate(4,5,6);
	Film* unFilm = new Film(4,"Twilight, chapitre IV : Révélation","Le mariage tant attendu a lieu",120, uneDate);
	Film* deuxFilm = new Film(5,"Film de marde","La suite du film de marde",121, deuxDate);
	Coffret unCoffret;

	unCoffret.ajouterFilm(unFilm);
	unCoffret.ajouterFilm(deuxFilm);

	uneVideotheque.ajouterCoffret(unCoffret);

	uneVideotheque.afficherVideotheque();


	/*
	Film unFilm;
	
	//1) Créer un objet Film(unFilm) avec constructeur par défaut ;
	Date uneDate(1, 1, 2010);

	Film unAutreFilm(2, "Tentation (New Moon)", "Il s'agit du deuxième volet de l'adaptation cinématographique de la série de romans de Stephenie Meyer", 120, uneDate);
	
	//2) Création d'un objet Film (unAutreFilm) avec constructeur par paramètre
	//Utiliser les arguments suivants : id = 2, titre = "Tentation (New Moon)", description = "Il s'agit du deuxième volet de l'adaptation cinématographique de la série de romans de Stephenie Meyer" duree 120, Date: 1/1/2010
	
	
	Date dateTwilight1(12,10,2009);
	unAutreFilm.setId(1);
	unAutreFilm.setTitre("Fascination (Twilight)");
	unAutreFilm.setDescript("Fascination est le premier roman de la saga twilight");
	unAutreFilm.setDuree(120);
	unAutreFilm.setDate(dateTwilight1);


	//3) Modifier tous les attributs du Film créée dans 1) ;
	//utilisant les arguments suivants: id =1 titre = "Fascination (Twilight)", description = "Fascination est le premier roman de la saga twilight"  et duree = 120, Date: 12/10/2009

	Film* unTableauFilm;
	unTableauFilm = new Film;
	
	//4) Allouer dynamiquement un Film utilisant le constructeur par défaut ;
	//nom de l'objet : (unFilmDynamique)
	
	uneDate.setJ(1);
	uneDate.setM(1);
	uneDate.setA(2013);
	
	Film* deuxTableauFilm;
	deuxTableauFilm = new Film (4,"Twilight, chapitre IV : Révélation","Le mariage tant attendu a lieu",120, uneDate);
	
	//5) Allouer dynamiquement une Film utilisant le constructeur par paramètres ;
	//Utiliser les arguments suivants : id = 4 ,titre = "Twilight, chapitre IV : Révélation", description = "Le mariage tant attendu a lieu"et durée = 120, , Date: 1,1,2013
	

	Date dateTwilight3(2,3,2012);
	unTableauFilm->setId(3);
	unTableauFilm->setTitre("Twilight, chapitre III : Hésitation");
	unTableauFilm->setDescript("La famille Cullen est de retour à Forks");
	unTableauFilm->setDuree(120);
	unTableauFilm->setDate(dateTwilight3);


	//6) Modifier les attributs de Film créée dans 4) ;
	//Appel des fonctions de modification l'objet unFilmDynamique
	//Utiliser les arguments suivants :id = 3, titre = "Twilight, chapitre III : Hésitation", desciption = "La famille Cullen est de retour à Forks" et duree = 120, Date: 2/3/2012

	

	
	cout<<endl<<"***************Affichage des attributs de uneFilmDynamique***************"<<endl;
	

	unTableauFilm->afficherInfoFilm();


	//7) Afficher les informations du Film créée dans 4) ;
	
	

	//Allocation dynamique d'un tableau de Films de 4 elements
	
	Film* quatreTableauFilm;
	quatreTableauFilm = new Film[4]; 

	//8) Allouer dynamiquement un tableau de 4 Films ;

	quatreTableauFilm[0] = unFilm;
	quatreTableauFilm[1] = unAutreFilm;
	quatreTableauFilm[2] = unTableauFilm[0];
	quatreTableauFilm[3] = deuxTableauFilm[0];


	//9) Remplir le tableau crée dans 8) avec les Films créées précédemment* ;

	
	cout<<endl<<"***************affichage du tableau de Films***************"<<endl;
	
	quatreTableauFilm[0].afficherInfoFilm();
	quatreTableauFilm[1].afficherInfoFilm();
	quatreTableauFilm[2].afficherInfoFilm();
	quatreTableauFilm[3].afficherInfoFilm();


	//10) Afficher les informations des Films du tableau ;	

	uneDate.setJ(1);
	uneDate.setM(1);
	uneDate.setA(2013);
	
	Coffret CoffretSagaTwilight(1, "Saga Twilight", uneDate);


	// //11) Créer un objet Coffret (CoffretSagaTwilight)
	//Utiliser l'id = 1 et le titre "Saga Twilight", Date:10/12/2012
	
	
	for(int i = 0; i < 4; i++)
	{
		CoffretSagaTwilight.ajouterFilm(quatreTableauFilm[i]);
	}

	//12) Ajouter les Films du tableau dans le Coffret ;
	//Copier les Films contenues dans le tableau tableauFilm 
	//dans l'Coffret CoffretSagaTwilight

	
	Date Taxi1Date (1,2,3), Taxi2Date(3,4,5), CoffretTaxi(02,03,2006),
		 Matrice1Date(6,7,8), Matrice2Date(9,10,11), CoffretMatrice(01,06,2001),
		 Titanic1Date(12,1,2001), Titanic2Date(23, 11,2120), CoffretTitanic(24,12,1999),
		 BackToTheFuture1Date(31, 02,2013), BackToTheFuture2Date(43,03,23), CoffretBackToTheFuture(05,06,1608),
		 Poulet1Date(21,12,2123), Poulet2Date(30, 10, 2013), CoffretPoulet(04,07,2008),
		 Dinde1Date(12,23,4094), Dinde2Date(12,39,2039), CoffretDinde(14,07,2004),
		 MCCEN1Date(2,5,2012), MCCEN2Date(10,12,2048), CoffretMMCEN(21,01,2013);


	Film Taxi1(1, "Taxi 1", "Un film avec un taxi", 90, Taxi1Date),
		 Taxi2(2, "Taxi2", "Un film avec deux taxis", 97, Taxi2Date),
		 Matrice1(23, "Matrice", "Un lapin avec une pilule bleu et une autre rouge et une fille et des effets spéciaux", 120, Matrice1Date), 
		 Matrice2(24, "Matrice Revolution", "Plus d'effets spéciaux", 123, Matrice2Date),
		 Titanic1(12, "Titanic", "un bateau coule", 600, Titanic1Date),
		 Titanic2(13, "Titanic 2", "Un autre bateau qui coule", 797, Titanic2Date),
		 BackToTheFuture1(123, "Back To The Future 1", "Un retour dans le future", 120, BackToTheFuture1Date),
		 BackToTheFuture2(124, "Back To The Future 2", "Un autre retour dans le future", 123, BackToTheFuture2Date),
		 Poulet1(3, "Poulet 1", "Un poulet s'échappe d'un azile", 10, Poulet1Date),
		 Poulet2(4, "Poulet 2", "Un poulet atteri dans un azile", 150, Poulet2Date),
		 Dinde1(5, "Dinde 1 ", "Une dinde se fait manger par un poulet", 129, Dinde1Date),
		 Dinde2(6, "Dinde 2", "Une dinde se fait manger et pousse un poulet a la demence", 120, Dinde2Date),
		 MCCEN1(7,"MCCEN", "Je ne connais pas beaucoup de film", 120, MCCEN1Date),
		 MCCEN2(8, "MCCEN2", "Ma culture cinématographique est nulle", 320, MCCEN2Date);


	Coffret Taxi(2, "Taxi", CoffretTaxi),
			Matrice(3, "La Matrice", CoffretMatrice),
			Titanic(4, "Titanic", CoffretTitanic),
			BackToTheFuture(5, "Back to the Future", CoffretBackToTheFuture),
			Poulet(6, "L'histoire de Poulet", CoffretPoulet),
			Dinde(7, "L'histoire de Dinde", CoffretDinde),
			MCCEN(8, "MCCEN", CoffretMMCEN);


	Taxi.ajouterFilm(Taxi1);
	Taxi.ajouterFilm(Taxi2);
	
	Matrice.ajouterFilm(Matrice1);
	Matrice.ajouterFilm(Matrice2);

	Titanic.ajouterFilm(Titanic1);
	Titanic.ajouterFilm(Titanic2);

	BackToTheFuture.ajouterFilm(BackToTheFuture1);
	BackToTheFuture.ajouterFilm(BackToTheFuture2);

	Poulet.ajouterFilm(Poulet1);
	Poulet.ajouterFilm(Poulet2);

	Dinde.ajouterFilm(Dinde1);
	Dinde.ajouterFilm(Dinde2);

	MCCEN.ajouterFilm(MCCEN1);
	MCCEN.ajouterFilm(MCCEN2);



	 //13 creer 7 autres coffrets de votre choix avec les films de votre choix(pour simplifier les choses, deux film par cofret)
	 
	
	cout<<endl<<"***************Afficher les Films d'un Coffret***************"<<endl;
	
	//14 Afficher les film du premier coffret crée

	Taxi.afficher();

	
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



	cout<<endl<<"*******Afficher Coffrets et Films de la Videotheque*******"<<endl;
	
	//17) Afficher les titres et les informations de tous les films de tous les Coffrets de la Videotheque ;

	maVideotheque.afficherVideotheque();
	*/

	return 0;
	
}