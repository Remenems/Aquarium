#include "Yeux.h"
#include "Bestiole.h"
        
Bestiole* Yeux::clone()
{
    //TODO clone pour les oreilles
}

vector<Bestiole*> detecter()
{
 //TODO detecter pour les oreilles
}

bool Yeux::aiJeCeCapteur(CapteurType type)
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