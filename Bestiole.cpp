#include "Bestiole.h"

#include "Milieu.h"

#include "IComportement.h"

#include <cstdlib>
#include <cmath>
#include <tuple>

const double MAX_VITESSE = 10.;

Bestiole::Bestiole()
{
   x = 0;
   y = 0;
   cumulX = 0;
   cumulY = 0;
   camouflage = static_cast<double>( rand() )/RAND_MAX * (1 /*Différence entre le cam max et le cam min*/)/*+cam min*/;
   /* idem pour tous les autres */ //TODO constructeur sans arguments, initialisation aléatoir
   carapace =  static_cast<double>( rand() )/RAND_MAX ;
   nageoire = static_cast<double>( rand() )/RAND_MAX ;
   taille = static_cast<double>( rand() )/RAND_MAX ;
   dateDeces = rand() % 1000;
   probabiliteDecesCollision = static_cast<double>( rand() )/RAND_MAX ;
   probabiliteClonage = static_cast<double>( rand() )/RAND_MAX ;

   direction = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;
}

Bestiole::Bestiole(float cam, float car, float nag, float tai, int daDeces, float probaDecesCollision, float probaClonage, IComportement& comport, float dir, float vit)
{
   x = 0;
   y = 0;
   cumulX = 0;
   cumulY = 0;

   camouflage = cam;
   carapace = car;
   nageoire = nag;
   taille = tai;
   dateDeces = daDeces;
   probabiliteDecesCollision = probaDecesCollision;
   probabiliteClonage = probaClonage;

   direction = dir;
   vitesse = vit;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   comportement = &comport;
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
   direction = modulo(b.getDirection() + M_PI, 2 * M_PI); // va dans la direction opposée à la bestiole passée en paramètre
   vitesse = b.getVitesse();

   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );

   //TODO initialiser le comportement de la bonne manière (même que celui de la bestiole originale)
   comportement = new ComportementGregaire(this);
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
   tuple<float, float> coupleDirectionVitesse = comportement->calculDirection(bestiolesVoisines);//comportement.calculDirection();
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