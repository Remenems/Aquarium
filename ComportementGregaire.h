#ifndef _GREGAIRE_H_
#define _GREGAIRE_H_

#include "IComportement.h"
#include <vector>

using namespace std;

class ComportementGregaire : public IComportement
{
    public:
        ComportementGregaire();
        tuple<float,float> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee);
        ComportType getComportementType() { return GREG; };
};

#endif