#include "Milieu.h"
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Clones.h"
#include <tuple>

#include <iostream>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;
   Clones clones = Clones();
   std::srand( time(NULL) );
   bestioles = std::vector<Bestiole*>();
   clock = 0;
}


Milieu::~Milieu( void )
{
   int s = bestioles.size();
   for(int i =0; i<s;i++)
   {
      delete bestioles.at(i);
   }
   cout << "dest Milieu" << endl;

}

void Milieu::clonerBestiole(std::vector<Bestiole*> listeBestioles)
{
   for (long unsigned int i = 0; i<listeBestioles.size();i++)
   {
      int x = static_cast<int>(static_cast<float>( std::rand() )/RAND_MAX*width);
      int y = static_cast<int>(static_cast<float>( std::rand() )/RAND_MAX*height);
      Bestiole* nouvelleBestiole = listeBestioles.at(i) -> clone(x, y);
      bestioles.push_back(nouvelleBestiole);
   }
}

void Milieu::verifierSiClonage(){
   std::vector<Bestiole*> bestiolesClones = std::vector<Bestiole*>();
   for (long unsigned int i =0; i< bestioles.size(); i++)
   {
      float p = bestioles.at(i) -> getProbabiliteClonage();
      float p2 = static_cast<float>( std::rand() )/RAND_MAX;
      if (p > p2)
      {
         bestiolesClones.push_back(bestioles.at(i));
      }
   }
   clonerBestiole(bestiolesClones);
}

void Milieu::verifierAgeBestiole()
{
   for (long unsigned int i = 0 ; i<bestioles.size(); i++)
   {
      if (bestioles.at(i) -> getAgeDeces() <= 0){
         tuerBestiole(bestioles.at(i));
      }
   }
}

void Milieu::verifierCollision()
{
   int tailleVecteur = bestioles.size();
   for (int i=0; i<=tailleVecteur-1; i=i+1)
   {
      float taille1 = bestioles.at(i) -> getTaille();

      for (int k = i+1; k<= tailleVecteur; k=k+1)
      {
         float taille2 = bestioles.at(k) -> getTaille();

         float distance = bestioles.at(i) -> distanceEntreBestioles(*bestioles.at(k));
         if (distance < taille1 + taille2)
         {
            if (bestioles.at(i) -> mourrirSiCollision()){
               tuerBestiole(bestioles.at(i));
            }
            if (bestioles.at(k) -> mourrirSiCollision()){
               tuerBestiole(bestioles.at(k));
            }
         } 
      }
   }
}

void Milieu::repositionnerBestioles()
{
   for (long unsigned int i =0; i< bestioles.size(); i++)
   {
      bestioles.at(i) -> actualiserPosition(width, height);
   }
}

void Milieu::actualiserVoisines()
{
   std::vector<tuple<float,float>> res = std::vector<tuple<float,float>>();
   for (long unsigned int i =0 ; i<bestioles.size();i++)
   {
      res = bestioles.at(i) -> detecter();      
      std::vector<Bestiole*> voisines = std::vector<Bestiole*>();
      
      int x1 = bestioles.at(i) -> getX();
      float direction = bestioles.at(i) -> getDirection();

      for (long unsigned int n =0 ; n<bestioles.size(); n++)
      {
         if (bestioles.at(i) != bestioles.at(n))
         {

            int x2 = bestioles.at(n) -> getX();
            float distance = bestioles.at(i) -> distanceEntreBestioles(*(bestioles.at(n)));
            float angle = std::acos((x2 - x1)/distance);

            if (distance = 0){voisines.push_back(bestioles.at(n));}

            for (long unsigned int k=0; k<res.size(); k++)
            {
               float distanceMax = get<0>(res.at(k));
               float angleVu = get<1>(res.at(k));

               float angleMax = direction + angleVu/2;
               float angleMin = direction - angleVu/2;

               if (distance < distanceMax && angle>angleMin && angle<angleMax)
               {
                  voisines.push_back(bestioles.at(n));
               }
            }
         }
      }
      bestioles.at(i)->setBestiolesVoisines(voisines);
   }
}

void Milieu::initialisation(int nombre, std::vector<float> pourcentageComportement)
{
   //TODO
}

void Milieu::ajouterCarapace(std::vector<Bestiole*> listeBestioles, float coefficient)
{
   for (long unsigned int i = 0 ; i<listeBestioles.size(); i++)
   {
      listeBestioles.at(i)->changerCarapace(coefficient);
   }
}

void Milieu::ajouterCamouflage(std::vector<Bestiole*> listeBestioles, float coefficient)
{
   for (long unsigned int i = 0 ; i<listeBestioles.size(); i++)
   {
      listeBestioles.at(i)->changerCamouflage(coefficient);
   }
}

void Milieu::ajouterNageoire(std::vector<Bestiole*> listeBestioles, float coefficient)
{
   for (long unsigned int i = 0 ; i<listeBestioles.size(); i++)
   {
      listeBestioles.at(i)->changerNageoire(coefficient);
   }
}

void Milieu::changerComportement(IComportement* comportement, std::vector<Bestiole*> listeBestioles)
{
   /*  FAIRE LA FONCTION CHANGERCOMPORTEMENT DANS BESTIOLE.H ET BESTIOLE.CPP
   for (long unsigned int i = 0 ; i<listeBestioles.size(); i++)
   {
      listeBestioles.at(i)-> changerComportement(comportement);
   }
   */
}

void Milieu::step( void )
{
   clock++;
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for (long unsigned int i = 0 ; i<bestioles.size(); i++)
   {
      bestioles.at(i)->draw( *this );
      bestioles.at(i)->actualiserPosition(width,height);
   }

}

void Milieu::ajouterBestioles(int nombre)
{
   for(int i=0;i<nombre;i++)
   {
      bestioles.push_back(new SimpleBestiole());
   }
}

void Milieu::tuerBestiole(Bestiole* bestiole)
{
   //TODO tuerBestiole
}


/*int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}*/
