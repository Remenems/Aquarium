#ifndef _CLONES_H_
#define _CLONES_H_

#include "Bestiole.h"
#include "IPrototypeBestiole.h"
#include "SimpleBestiole.h"

class Clones
{
    private :
        Bestiole* bestioleGregaire;
        Bestiole* bestiolePeureuse;
        Bestiole* bestioleKamikaze;
        Bestiole* bestiolePrevoyante;
        Bestiole* bestioleMultiple;

    public :
        Clones();

        Bestiole* getGregaire() const;
        Bestiole* getPeureuse() const;
        Bestiole* getKamikaze() const;
        Bestiole* getPrevoyante() const;
        Bestiole* getMultiple() const;
};

#endif