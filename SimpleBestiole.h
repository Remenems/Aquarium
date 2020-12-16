#ifndef _SIMPLE_BESTIOLE_H_
#define _SIMPLE_BESTIOLE_H_

#include "Bestiole.h"
#include <iostream>

class SimpleBestiole : public Bestiole
{
    public:
        SimpleBestiole( void );
        SimpleBestiole(float camouflage, float carapace, float nageoire, float taille, int ageDeces, float probabiliteDecesCollision, float probabiliteClonage, IComportement* comportement, float direction, float vitesse);
        SimpleBestiole(const Bestiole& bestiole);
        Bestiole* clone();
        vector<tuple<float,float>> detecter();
        bool aiJeCeCapteur(CapteurType type);

};

#endif