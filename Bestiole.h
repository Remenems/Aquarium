#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"
#include <vector>
#include "IPrototypeBestiole.h"
#include <string>
#include <tuple>

#include "IComportement.h"

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
   IComportement* comportement;

   //Caractéristiques "spatiales" (modifié au cours de la simulation)
   float direction;
   float vitesse;
   int x;
   int y;
   vector<Bestiole*> bestiolesVoisines;
   double cumulX = 0;
   double cumulY = 0;

   //caractéristiques visuelles
   T * couleur;

//méthodes
public :

   //void changerComportement(IComportement*);

   Bestiole(float camouflage, float carapace, float nageoire, float taille, int dateDeces, float probabiliteDecesCollision, float probabiliteClonage, IComportement& comportement, float direction, float vitesse, T* couleur);
   Bestiole(const Bestiole& bestiole);

   Bestiole* clone() = 0;

   void initCoords( int xLim, int yLim );

   bool mourrirSiCollision();
   virtual vector<Bestiole*> detecter() = 0;
   virtual bool aiJeCeCapteur(string capteur) = 0;

   void draw(UImg & support);
   void repositionnerBestiole(int xLim, int yLim);
   float distanceEntreBestioles(Bestiole& b);

   void action(Milieu& monMilieu);

   // accesseurs des accessoires
   void changerNageoire(float coefficient);
   void changerCamouflage(float coefficient);
   void changerCarapace(float coefficient);

   float getNageoire() const;
   float getCamouflage() const;
   float getCarapace() const;

   // accesseurs des caractéristiques physiques
   float getTaille() const;
   int getDateDeces() const;
   float getProbabiliteDecesCollision() const;
   float getProbabiliteClonage() const;

   void setTaille(float taille);
   void setDateDeces(int dateDeces);
   void setProbabiliteDecesCollision(float p);
   void setProbabiliteClonage(float p);

   //accesseurs des caractéristiques spatiales 
   float getDirection() const;
   float getVitesse() const;
   tuple<int, int> getPosition() const;
   int getX() const;
   int getY() const;
   vector<Bestiole*> getBestiolesVoisines() const;

   void setDirection(float direction);
   void setVitesse(float vitesse);
   void setPosition(tuple<int, int> position);
   void setX(int x);
   void setY(int y);
   void setBestiolesVoisines(vector<Bestiole*> bV);

   //accesseurs des caractériques visuelles
   T* getCouleur() const;
   void setCouleur(T* couleur);

};


#endif
