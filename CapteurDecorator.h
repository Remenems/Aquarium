#ifndef _CAPTEUR_DECORATOR_H_
#define _CAPTEUR_DECORATOR_H_

#include "Bestiole.h"
class CapteurDecorator : public Bestiole
{
    private:
        Bestiole* bestioleDecoreePtr;

    public:
        Bestiole* clone();
        virtual vector<Bestiole*> detecter() = 0;
        virtual bool aiJeCeCapteur(string capteur) = 0;
};

#endif