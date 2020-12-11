#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include "Clones.h"
#include <iostream>
#include <vector>
#include "SimpleBestiole.h"

using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];
   Clones clones;
   int                     width, height;
   std::vector<Bestiole*>   bestioles;

   //Timer: échelle de temps, est incrémenté à chaque step
   int clock;

public :
   Milieu( int _width, int _height );
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
   void initialisation(int nombre, std::vector<float> pourcentageComportement);
   void ajouterCarapace(std::vector<Bestiole*> listeBestioles);
   void ajouterNageoire(std::vector<Bestiole*> listeBestioles);
   void ajouterCamouflage(std::vector<Bestiole*> listeBestioles);
   void changerComportement(IComportement* comportement, std::vector<Bestiole*> listeBestioles);
   void ajouterYeux(std::vector<Bestiole*> listeBestioles);
   void ajouterOreilles(std::vector<Bestiole*> listeBestioles);
   void afficherBestiole();
   void tuerBestiole(Bestiole* bestiole);
   void ajouterBestioles(int nombre);
};


#endif
