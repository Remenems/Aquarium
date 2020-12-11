#ifndef _CAPTEUR_DECORATOR_H_
#define _CAPTEUR_DECORATOR_H_

#include "Bestiole.h"
class CapteurDecorator : public Bestiole
{
    protected:
        Bestiole* bestioleDecoreePtr;

    public:
        CapteurDecorator(Bestiole* bestiole) : bestioleDecoreePtr(bestiole) {} ;
        Bestiole* clone() = 0;
        virtual vector<tuple<float,float>> detecter() = 0;
        virtual bool aiJeCeCapteur(string capteur) = 0;
};

#endif