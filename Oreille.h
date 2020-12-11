#ifndef _OREILLE_H_
#define _OREILLE_H_

#include "CapteurDecorator.h"
class Oreille
{
    private:
        float distanceOuie;
    public:
        Bestiole* clone();
        vector<Bestiole*> detecter();
        bool aiJeCeCapteur(CapteurType type);
};


#endif