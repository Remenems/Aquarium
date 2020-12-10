#include "SimpleBestiole.h"


SimpleBestiole::SimpleBestiole(float camouflage, float carapace, float nageoire, float taille, int dateDeces, float probabiliteDecesCollision, float probabiliteClonage, IComportement& comportement, float direction, float vitesse, T* couleur)
{
    this->setX(0);
    this->setY(0);
    this->changerCamouflage(camouflage);
    this->changerCarapace(carapace);
    this->changerNageoire(nageoire);
    this->setTaille(taille);
    this->setDateDeces(dateDeces);
    this->setProbabiliteDecesCollision(probabiliteDecesCollision);
    this->setProbabiliteClonage(probabiliteClonage);
    this->setDirection(direction);
    this->setVitesse(vitesse);
    this->setCouleur(couleur);
    //this->changerComportement(comportement);
    
}

SimpleBestiole::SimpleBestiole(const Bestiole& bestiole)
{
    this->setX(bestiole.getX());
    this->setY(bestiole.getY());
    this->changerCamouflage(bestiole.getCamouflage());
    this->changerCarapace(bestiole.getCarapace());
    this->changerNageoire(bestiole.getNageoire());
    this->setTaille(bestiole.getTaille());
    this->setDateDeces(bestiole.getDateDeces());
    this->setProbabiliteDecesCollision(bestiole.getProbabiliteDecesCollision());
    this->setProbabiliteClonage(bestiole.getProbabiliteClonage());
    this->setDirection(bestiole.getDirection());
    this->setVitesse(modulo(bestiole.getVitesse() + M_PI, 2*M_PI));
    this->setCouleur(bestiole.getCouleur());
    //this->changerComportement(bestiole.getcomportement);
}

Bestiole* SimpleBestiole::clone()
{
    return &SimpleBestiole(*this);
}

vector<Bestiole*> SimpleBestiole::detecter()
{
    return vector<Bestiole*>();
}

bool SimpleBestiole::aiJeCeCapteur(string capteur)
{
    return false;
}

//fct modulo

float modulo(float x, float y) //y>0
{
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
