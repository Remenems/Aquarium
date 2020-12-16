#include "Oreille.h"
#include "Bestiole.h"

Oreille::Oreille(Bestiole* bestiole, float distance) : CapteurDecorator(bestiole)
{
    distanceOuie = distance;
}

Oreille::~Oreille()
{
    
}
        
Bestiole* Oreille::clone()
{
    Bestiole* bClone = bestioleDecoreePtr->clone();
    return new Oreille(bClone, distanceOuie);
}

vector<tuple<float,float>> Oreille::detecter()
{
    vector<tuple<float,float>> result = bestioleDecoreePtr->detecter();
    result.push_back(make_tuple(distanceOuie,2*M_PI));
    return result;
}

bool Oreille::aiJeCeCapteur(CapteurType type)
{
    if(type == Oreilles)
    {
        return true;
    }
    else
    {
        return bestioleDecoreePtr->aiJeCeCapteur(type);
    }
}