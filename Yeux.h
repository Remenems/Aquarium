#ifndef _YEUX_H_
#define _YEUX_H_

#include "CapteurDecorator.h"
class Yeux : public CapteurDecorator
{
    private:
        float champAngulaire;
        float distanceVision;
    public:
        Bestiole* clone();
        vector<Bestiole*> detecter();
        bool aiJeCeCapteur(CapteurType type);
};

#endif