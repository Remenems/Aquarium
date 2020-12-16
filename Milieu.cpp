#include "Milieu.h"
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Clones.h"
#include <tuple>

#include "Yeux.h"
#include "Oreille.h"
#include "ComportementKamikaze.h"
#include "ComportementGregaire.h"
#include "ComportementMultiple.h"
#include "ComportementPrevoyante.h"
#include "ComportementPeureuse.h"

#include <iostream>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu( int _width, int _height, Aquarium* aquarium ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   //on contruit le milieu
   cout << "const Milieu" << endl;
   clones = new Clones();
   std::srand( time(NULL) );
   bestioles = std::vector<Bestiole*>();
   clock = 0;
   aquariumAssocie = aquarium;
   std::srand(std::time(nullptr));
}


Milieu::~Milieu( void )
{
   //on détruit le milieu eet les bestioles à l'intérieur
   int s = bestioles.size();
   for(int i =0; i<s;i++)
   {
      delete bestioles.at(i);
   }
   //on détruit les clones
   delete clones;
   cout << "dest Milieu" << endl;

}

void Milieu::clonerBestiole(std::vector<Bestiole*> listeBestioles)
{
   for (long unsigned int i = 0; i<listeBestioles.size();i++)
   {
      //Bestiole* nouvelleBestiole = listeBestioles.at(i) -> clone(x, y);
      //TODO réparer la méthode clone 
      Bestiole* nouvelleBestiole = new SimpleBestiole();
      nouvelleBestiole->initCoords(width, height);
      bestioles.push_back(nouvelleBestiole);
   }
}

void Milieu::verifierSiClonage(){
   std::vector<Bestiole*> bestiolesClones = std::vector<Bestiole*>();

   //on parcourt l'ensemble des bestioles
   for (long unsigned int i =0; i< bestioles.size(); i++)
   {
      float p = bestioles.at(i) -> getProbabiliteClonage();
      float p2 = static_cast<float>( std::rand() )/RAND_MAX;
      //pour chaque bestioles on vérifie si elle doit être cloné
      if (p > p2)
      {
         //si c'est le cas on l'ajout à la liste des bestioles à cloner
         bestiolesClones.push_back(bestioles.at(i));
      }
   }
   //on clone l'ensemble des bestioles à cloner
   clonerBestiole(bestiolesClones);
}

void Milieu::verifierAgeBestiole()
{
   //on  parcourt l'ensemble des bestioles
   for (long unsigned int i = 0 ; i<bestioles.size(); i++)
   {
      //pour chaque bestioles, on vérifie si regarde si le nombre d'année à vivre est inférieur à 0
      if (bestioles.at(i) -> getAgeDeces() <= 0){
         //on tue la bestiole si c'est le cas
         tuerBestiole(bestioles.at(i));
      }
   }
}

void Milieu::verifierCollision()
{
   std::vector<Bestiole*> bestiolesToKill = std::vector<Bestiole*>();
   int tailleVecteur = bestioles.size();
   //On choisit d'abord les bestioles que l'on va tuer (si les conditions sont respectées)
   //On parcourt l'ensemble des bestioles
   for (int i=0; i<tailleVecteur; i=i+1)
   {
      float taille1 = bestioles.at(i) -> getTaille();
      bool toKill = false;
      //Pour chaque bestioles on vérifie si elle n'est pas en collision avec chaque autre bestioles
      for (int k = 0; k<tailleVecteur; k=k+1)
      {
         //on ne compare pas la bestiole avec elle même
         if(k!=i)
         {
            float taille2 = bestioles.at(k) -> getTaille();

            float distance = bestioles.at(i) -> distanceEntreBestioles(*bestioles.at(k));
            //si il y a collision
            if (5* distance < taille1 + taille2)
            {
               bool p = bestioles.at(i) -> mourrirSiCollision();
               //std::cout << p << endl;

               // si elle doit mourrir
               if (p){
                  toKill = true;
               }

               //si elle ne meurt pas, elle fait demi tour
               else{
                  float direction = (bestioles.at(i) -> getDirection()) + M_PI;
                  bestioles.at(i) -> setDirection(direction);
               }
            } 
         }
         
      }
      //On ajoute la bestiole à la liste des bestioles à tuer
      if(toKill)
      {
         bestiolesToKill.push_back(bestioles.at(i));
      }
   }
   //On tue les bestioles selectionnées précedemment
   for(long unsigned int i = 0; i< bestiolesToKill.size(); i++)
   {
      tuerBestiole(bestiolesToKill.at(i));
   }
}

