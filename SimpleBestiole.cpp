#include "SimpleBestiole.h"

SimpleBestiole::SimpleBestiole() : Bestiole()
{}


SimpleBestiole::SimpleBestiole(float camouflage, float carapace, float nageoire, float taille, int ageDeces, float probabiliteDecesCollision, float probabiliteClonage, IComportement* comportement, float direction, float vitesse)
: Bestiole(camouflage,carapace,nageoire,taille,ageDeces,probabiliteDecesCollision,probabiliteClonage,comportement,direction,vitesse)
{
    
}

SimpleBestiole::SimpleBestiole(const Bestiole& bestiole)
: Bestiole(bestiole, 0,0)
{
    
}

Bestiole* SimpleBestiole::clone()
{
    //on clone la bestiole
    return new SimpleBestiole(*this);
}

vector<tuple<float,float>> SimpleBestiole::detecter()
{
    //la simple bestiole n'a pas de capteurs donc n'est pas capable de détecter une autre personne
    return vector<tuple<float,float>>();
}

bool SimpleBestiole::aiJeCeCapteur(CapteurType type)
{
    //la bestiole simple n'a pas de capteur par définition
    return false;
}
