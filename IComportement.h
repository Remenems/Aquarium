#ifndef _ICOMP_H_
#define _ICOMP_H_

#include <iostream>
#include <vector>
#include "Bestiole.h"

#include "ComportementGregaire.h"
#include "ComportementPeureuse.h"
#include "ComportementKamikaze.h"
#include "ComportementPrevoyante.h"
#include "ComportementMultiple.h"

using namespace std;

class IComportement
{
    protected:
        Bestiole& bestioleAssociee;
    public:
        IComportement(Bestiole* b) { bestioleAssociee = &b; };
        virtual tuple<float,float> calculDirection(vector<Bestiole*> voisins) = 0;
};

#endif