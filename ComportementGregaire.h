#ifndef _GREGAIRE_H_
#define _GREGAIRE_H_

#include "IComportement.h"

using namespace std;

class ComportementGregaire : public IComportement
{
    public:
        ComportementGregaire(Bestiole& bestioleAss) : IComportement(bestioleAss){};
        tuple<float,float> calculDirection(vector<Bestiole*> voisins);
};

#endif