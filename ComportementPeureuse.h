#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_

#include "IComportement.h"

using namespace std;

class ComportementPeureuse : public IComportement
{
    public:
        ComportementPeureuse() : IComportement(){};
        tuple<float,float> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee);

    private:
        int seuilAvantPeur;
};

#endif