#ifndef _ICOMP_H_
#define _ICOMP_H_

//#include <iostream>
#include <vector>
#include "Bestiole.h"

using namespace std;

class Bestiole;

class IComportement
{
    public:
        IComportement();
        virtual ~IComportement();
        virtual tuple<float,float> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee) = 0;
};

#endif