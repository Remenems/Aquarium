#ifndef _CMULTIPLE_H_
#define _CMULTIPLE_H_

#include "IComportement.h"

using namespace std;

class ComportementMultiple : public IComportement
{
    public:
        tuple<float,float> calculDirection(vector<IPrototypeBestiole*> voisins);

    private:
        IComportement comportementPeureuse;
        IComportement comportementGregaire;
        IComportement comportementPrevoyante;
        IComportement comportementKamikaze;

        IComportement comportementActif;
        int tempsAvantChangementDeComportement;
};

#endif