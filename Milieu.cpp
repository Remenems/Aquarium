#include "Milieu.h"
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Clones.h"
#include <tuple>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;
   Clones clones = Clones();
   std::srand( time(NULL) );
   bestioles = std::vector<Bestiole>();
   clock = 0;
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
   clonerBestiole(bestiolesClones);
}

void Milieu::verifierAgeBestiole()
{
   for ( std::vector<Bestiole>::iterator it = bestioles.begin() ; it != bestioles.end() ; ++it )
   {
      if (it -> getAgeDeces() <= 0){
         tuerBestiole(*it);
      }
   }
}

void Milieu::verifierCollision()
{
   int tailleVecteur = bestioles.size();
   for (int i=0; i<=tailleVecteur-1; i=i+1)
   {
      float taille1 = bestioles.at(i).getTaille();

      for (int k = i+1; k<= tailleVecteur; k=k+1)
      {
         float taille2 = bestioles.at(k).getTaille();

         float distance = bestioles.at(i).distanceEntreBestioles(bestioles.at(k));
         if (distance < taille1 + taille2)
         {
            if (bestioles.at(i).mourrirSiCollision()){
               tuerBestiole(bestioles.at(i));
            }
            if (bestioles.at(k).mourrirSiCollision()){
               tuerBestiole(bestioles.at(k));
            }
         } 
      }
   }
}

void Milieu::repositionnerBestioles()
{
   for ( std::vector<Bestiole>::iterator it = bestioles.begin() ; it != bestioles.end() ; ++it )
   {
      it -> actualiserPosition(width, height);
   }
}

void Milieu::actualiserVoisines()
{
   for ( std::vector<Bestiole>::iterator it = bestioles.begin() ; it != bestioles.end() ; ++it )
   {
      vector<std::tuple<float,float>> res = it -> detecter();
      std::vector<Bestiole> voisines = std::vector<Bestiole>();
      for
   }
}

void Milieu::step( void )
{
   clock++;
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole>::iterator it = bestioles.begin() ; it != bestioles.end() ; ++it )
   {

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
