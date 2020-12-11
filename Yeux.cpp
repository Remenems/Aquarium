#include "Yeux.h"
#include "Bestiole.h"
        
Bestiole* Yeux::clone()
{
    //TODO clone pour les yeux
}

vector<Bestiole*> detecter()
{
 //TODO detecter pour les yeux
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