#include "Bestiole.h"

#include "Milieu.h"

#include <cstdlib>
#include <cmath>
#include <tuple>

Bestiole::Bestiole(float cam, float car, float nag, float tai, int daDeces, float probaDecesCollision, float probaClonage, IComportement& comport, float dir, float vit, T* coul)
{
   x = 0;
   y = 0; // à changer
   camouflage = cam;
   carapace = car;
   nageoire = nag;
   taille = tai;
   dateDeces = daDeces;
   probabiliteDecesCollision = probaDecesCollision;
   probabiliteClonage = probaClonage;
   direction = dir;
   vitesse = vit;
   couleur = coul;
   //TODO intiialiser le comportement
}


Bestiole::Bestiole( const Bestiole & b )
{
   x = b.getX();
   y = b.getY();
   camouflage = b.getCamouflage();
   carapace = b.getCarapace();
   nageoire = b.getNageoire();
   taille = b.getTaille();
   dateDeces = b.getDateDeces();
   probabiliteDecesCollision = b.getProbabiliteDecesCollision();
   probabiliteClonage = b.getProbabiliteClonage();
   direction = b.getDirection();
   vitesse = b.getVitesse();
   couleur = b.getCouleur();
   //TODO initialiser le comportement
}


Bestiole::~Bestiole( void )
{

   delete[] couleur;
   delete comportement;

   cout << "dest Bestiole" << endl;

}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::repositionnerBestiole( int xLim, int yLim )
{
   tuple<float, float> coupleDirectionVitesse = comportement->calculDirection(detecter());//comportement.calculDirection();
   direction = get<0>(coupleDirectionVitesse);
   float vitessePourCeTour = vitesse*get<1>(coupleDirectionVitesse);

   double nx, ny;
   double dx = cos( direction )*vitessePourCeTour*nageoire;
   double dy = -sin( direction )*vitessePourCeTour*nageoire;
   int cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      direction = M_PI - direction;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      direction = -direction;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }
}

bool Bestiole::mourrirSiCollision()
{
   float p = static_cast<float>( rand() )/RAND_MAX;
   return (p < probabiliteDecesCollision);
}

void Bestiole::draw( UImg & support )
{

   double xt = x + cos( direction )*taille/2.1;
   double yt = y - sin( direction )*taille/2.1;


   support.draw_ellipse( x, y, taille, taille/5., -direction/M_PI*180., couleur );
   support.draw_circle( xt, yt, taille/2., couleur );

}

float Bestiole::distanceEntreBestioles(Bestiole& b){
   int dx = x - b.getX();
   int dy = y - b.getY();
}

//accesseurs
#pragma region accesseurs

float Bestiole::getDirection() const{
   return direction;
}

void Bestiole::setDirection(float dir){
   direction = dir;
}

float Bestiole::getVitesse() const{
   return vitesse;
}

void Bestiole::setVitesse(float vit){
   vitesse = vit;
}

int Bestiole::getX() const{
   return x;
}

void Bestiole::setX(int X){
   x= X;
}

int Bestiole::getY() const{
   return y;
}

void Bestiole::setY(int Y){
   y=Y;
}

vector<Bestiole*> Bestiole::getBestiolesVoisines() const{
   return bestiolesVoisines;
}

void Bestiole::setBestiolesVoisines(vector<Bestiole*> bV){
   bestiolesVoisines = bV;
}

T* Bestiole::getCouleur() const{
   return couleur;
}

void Bestiole::setCouleur(T* coul){
   couleur = coul;
}

float Bestiole::getTaille() const{ 
   return taille;
}

void Bestiole::setTaille(float t){
   taille = t;
}

int Bestiole::getDateDeces() const{
   return dateDeces;
}

void Bestiole::setDateDeces(int date){
   dateDeces = date;
}

float Bestiole::getProbabiliteClonage() const{
   return probabiliteClonage;
}

void Bestiole::setProbabiliteClonage(float p){
   probabiliteClonage= p;
}

float Bestiole::getProbabiliteDecesCollision() const{
   return probabiliteDecesCollision;
}

void Bestiole::setProbabiliteDecesCollision(float p){
   probabiliteDecesCollision = p;
}

float Bestiole::getNageoire() const{
   return nageoire;
}

void Bestiole::changerNageoire(float n){
   nageoire = n;
}

float Bestiole::getCamouflage() const{
   return camouflage;
}

void Bestiole::changerCamouflage(float c){
   camouflage = c;
}

float Bestiole::getCarapace() const{
   return carapace;
}

void Bestiole::changerCarapace(float c){
   carapace = c;
}

#pragma endregion accesseurs

void Bestiole::action( Milieu & monMilieu )
{

   repositionnerBestiole( monMilieu.getWidth(), monMilieu.getHeight() );

}

 // modulo
float modulo(float x, float y) //y>0
{
   if(y<0)
      y = abs(y);
   if(x>=0)
   {
      if(x>=y)
      {
         return modulo(x-y, y);
      }
      else
      {
         return x;
      }
   }
   else
   {
      return modulo(x+y,y);
   }
    
}