#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_


#include <iostream>
#include <CImg.h>

#include <tuple>

using namespace std;
using namespace cimg_library;


class Milieu;


class Aquarium : public CImgDisplay
{

private :
   Milieu * milieu;

   int delay;

   std::tuple<float,float> plageChampAngulaireVision;
   std::tuple<float,float> plageDistanceVision;
   std::tuple<float,float> plageDistanceOuie;
   std::tuple<float,float> plageCapaciteDetectionOuie;
   std::tuple<float,float> plageCamouflage;
   float protectionCarapacemax;

   float vitesseNageoireMax;
   float probaMaxClonage;
   int seuilAvantPeurMax;

public :
   Aquarium( int width, int height, int _delay, float angleVisionMax, float angleVisionMin, float distanceVisionMax, float distanceVisionMin, float distanceOuieMin, float distanceOuieMax, float capaciteDetectionOuieMin, float capaciteDetectionOuieMax, float camouflageMin, float camouflageMax, float protectionCarapaceMax, float vitesseNageoireMax,float probaMaxClonage, int seuilAvantPeurMax);
   ~Aquarium( void );

   Milieu & getMilieu( void ) { return *milieu; }

   void run( void );

};


#endif
