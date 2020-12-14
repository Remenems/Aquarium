#include "Bestiole.h"

#include "Milieu.h"

#include "IComportement.h"

#include "ComportementGregaire.h"
#include "ComportementKamikaze.h"
#include "ComportementMultiple.h"
#include "ComportementPeureuse.h"
#include "ComportementPrevoyante.h"

#include <cstdlib>
#include <cmath>
#include <tuple>

static float modulo(float x, float y);

Bestiole::Bestiole(float cam, float car, float nag, float tai, int aDeces, float probaDecesCollision, float probaClonage, IComportement* comport, float dir, float vit)
{
   x = 0;
   y = 0;
   cumulX = 0;
   cumulY = 0;

   camouflage = cam;
   carapace = car;
   nageoire = nag;
   taille = tai;
   ageDeces = aDeces;
   probabiliteDecesCollision = probaDecesCollision;
   probabiliteClonage = probaClonage;

   bestiolesVoisines = vector<Bestiole*>();

   direction = dir;
   vitesse = vit;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   comportement = comport;
}

Bestiole::Bestiole()
{
   x = 0;
   y = 0;
   cumulX = 0;
   cumulY = 0;
   camouflage = 0;
   carapace =  1;
   nageoire = 1;
   taille = 8.;
   cout << taille << endl;
   ageDeces = 1000;
   probabiliteDecesCollision = 1;
   probabiliteClonage = 0;

   direction = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = 2;//static_cast<double>( rand() )/RAND_MAX*10.;

   bestiolesVoisines = vector<Bestiole*>();

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   int choix = rand() % 5;
   switch (choix)
   {
   case 0:
      comportement = new ComportementPeureuse();
      break;
   
   case 1:
      comportement = new ComportementPrevoyante();
      break;

   case 2:
      comportement = new ComportementKamikaze();
      break;

   case 3:
      comportement = new ComportementGregaire();
      break;

   case 4:   
   default:
      comportement = new ComportementMultiple();
      break;
   }

}

Bestiole::Bestiole( const Bestiole & b , int newx, int newy)
{
   x = newx;
   y = newy;
   camouflage = b.getCamouflage();
   carapace = b.getCarapace();
   nageoire = b.getNageoire();
   taille = b.getTaille();
   ageDeces = b.getAgeDeces();
   probabiliteDecesCollision = b.getProbabiliteDecesCollision();
   probabiliteClonage = b.getProbabiliteClonage();
   direction = modulo(b.getDirection() + M_PI, 2 * M_PI); // va dans la direction opposée à la bestiole passée en paramètre
   vitesse = b.getVitesse();
   bestiolesVoisines = vector<Bestiole*>();

   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );

   bestiolesVoisines = vector<Bestiole*>();

   switch (b.comportement->getComportementType())
   {
   case PEUR:
      comportement = new ComportementPeureuse();
      break;
   
   case PREV:
      comportement = new ComportementPrevoyante();
      break;

   case KAMIK:
      comportement = new ComportementKamikaze();
      break;

   case GREG:
      comportement = new ComportementGregaire();
      break;

   case MULTI:   
   default:
      comportement = new ComportementMultiple();
      break;
   }
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

void Bestiole::vieillir()
{
   ageDeces-=1;
}

void Bestiole::actualiserPosition( int xLim, int yLim )
{
   tuple<float, float> coupleDirectionVitesse = comportement->calculDirection(bestiolesVoisines, *this);//comportement.calculDirection();
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
   return sqrt(static_cast<float>(dx*dy + dy*dy));
}

//Accesseurs

void Bestiole::changerComportement(IComportement* newComp)
{
   comportement = newComp;
}

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

int Bestiole::getAgeDeces() const{
   return ageDeces;
}

void Bestiole::setAgeDeces(int date){
   ageDeces = date;
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

 // modulo
static float modulo(float x, float y) //y>0
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