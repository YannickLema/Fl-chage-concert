#pragma hdrstop

#include "QrCode.h"
#include "SNImage.h"
#include <vector>
#include <iomanip>
#include <cmath>
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
using namespace std;
void QrCode::DetectionCarresCalibrage()
{
	Coordonnee coordhg, coordhd, coordbg, valeurDepart, valeur;
	Pixel blanc={255,255,255};
	Pixel noir={0,0,0};
	Pixel rouge={0,0,255};
	Pixel bleu={255,0,0};
	Pixel vert={0,255,0};

	//Detourer(155,155,80,80,blanc);
	SeuillerNoirBlanc(80);

	Sauvegarder("imageseuillee.bmp");
	
	//Tourner90Gauche();
	//Detourer(155,155,80,80,blanc);
	coordhg= RechercherZone(105,10,noir);
	DessinerCroix(coordhg,2,20,rouge);
	Tourner90Droite();
	coordbg=  RechercherZone(105,10,noir);
	Colorier(coordbg,10,10,bleu);
	//Tourner90Droite();
	//coordhd=  RechercherZone(100,10,noir);
	//DessinerCroix(coordhd,5,20,vert);
	Tourner90Gauche();
	coordbg=  RechercherZone(10,10,bleu);
	coordbg.ligne = coordbg.ligne + 10;
	DessinerCroix(coordbg,2,20,bleu);
	/*coordbr.ligne= 480-coordbr.ligne;
	coordbr.colonne=640-coordbr.colonne;
	centre.ligne=(coordhr.ligne+coordbr.ligne)/2;
	centre.colonne=(coordhr.colonne+coordbr.colonne)/2;
	DessinerCroix(centre,2,20,vert);  */

	cout<<"Coordonnees x croix rouge = " << coordhg.ligne <<endl;
	cout<<"Coordonnees y croix rouge = " << coordhg.colonne <<endl;
	cout<<"Coordonnees x croix bleu = " << coordbg.ligne <<endl;
	cout<<"Coordonnees y croix bleu = " << coordbg.colonne <<endl;
	float x1, y1;
	//cout<<"Premier point? ";
	//cin>>x1>>y1;
	float x2, y2;
	//cout<<"Deuxieme point? ";
	//cin>>x2>>y2;
	x1=coordhg.ligne;
	y1=coordhg.colonne;
	x2=coordbg.ligne;
	y2=coordbg.colonne;
	float dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	cout<<"La distance est de "<<dist<<endl;
	float distpix= dist/21;
	cout<<"La taille d'un pixel est de "<<distpix<<endl;
	
	Charger("imageseuillee.bmp");
	

	valeurDepart.ligne =  coordhg.ligne + distpix/2 ;
	valeurDepart.colonne = coordhg.colonne + distpix/2 ;

/*	Pixel pix1 = image[valeur1.ligne][valeur1.colonne];
	if(pix1.bleu == noir.bleu && pix1.rouge == noir.rouge && pix1.vert == noir.vert ) { cout << "1 "; }
	else { cout << "0 " << endl;}
	DessinerCroix(valeur1,2,10,bleu);
  */	
	Pixel pix1;
	int tab[21][21];
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {

			valeur.ligne = valeurDepart.ligne + (int)((float)i*distpix);
			valeur.colonne = valeurDepart.colonne + (int)((float)j*distpix);
			pix1 = image[valeur.ligne][valeur.colonne];
			if(pix1.bleu == noir.bleu && pix1.rouge == noir.rouge && pix1.vert == noir.vert ) { tab[i][j] = 1; /*cout << "1 ";*/}
			else { tab[i][j] = 0; /*cout << "0 ";*/}
			DessinerCroix(valeur,2,10,vert);
		}
	}
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			if(tab[i][j] == 0)
			{
				cout << "  ";
			}
			else 
			{
				cout << "1 ";
            }
		}
		cout << endl;
	}


/*	valeur1.ligne =  coordhg.ligne + distpix/2 + distpix ;
	valeur1.colonne = coordhg.colonne + distpix/2 ;

	Pixel pix2 = image[valeur1.ligne][valeur1.colonne];
	if(pix2.bleu == noir.bleu && pix2.rouge == noir.rouge && pix2.vert == noir.vert ) { cout << "1 "; }
	else { cout << "0 " << endl;}
	DessinerCroix(valeur1,2,10,bleu);
	
	for (int i = 0; i < 21; i++) {
	valeur1.colonne = valeur1.colonne + distpix;
	pix2 = image[valeur1.ligne][valeur1.colonne];
	if(pix2.bleu == noir.bleu && pix2.rouge == noir.rouge && pix2.vert == noir.vert ) { cout << "1 ";}
	else { cout << "0 ";}
	DessinerCroix(valeur1,2,10,bleu);  
	}
  */
	Sauvegarder("photocamseuiller.bmp");
	system("photocamseuiller.bmp");
	cin.get();
}
