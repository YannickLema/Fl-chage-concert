//---------------------------------------------------------------------------

#pragma hdrstop
#include <stdio.h>
#include <SNClientTCP.h>
#include <iostream>
#include <fstream>
#include "base64.h"
#include "ConfigurationCamera.h"
using namespace std;

ConfigurationCamera::ConfigurationCamera(){
	strcpy(adressIP,"0.0.0.0");
	port=0;
	strcpy(identifiant,"admin");
	strcpy(motDePasse,"");

}

void ConfigurationCamera::AfficherConfiguration(){
	cout<<"Adresse IP:"<<adressIP<<endl;
	cout<<"Port:"<<port<<endl;
	cout<<"Identifiant:"<<identifiant<<endl;
	cout<<"Mot de passe:"<<motDePasse<<endl;
}

void ConfigurationCamera::LireConfiguration(const char*fichier){
	char texte[20];
	ifstream fichierConfig;
	fichierConfig.open(fichier);
	fichierConfig>>texte>>adressIP;
	fichierConfig>>texte>>port;
	fichierConfig>>texte>>identifiant;
	fichierConfig>>texte>>motDePasse;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
