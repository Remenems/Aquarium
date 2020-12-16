#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "ComportementGregaire.h"

#include <iostream>

using namespace std;


int main()
{
   float angleVisionMax = M_PI;
   float angleVisionMin = 0.;
   float distanceVisionMax = 100.;
   float distanceVisionMin = 50.;
   float distanceOuieMin = 400.;
   float distanceOuieMax = 500.;
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
   milieu.ajouterBestioles(5);
   std::vector<Bestiole*> bestioles = milieu.getBestioles();

   bestioles.at(0) -> setX(100);
   bestioles.at(0) -> setY(100);
   bestioles.at(0) -> setDirection(M_PI);

   bestioles.at(1) -> setX(150);
   bestioles.at(1) -> setY(120);
   bestioles.at(1) -> setDirection(0);

   bestioles.at(2) -> setX(130);
   bestioles.at(2) -> setY(110);
   bestioles.at(2) -> setDirection(1.12);

   bestioles.at(3) -> setX(150);
   bestioles.at(3) -> setY(150);
   bestioles.at(3) -> setDirection(2.1);

   bestioles.at(4) -> setX(140);
   bestioles.at(4) -> setY(100);
   bestioles.at(4) -> setDirection(3);
   
   milieu.changerComportement(new ComportementGregaire(), bestioles.at(0));
   milieu.changerComportement(new ComportementGregaire(), bestioles.at(1));
   milieu.changerComportement(new ComportementGregaire(), bestioles.at(2));
   milieu.changerComportement(new ComportementGregaire(), bestioles.at(3));
   milieu.changerComportement(new ComportementGregaire(), bestioles.at(4));
   milieu.ajouterOreilles(bestioles);


   ecosysteme.run();

   return 0;

}
