#ifndef _SIMPLE_BESTIOLE_H_
#define _SIMPLE_BESTIOLE_H_

#include "Bestiole.h"
#include <iostream>

class SimpleBestiole : public Bestiole
{
    public:
        SimpleBestiole(float camouflage, float carapace, float nageoire, float taille, int dateDeces, float probabiliteDecesCollision, float probabiliteClonage, IComportement& comportement, float direction, float vitesse, T* couleur);
        SimpleBestiole(const Bestiole& bestiole);
        Bestiole* clone();
        vector<Bestiole*> detecter();
        bool aiJeCeCapteur(string capteur);

};

#endif