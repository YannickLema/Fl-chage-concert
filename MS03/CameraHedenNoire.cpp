//---------------------------------------------------------------------------

#pragma hdrstop
#include <stdio.h>
#include "SNClientTCP.h"
#include <iostream>
#include <fstream>
#include "CameraHedenNoire.h"
#include "base64.h"

CameraHedenNoire::CameraHedenNoire(){
	strcpy(adressIP,"172.20.21.14");
	port=81;
	strcpy(identifiant,"admin");
	strcpy(motDePasse,"0000");
}

bool CameraHedenNoire::PrendrePhoto(char nomFichier[]){


	char requete[1500],donnees[1000];
	unsigned char octetLu;
	SNClientTCP monClient;
	ifstream fichierLecture;
	ofstream fichierEcriture;
	char concat[50];
	sprintf(concat,"%s:%s",identifiant,motDePasse);

	char motCode[70];
	codage64(concat, motCode);
	//cout<<"motcode "<<motCode<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
	monClient.SeConnecterAUnServeur(adressIP,port);
	sprintf(requete,"GET /snapshot.cgi?user=admin&pwd=0000&16438859156430.8734616515443281 HTTP/1.1\r\nHost: 172.20.21.13:81\r\nConnection: keep-alive\r\nCache-Control: max-age=0\r\nAuthorization: Digest %s\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.99 Safari/537.36\r\nAccept: image/avif,image/webp,image/apng,image/svg+xml,image/*,*/*;q=0.8\r\nReferer: http://172.20.21.9:81/snapshot.htm\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n\r\n",adressIP,motCode);
	monClient.Envoyer(requete,strlen(requete));
	cout<<requete<<endl;
	int nbOctetsLus;
	ofstream fichierBrute;
	fichierBrute.open("photo.brute",ios_base::binary);
	do{
		nbOctetsLus=monClient.Recevoir(donnees,1500);
		cout<<donnees<<endl;
		fichierBrute.write(donnees,nbOctetsLus);
	}
	while(nbOctetsLus>0);
	fichierBrute.close();
	monClient.SeDeconnecter();

	fichierLecture.open("photo.brute",ios_base::binary);
	fichierEcriture.open("photocam.bmp",ios_base::binary);
	bool copie = false;
	do{
		octetLu=fichierLecture.get();
		if(octetLu==0xFF){
			copie=true;
		}
		if(copie){
			fichierEcriture.put(octetLu);
		}
	}
	while(!fichierLecture.eof());


	fichierLecture.close();
	fichierEcriture.close();



	cin.get();
	return 0;

}
//---------------------------------------------------------------------------
#pragma package(smart_init)

