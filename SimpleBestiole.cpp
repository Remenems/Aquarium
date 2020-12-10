#include "SimpleBestiole.h"


SimpleBestiole::SimpleBestiole(float camouflage, float carapace, float nageoire, float taille, int dateDeces, float probabiliteDecesCollision, float probabiliteClonage, IComportement& comportement, float direction, float vitesse, T* couleur)
: Bestiole(camouflage,carapace,nageoire,taille,dateDeces,probabiliteDecesCollision,probabiliteClonage,comportement,direction,vitesse,couleur)
{
    
}

SimpleBestiole::SimpleBestiole(const Bestiole& bestiole)
: Bestiole(bestiole)
{
    
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
