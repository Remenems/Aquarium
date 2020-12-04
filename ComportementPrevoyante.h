#ifndef _PREVOYANTE_H_
#define _PREVOYANTE_H_

#include "IComportement.h"

using namespace std;

class ComportementPrevoyante : public IComportement
{
    public:
        tuple<float,float> calculDirection(vector<IPrototypeBestiole*> voisins);
};

#endif