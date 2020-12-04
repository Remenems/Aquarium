#ifndef _ICOMP_H_
#define _ICOMP_H_

#include <iostream>
#include <vector>
#include "IPrototypeBestiole.h"

using namespace std;

class IComportement
{
    virtual tuple<float,float> calculDirection(vector<IPrototypeBestiole*> voisins) = 0;
};

#endif