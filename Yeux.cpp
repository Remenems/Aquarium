#include "Yeux.h"
#include "Bestiole.h"

Yeux::Yeux(Bestiole* bestiole, float distance, float angle) : CapteurDecorator(bestiole)
{
    distanceVision = distance;
    champAngulaire = angle;
}
        
Bestiole* Yeux::clone(int x, int y)
{
    Bestiole* bClone = bestioleDecoreePtr->clone(x,y);
    return new Yeux(bClone, distanceVision, champAngulaire);
    
}

vector<tuple<float,float>> Yeux::detecter()
{
    vector<tuple<float,float>> result = bestioleDecoreePtr->detecter();
    result.push_back(make_tuple(distanceVision,champAngulaire));
    return result;
}

bool Yeux::aiJeCeCapteur(CapteurType type)
{
    if(type == Oeil)
    {
        return true;
    }
    else
    {
        return bestioleDecoreePtr->aiJeCeCapteur(type);
    }
}