#ifndef _CLONES_H_
#define _CLONES_H_

#include "IPrototypeBestiole.h"

class Clones
{
    private :
        IPrototypeBestiole bestioleGregaire;
        IPrototypeBestiole bestiolePeureuse;
        IPrototypeBestiole bestioleKamikaze;
        IPrototypeBestiole bestiolePrevoyante;
        IPrototypeBestiole bestioleMultiple;

    public :
        /*
        A ajouter quand les comportements seront faits
        Clones( void );*/

        IPrototypeBestiole getGregaire() const;
        IPrototypeBestiole getPeureuse() const;
        IPrototypeBestiole getKamikaze() const;
        IPrototypeBestiole getPrevoyante() const;
        IPrototypeBestiole getMultiple() const;
};