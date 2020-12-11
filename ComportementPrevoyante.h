#ifndef _PREVOYANTE_H_
#define _PREVOYANTE_H_

#include "IComportement.h"

using namespace std;

class ComportementPrevoyante : public IComportement
{
    public:
        ComportementPrevoyante(Bestiole* bestioleAss) : IComportement(bestioleAss){};
        tuple<float,float> calculDirection(vector<Bestiole*> voisins);
};

#endif