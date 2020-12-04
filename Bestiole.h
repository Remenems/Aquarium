#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"
#include <vector>
#include "IPrototypeBestiole.h"
#include <string>
#include <tuple>

#include <iostream>

using namespace std;


class Milieu;


class Bestiole : public IPrototypeBestiole
{

//attributs
private :

   //accessoires
   float camouflage;
   float carapace;
   float nageoire;

   //Caractéristiques "physiques" (non modifiafle sauf intervention extérieur)
   float taille;
   int dateDeces;
   float probabiliteDecesCollision;
   float probabiliteClonage;
   //IComportement& comportement;

   //Caractéristiques "spatiales" (modifié au cours de la simulation)
   float direction;
   float vitesse;
   tuple<int, int> position;
   int x = get<0>(position);
   int y = get<1>(position);
   vector<Bestiole*> bestiolesVoisines;
   double cumulX = 0;
   double cumulY = 0;

   //caractéristiques visuelles
   T               * couleur;

//méthodes
public :

   //void changerComportement(IComportement*);

   Bestiole* clone() = 0;

   bool mourrirSiCollision();
   virtual vector<Bestiole*> detecter() = 0;
   bool aiJeCeCapteur(string capteur);

   void draw(UImg & support);
   void repositionnerBestiole(int xLim, int yLim);
   float distanceEntreBestioles(Bestiole& b);

   // accesseurs des accessoires
   void changerNageoire(float coefficient);
   void changerCamouflage(float coefficient);
   void changerCarapace(float coefficient);

   float getNageoire();
   float getCamouflage();
   float getCarapace();

   // accesseurs des caractéristiques physiques
   float getTaille();
   int getDateDeces();
   float getProbabiliteDecesCollision();
   float getProbabiliteClonage();

   void setTaille(float taille);
   void setDateDeces(int dateDeces);
   void setProbabiliteDecesCollision(float p);
   void setProbabiliteClonage(float p);

   //accesseurs des caractéristiques spatiales 
   float getDirection();
   float getVitesse();
   tuple<int, int> getPosition();
   int getX();
   int getY();
   vector<Bestiole*> getBestiolesVoisines();

   void setDirection(float direction);
   void setVitesse(float vitesse);
   void setPosition(tuple<int, int> position);
   void setX(int x);
   void setY(int y);
   void setBestiolesVoisines(vector<Bestiole*> bV);

   //accesseurs des caractériques visuelles
   T* getCouleur();
   void setCouleur(T* couleur);
};


#endif
