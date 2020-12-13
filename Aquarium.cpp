#include "Aquarium.h"

#include "Milieu.h"


Aquarium::Aquarium( int width, int height, int _delay, float angleVisionMax, float angleVisionMin, float distanceVisionMax, float distanceVisionMin, float distanceOuieMin, float distanceOuieMax, float capaciteDetectionOuieMin, float capaciteDetectionOuieMax, float camouflageMin, float camouflageMax, float protectionCarapaceMax, float vitesseNageoiremax,float probamaxClonage, int seuilAvantPeurmax) : CImgDisplay(), delay( _delay )
{

   int screenWidth = 1280; //screen_width();
   int screenHeight = 1024; //screen_height();

   plageChampAngulaireVision = make_tuple(angleVisionMin, angleVisionMax);
   plageDistanceVision = make_tuple(distanceVisionMin, distanceVisionMax);
   plageDistanceOuie = make_tuple(distanceOuieMin, distanceOuieMax);
   plageCapaciteDetectionOuie = make_tuple(capaciteDetectionOuieMin, capaciteDetectionOuieMax);
   plageCamouflage = make_tuple(camouflageMin, camouflageMax);
   protectionCarapacemax = protectionCarapaceMax;
   vitesseNageoireMax = vitesseNageoiremax;
   probaMaxClonage = probamaxClonage;
   seuilAvantPeurMax = seuilAvantPeurmax;

   cout << "const Aquarium" << endl;

   milieu = new Milieu( width, height );
   assign( *milieu, "Simulation d'ecosysteme - Groupe 6" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

   delete milieu;

   cout << "dest Aquarium" << endl;

}


void Aquarium::run( void )
{

   cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {

      // cout << "iteration de la simulation" << endl;

      if ( is_key() ) {
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();
      }

      milieu->step();
      display( *milieu );

      wait( delay );

   } // while

}
