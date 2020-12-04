#ifndef _GREGAIRE_H_
#define _GREGAIRE_H_

#include "IComportement.h"

using namespace std;

class ComportementGregaire : public IComportement
{
    public:
        tuple<float,float> calculDirection(vector<IPrototypeBestiole*> voisins);
};

#endif