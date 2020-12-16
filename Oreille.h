#ifndef _OREILLE_H_
#define _OREILLE_H_

#include "CapteurDecorator.h"
class Oreille : public CapteurDecorator
{
    protected:
        float distanceOuie;
    public:
        Oreille(Bestiole* bestiole, float distance);
        ~Oreille();
        Bestiole* clone();
        vector<tuple<float,float>> detecter();
        bool aiJeCeCapteur(CapteurType type);
};


#endif