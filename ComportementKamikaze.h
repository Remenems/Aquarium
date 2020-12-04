#ifndef _KAMIKAZE_H_
#define _KAMIKAZE_H_

#include "IComportement.h"

using namespace std;

class ComportementKamikaze : public IComportement
{
    public:
        tuple<float,float> calculDirection(vector<IPrototypeBestiole*> voisins);
};

#endif