void Milieu::repositionnerBestioles()
{
   //on repositionne toutes les bestioles
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

            //Cas 1 : la bestiole est sur la meme position que la première-> detectée
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

void Milieu::ajouterCarapace(std::vector<Bestiole*> listeBestioles, float coefficient)
{
   //pour toutes les bestioles de la liste en paramètre on ajoute une carapace
   for (long unsigned int i = 0 ; i<listeBestioles.size(); i++)
   {
      listeBestioles.at(i)->changerCarapace(coefficient);
   }
}

void Milieu::ajouterCamouflage(std::vector<Bestiole*> listeBestioles, float coefficient)
{
   //pour toutes les bestioles de la lsite en paramètres on ajoute un camouflage
   for (long unsigned int i = 0 ; i<listeBestioles.size(); i++)
   {
      listeBestioles.at(i)->changerCamouflage(coefficient);
   }
}

void Milieu::ajouterNageoire(std::vector<Bestiole*> listeBestioles, float coefficient)
{
   //pour toutes les bestioles de la liste en paramètres on ajoute une nageoire
   for (long unsigned int i = 0 ; i<listeBestioles.size(); i++)
   {
      listeBestioles.at(i)->changerNageoire(coefficient);
   }
}

void Milieu::changerComportement(IComportement* comportement, std::vector<Bestiole*> listeBestioles)
{
   //pour toutes les bestioles de la liste en paramètre on change leur comportement en celui mis en paramètre
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
      //à chaque étape :
      //on affiche les bestioles
      bestioles.at(i)->draw( *this );
      //on diminue leur durée de vie restantes
      bestioles.at(i)->vieillir();
      //on regarde si elles détectent d'autres bestioles
      actualiserVoisines();
      //on les place à leur nouvelle position
      bestioles.at(i)->actualiserPosition(width,height);
      //on vérifie après si elle n'entre pas en collision avec une autre bestiole
      verifierCollision();
      //on regarde si elles ne ne sont pas mortes
      verifierAgeBestiole();
      //on regarde si elle doit être cloné
      verifierSiClonage();
   }

}

void Milieu::ajouterBestioles(int nombre)
{
   for(int i=0;i<nombre;i++)
   {

      //choix aléatoire du comportement
      int choix = std::rand() % 5;
      Bestiole* b;
      switch (choix)
         {
         case 0:
            b = (clones -> getPeureuse()) -> clone();
            break;
         
         case 1:
            b = (clones -> getPrevoyante()) -> clone();
            break;

         case 2:
            b = (clones -> getKamikaze()) -> clone();
            break;

         case 3:
            b = (clones -> getGregaire()) -> clone();
            break;

         case 4:   
         default:
            b = (clones -> getMultiple()) -> clone();
            break;
         }

      float probaDecesCollision = aquariumAssocie->getProbaMaxDecCollision() * (float)(std::rand()) / (float)(RAND_MAX);
      float probaClonage = aquariumAssocie -> getProbaMaxClonage() * static_cast<float>(std::rand()) / RAND_MAX;
      float direction = (static_cast<float>(std::rand()) / RAND_MAX) * 2 * M_PI;
      float vitesse = (static_cast<float>(std::rand()) / RAND_MAX) * 4. + 1;

      b -> setProbabiliteDecesCollision(probaDecesCollision);
      b -> setProbabiliteClonage(probaClonage);
      b -> setDirection(direction);
      b -> setVitesse(vitesse);
      b->initCoords(width,height);

      bestioles.push_back(b);
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

std::vector<Bestiole*> Milieu::getBestioles()
{
   return bestioles;
}

