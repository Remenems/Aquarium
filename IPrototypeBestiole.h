#ifndef _PROTOTYPE_BEST_H_
#define _PROTOTYPE_BEST_H_

/* interface du design pattern Prototype */
#include "Bestiole.h"

class Bestiole;

class IPrototypeBestiole
{
    public:
    virtual Bestiole* clone(int x, int y) = 0;
};

#endif