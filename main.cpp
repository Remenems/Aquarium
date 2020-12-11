#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium ecosysteme( 640, 480, 30 );

   ecosysteme.getMilieu().ajouterBestioles(20);
   ecosysteme.run();

   return 0;

}
