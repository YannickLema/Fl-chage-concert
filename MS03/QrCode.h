//---------------------------------------------------------------------------

#ifndef QRCODE_H
#define QRCODE_H
#include "SNImage.h"
//---------------------------------------------------------------------------
class QrCode : public SNImage{       // QrCode h?rite de la classe SNImage
	private:
		char fichierImage;
/*		int diametreRond;
		int diametreCible;
		Coordonnee centre;*/
		Coordonnee hautRond;
		Coordonnee basRond;
		/*int diametreImpact;
		int nbimpact;
		Coordonnee* centreImpact;
		Coordonnee* impact;
		Coordonnee cadreCible;
		int rayonPoint;
		int points;
		int nbPointsTotal;
		char dateDuTir;*/
	public:

		void DetectionCarresCalibrage();


};
#endif
