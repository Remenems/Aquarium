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
   float distanceOuieMin = 3.;
   float distanceOuieMax = 8.;
   float capaciteDetectionOuieMin = 0.2; // dans [0,1]
   float capaciteDetectionOuieMax = 0.8;
   float camouflageMin = 0.3; // dans [0,1]
   float camouflageMax = 0.7;
   float protectionCarapaceMax = 5.; // >1
   float vitesseNageoireMax = 8.; //>1
   float probaMaxClonage = 1; // dans [0,1]
   int seuilAvantPeurMax = 5;


   Aquarium ecosysteme( 640, 480, 30, angleVisionMax, angleVisionMin, distanceVisionMax, distanceVisionMin, distanceOuieMin, distanceOuieMax, capaciteDetectionOuieMin, capaciteDetectionOuieMax, camouflageMin, camouflageMax, protectionCarapaceMax, vitesseNageoireMax, probaMaxClonage, seuilAvantPeurMax );

   ecosysteme.getMilieu().ajouterBestioles(20);
   ecosysteme.run();

   return 0;

}
