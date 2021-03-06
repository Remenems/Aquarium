#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"
//#include <vector>
#include "IPrototypeBestiole.h"
//#include <string>
#include <tuple>

#include "IComportement.h"

#include <iostream>

using namespace std;


class Milieu;
class IComportement;

enum CapteurType
{
   Oeil,
   Oreilles,
};

class Bestiole : public IPrototypeBestiole
{

//attributs
private :

   static int NB_bestiole;

   int identity;

   //accessoires
   float camouflage;
   float carapace;
   float nageoire;

   //Caractéristiques "physiques" (non modifiafle sauf intervention extérieur)
   float taille;
   int ageDeces;
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

   Bestiole();
   Bestiole(float camouflage, float carapace, float nageoire, float taille, int ageDeces, float probabiliteDecesCollision, float probabiliteClonage, IComportement* comportement, float direction, float vitesse);
   Bestiole(const Bestiole& bestiole, int x, int y);
   virtual ~Bestiole( void );

   virtual Bestiole* clone() = 0; 

   void initCoords( int xLim, int yLim );

   bool mourrirSiCollision();

   virtual vector<tuple<float,float>> detecter() = 0;
   virtual bool aiJeCeCapteur(CapteurType type) = 0;

   void changerComportement(IComportement*);

   void draw(UImg & support);
   void vieillir();
   void actualiserPosition(int xLim, int yLim);
   float distanceEntreBestioles(Bestiole& b);

   // accesseurs des accessoires
   void changerNageoire(float coefficient);
   void changerCamouflage(float coefficient);
   void changerCarapace(float coefficient);

   float getNageoire() const;
   float getCamouflage() const;
   float getCarapace() const;

   // accesseurs des caractéristiques physiques
   float getTaille() const;
   int getAgeDeces() const;
   float getProbabiliteDecesCollision() const;
   float getProbabiliteClonage() const;

   void setTaille(float taille);
   void setAgeDeces(int AgeDeces);
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

   //acc identité
   int getIdentity();

};


#endif
