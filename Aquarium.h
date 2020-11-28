#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_


#include <iostream>
#include <CImg.h>

using namespace std;
using namespace cimg_library;


class Milieu;


class Aquarium : public CImgDisplay
{

private :
   Milieu * flotte;

   int delay;

   static const tuple<float,float> plageChampAngulaireVision;
   static const tuple<float,float> plageDistanceVision;
   static const tuple<float,float> plageDistanceOuie;
   static const tuple<float,float> plageCapaciteDetectionOuie;
   static const tuple<float,float> plageCamouflage;
   static const tuple<float,float> protectionCarapacemax;

   static const float vitesseNageoireMax;
   static const float probaMaxClonage;
   static const int seuilAvantPeurMax;

public :
   Aquarium( int width, int height, int _delay );
   ~Aquarium( void );

   Milieu & getMilieu( void ) { return *flotte; }

   void run( void );

};


#endif
