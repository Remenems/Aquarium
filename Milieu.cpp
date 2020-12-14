#include "Milieu.h"
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Clones.h"
#include <tuple>

#include "Yeux.h"
#include "Oreille.h"

#include <iostream>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu( int _width, int _height, Aquarium* aquarium ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;
   Clones clones = Clones();
   std::srand( time(NULL) );
   bestioles = std::vector<Bestiole*>();
   clock = 0;
   aquariumAssocie = aquarium;
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
   std::vector<tuple<float,float>> zones = std::vector<tuple<float,float>>();
   for (long unsigned int i =0 ; i<bestioles.size();i++)
   {
      //On récupère la "zone" de détection de la bestiole
      zones = bestioles.at(i) -> detecter();      
      std::vector<Bestiole*> voisines = std::vector<Bestiole*>();
      
      int x1 = bestioles.at(i) -> getX();
      float direction = bestioles.at(i) -> getDirection();

      //On vérifie pour chaque bestiole si elle est dans la zone
      for (long unsigned int n =0 ; n<bestioles.size(); n++)
      {
         if (bestioles.at(i) != bestioles.at(n))
         {

            int x2 = bestioles.at(n) -> getX();
            float distance = bestioles.at(i) -> distanceEntreBestioles(*(bestioles.at(n)));

            //Cas 1 : la bestiole sont sur la meme position -> detectée
            if (distance == 0){voisines.push_back(bestioles.at(n));}
            //Cas 2 : la distance est différente -> on vérifie par zone
            else
            {
               float angle = std::acos((x2 - x1)/distance); // calcul de l'angle entre les deux bestioles par rapport à 0
               //On vérifie pour chaque zone si la bestiole est dans la zone en question
               for (long unsigned int k=0; k<zones.size(); k++)
               {
                  // Une zone est définie par un rayon et un angle (angle = 2*PI si la zone est un cercle)
                  float distanceMax = get<0>(zones.at(k));
                  float angleVu = get<1>(zones.at(k));

                  float angleMax = direction + angleVu/2;
                  float angleMin = direction - angleVu/2;

                  if (distance < distanceMax && angle>angleMin && angle<angleMax)
                  {
                     //rempli les conditions -> voisine
                     voisines.push_back(bestioles.at(n));
                  }
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
   for (long unsigned int i = 0 ; i<listeBestioles.size(); i++)
   {
      listeBestioles.at(i)-> changerComportement(comportement);
   }
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
      Bestiole* b = new SimpleBestiole();
      bestioles.push_back(b);
      b->initCoords(width,height);
   }
}

void Milieu::tuerBestiole(Bestiole* bestiole)
{
   //On enlève la bestiole de la liste
   bestioles.erase(remove(bestioles.begin(), bestioles.end(), bestiole), bestioles.end());
   //On la supprime
   delete bestiole;
}

void Milieu::ajouterYeux(std::vector<Bestiole*> listeBestioles)
{
   //On appelle la fonction pour une bestiole à l'ensemble des bestioles de listeBestioles
   for(long unsigned int i =0; i< listeBestioles.size();i++)
   {
      ajouterYeux(listeBestioles.at(i));
   }
}

void Milieu::ajouterYeux(Bestiole* bestiole)
{  
   //On vérifie si la bestiole a déjà des yeux ou pas
   if(bestiole->aiJeCeCapteur(Oeil) == false)
   {
      //angle min + [nb aleatoire entre 0 et 1] * (angle max - angle min)
      float angle = get<0>(aquariumAssocie->getPlageChampAngulaireVision()) + static_cast<float>(std::rand()) / RAND_MAX * (get<1>(aquariumAssocie->getPlageChampAngulaireVision()) - get<0>(aquariumAssocie->getPlageChampAngulaireVision()));
      //dist min + [nb aleatoire entre 0 et 1] * (distance max - distance min)
      float distance = get<0>(aquariumAssocie->getPlageDistanceVision()) + static_cast<float>(std::rand()) / RAND_MAX * (get<1>(aquariumAssocie->getPlageDistanceVision()) - get<0>(aquariumAssocie->getPlageDistanceVision()));
      bestiole = new Yeux(bestiole, distance, angle);
   }
}

void Milieu::ajouterOreilles(std::vector<Bestiole*> listeBestioles)
{
   //On appelle la fonction pour une bestiole à l'ensemble des bestioles de listeBestioles
   for(long unsigned int i =0; i< listeBestioles.size();i++)
   {
      ajouterOreilles(listeBestioles.at(i));
   }
}

void Milieu::ajouterOreilles(Bestiole* bestiole)
{
   //On vérifie si la bestiole a déjà des oreilles ou pas
   if(bestiole->aiJeCeCapteur(Oreilles) == false)
   {
      //Ajouter une oreille
      //dist min + [nb aleatoire entre 0 et 1] * (distance max - distance min)
      float distance = get<0>(aquariumAssocie->getPlageDistanceOuie()) + static_cast<float>(std::rand()) / RAND_MAX * (get<1>(aquariumAssocie->getPlageDistanceOuie()) - get<0>(aquariumAssocie->getPlageDistanceOuie()));
      bestiole = new Oreille(bestiole, distance);
   }
}

