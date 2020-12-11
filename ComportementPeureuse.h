#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_

#include "IComportement.h"

using namespace std;

class ComportementPeureuse : public IComportement
{
    public:
        ComportementPeureuse(Bestiole* bestioleAss) : IComportement(bestioleAss){};
        tuple<float,float> calculDirection(vector<Bestiole*> voisins);

    private:
        int seuilAvantPeur;
};

#endif