#ifndef _KAMIKAZE_H_
#define _KAMIKAZE_H_

#include "IComportement.h"

using namespace std;

class ComportementKamikaze : public IComportement
{
    public:
        ComportementKamikaze(Bestiole& bestioleAss) : IComportement(bestioleAss){};
        tuple<float,float> calculDirection(vector<Bestiole*> voisins);
    
    private:
        static const int coefficientFonce = 3;
};

#endif