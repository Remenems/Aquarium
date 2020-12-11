#include "Milieu.h"
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <ctime>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}

void Milieu::clonerBestiole(std::vector<Bestiole> listeBestioles)
{
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      int x = static_cast<int>(static_cast<float>( std::rand() )/RAND_MAX*width);
      int y = static_cast<int>(static_cast<float>( std::rand() )/RAND_MAX*height);
      Bestiole* nouvelleBestiole = it -> clone(x, y);
      bestioles.push_back(*nouvelleBestiole);
   }
}

void Milieu::verifierSiClonage(){
   std::vector<Bestiole> bestiolesClones = std::vector<Bestiole>();
   for ( std::vector<Bestiole>::iterator it = bestioles.begin() ; it != bestioles.end() ; ++it )
   {
      float p = it -> getProbabiliteClonage();
      float p2 = static_cast<float>( std::rand() )/RAND_MAX;
      if (p > p2)
      {
         bestiolesClones.push_back(*it);
      }
   }
   ClonerBestiole(bestiolesClones);
}

void Milieu::step( void )
{
   clock++;
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole>::iterator it = bestioles.begin() ; it != bestioles.end() ; ++it )
   {

      it->action( *this );
      it->draw( *this );

   } // for

}


/*int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}*/
