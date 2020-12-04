#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_

#include "IComportement.h"

using namespace std;

class ComportementPeureuse : public IComportement
{
    public:
        tuple<float,float> calculDirection(vector<IPrototypeBestiole*> voisins);

    private:
        int seuilAvantPeur;
};

#endif