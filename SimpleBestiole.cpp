#include "SimpleBestiole.h"

SimpleBestiole::SimpleBestiole() : Bestiole()
{}


SimpleBestiole::SimpleBestiole(float camouflage, float carapace, float nageoire, float taille, int ageDeces, float probabiliteDecesCollision, float probabiliteClonage, IComportement* comportement, float direction, float vitesse)
: Bestiole(camouflage,carapace,nageoire,taille,ageDeces,probabiliteDecesCollision,probabiliteClonage,comportement,direction,vitesse)
{
    
}

SimpleBestiole::SimpleBestiole(const Bestiole& bestiole)
: Bestiole(bestiole)
{
    
}

Bestiole* SimpleBestiole::clone(int x, int y)
{
    return new SimpleBestiole(*this);
}

vector<tuple<float,float>> SimpleBestiole::detecter()
{
    return vector<tuple<float,float>>();
}

bool SimpleBestiole::aiJeCeCapteur(CapteurType type)
{
    return false;
}
