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
   float probaMaxClonage = 0.0005; // dans [0,1]
   int seuilAvantPeurMax = 5;
   float probaMaxDecesCollision = 1; //dans [0,1]


   Aquarium ecosysteme( 640, 480, 30, angleVisionMax, angleVisionMin, distanceVisionMax, distanceVisionMin, distanceOuieMin, distanceOuieMax, capaciteDetectionOuieMin, capaciteDetectionOuieMax, camouflageMin, camouflageMax, protectionCarapaceMax, vitesseNageoireMax, probaMaxClonage, seuilAvantPeurMax, probaMaxDecesCollision );
   
   Milieu& milieu = ecosysteme.getMilieu();
   milieu.ajouterBestioles(4);
   std::vector<Bestiole*> bestioles = milieu.getBestioles();

   bestioles.at(0) -> setX(100);
   bestioles.at(0) -> setY(100);
   bestioles.at(0) -> setDirection(0);
   bestioles.at(0) -> setProbabiliteDecesCollision(0);

   bestioles.at(1) -> setX(200);
   bestioles.at(1) -> setY(100);
   bestioles.at(1) -> setDirection(M_PI);
   bestioles.at(1) -> setProbabiliteDecesCollision(0);

   bestioles.at(2) -> setX(100);
   bestioles.at(2) -> setY(200);
   bestioles.at(2) -> setDirection(0);
   bestioles.at(2) -> setProbabiliteDecesCollision(1);

   bestioles.at(3) -> setX(200);
   bestioles.at(3) -> setY(200);
   bestioles.at(3) -> setDirection(M_PI);
   bestioles.at(3) -> setProbabiliteDecesCollision(1);

   ecosysteme.run();

   return 0;

}
