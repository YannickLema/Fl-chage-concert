//---------------------------------------------------------------------------

#ifndef CameraHedenNoireH
#define CameraHedenNoireH
//---------------------------------------------------------------------------
class CameraHedenNoire{

private:
	 char adressIP[20];
	 unsigned short port;
	 char identifiant[30];
	 char motDePasse[30];

public:
	CameraHedenNoire();
	bool PrendrePhoto(char * monFichier);
	void Deplacer(int commande);
};


#endif


