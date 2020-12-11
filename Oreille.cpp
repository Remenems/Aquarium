#include "Oreille.h"
#include "Bestiole.h"

Oreille::Oreille(Bestiole* bestiole, float distance) : CapteurDecorator(bestiole)
{
    distanceOuie = distance;
}

Oreille::~Oreille()
{
    delete bestioleDecoreePtr;
}
        
Bestiole* Oreille::clone(int x, int y)
{
    Bestiole* bClone = bestioleDecoreePtr->clone(x,y);
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