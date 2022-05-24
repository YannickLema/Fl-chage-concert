#include <stdio.h>
#include "SNClientTCP.h"
#include <fstream>
#include <iostream>

#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include "QrCode.h"
#include "SNImage.h"

//using namespace cv;
using namespace std;

int main()
{
	//CameraHedenNoire cam;
	//cam.PrendrePhoto("photocam.jpg");
	/*ConfigurationCamera config;
	config.AfficherConfiguration();
	config.LireConfiguration("Config.txt");
	config.AfficherConfiguration();*/
	//cin.get();
	QrCode monQrCode;
	monQrCode.Charger("photocam0.bmp");
	monQrCode.DetectionCarresCalibrage();
	//maCible.DetectionRondNoirEtCalculCentreCible();

	return 0;
}
