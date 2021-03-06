#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include "Clones.h"
#include <iostream>
#include <vector>
#include "SimpleBestiole.h"
#include "Aquarium.h"

using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];
   //Clones* clones;
   int                     width, height;
   std::vector<Bestiole*>   bestioles;
   Aquarium* aquariumAssocie;

   //Timer: échelle de temps, est incrémenté à chaque step
   int clock;

public :
   Milieu( int _width, int _height, Aquarium* aquarium );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );
   void clonerBestiole(std::vector<Bestiole*> listeBestioles);
   void verifierSiClonage();
   void verifierAgeBestiole();
   void verifierCollision();
   void repositionnerBestioles();
   void actualiserVoisines();
   void ajouterCarapace(std::vector<Bestiole*> listeBestioles, float coefficient);
   void ajouterNageoire(std::vector<Bestiole*> listeBestioles, float coefficient);
   void ajouterCamouflage(std::vector<Bestiole*> listeBestioles, float coefficient);
   void changerComportement(IComportement* comportement, Bestiole* bestiole);
   void ajouterYeux(std::vector<Bestiole*> listeBestioles);
   void ajouterYeux(Bestiole* bestiole);
   void ajouterOreilles(std::vector<Bestiole*> listeBestioles);
   void ajouterOreilles(Bestiole* bestiole);
   void afficherBestiole();
   void tuerBestiole(Bestiole* bestiole);
   void ajouterBestioles(int nombre);
   std::vector<Bestiole*> getBestioles();
};


#endif
