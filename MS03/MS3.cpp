#include <stdio.h>
#include "SNClientTCP.h"
#include "CameraHedenNoire.h"
#include "ConfigurationCamera.h"
#include <fstream>

/* #include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>*/
#include <iostream>

#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include "Cible.h"
#include "SNImage.h"

//using namespace cv;
using namespace std;

int main()
{
	CameraHedenNoire cam;
	cam.PrendrePhoto("photocam.bmp");
	/*ConfigurationCamera config;
	config.AfficherConfiguration();
	config.LireConfiguration("Config.txt");
	config.AfficherConfiguration();*/
	cin.get();
	Cible maCible;
	maCible.Charger("photocam.bmp");
	/*maCible.DetectionRondNoirEtCalculCentreCible();
	void display(Mat &im, Mat &bbox)
	{
	  int n = bbox.rows;
	  for(int i = 0 ; i < n ; i++)
	  {
		line(im, Point2i(bbox.at<float>(i,0),bbox.at<float>(i,1)), Point2i(bbox.at<float>((i+1) % n,0), bbox.at<float>((i+1) % n,1)), Scalar(255,0,0), 3);
	  }
	  imshow("Result", im);
	}

	int main(int argc, char* argv[])
	{
	  // Read image
	  Mat inputImage;
	  if(argc>1)
		inputImage = imread(argv[1]);
	  else
		inputImage = imread("qrcode-learnopencv.jpg");

	  QRCodeDetector qrDecoder;

	  Mat bbox, rectifiedImage;

	  std::string data = qrDecoder.detectAndDecode(inputImage, bbox, rectifiedImage);
	  if(data.length()>0)
	  {
		cout << "Decoded Data : " << data << endl;

		display(inputImage, bbox);
		rectifiedImage.convertTo(rectifiedImage, CV_8UC3);
		imshow("Rectified QRCode", rectifiedImage);

		waitKey(0);
	  }
	  else
		cout << "QR Code not detected" << endl;
	}   */

	return 0;
}
