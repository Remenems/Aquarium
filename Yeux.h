#ifndef _YEUX_H_
#define _YEUX_H_

#include "CapteurDecorator.h"
class Yeux : public CapteurDecorator
{
    private:
        float champAngulaire;
        float distanceVision;
    public:
        Yeux(Bestiole* bestiole, float distance, float angle);
        ~Yeux();
        Bestiole* clone(int x, int y);
        vector<tuple<float,float>> detecter();
        bool aiJeCeCapteur(CapteurType type);
};

#endif