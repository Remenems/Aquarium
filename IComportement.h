#ifndef _ICOMP_H_
#define _ICOMP_H_

#include <iostream>
#include <vector>
#include "Bestiole.h"

using namespace std;

class IComportement
{
    protected:
        Bestiole& bestioleAssociee;
    public:
        IComportement(Bestiole& bestioleAss) : bestioleAssociee(bestioleAss){};
        virtual tuple<float,float> calculDirection(vector<Bestiole*> voisins) = 0;
};

#endif