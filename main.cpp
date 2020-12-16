#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{
   float angleVisionMax = M_PI;
   float angleVisionMin = 0.;
   float distanceVisionMax = 10.;
   float distanceVisionMin = 2.;
   float distanceOuieMin = 10.;
   float distanceOuieMax = 25.;
   float capaciteDetectionOuieMin = 0.2; // dans [0,1]
   float capaciteDetectionOuieMax = 0.8;
   float camouflageMin = 0.; // dans [0,1]
   float camouflageMax = 0.;
   float protectionCarapaceMax = 1.; // >1
   float vitesseNageoireMax = 1.; //>1
   float probaMaxClonage = 0.00005; // dans [0,1]
   int seuilAvantPeurMax = 5;
   float probaMaxDecesCollision = 1; //dans [0,1]


   Aquarium ecosysteme( 640, 480, 30, angleVisionMax, angleVisionMin, distanceVisionMax, distanceVisionMin, distanceOuieMin, distanceOuieMax, capaciteDetectionOuieMin, capaciteDetectionOuieMax, camouflageMin, camouflageMax, protectionCarapaceMax, vitesseNageoireMax, probaMaxClonage, seuilAvantPeurMax, probaMaxDecesCollision );
   
   Milieu& milieu = ecosysteme.getMilieu();
   milieu.ajouterBestioles(20);
   
   ecosysteme.run();

   return 0;

}
