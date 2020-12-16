#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_

#include "IComportement.h"
#include <vector>
#include <tuple>

using namespace std;

class ComportementPeureuse : public IComportement
{
    public:
        ComportementPeureuse(int seuil);
        ComportementPeureuse();
        ~ComportementPeureuse();
        tuple<float,float> calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee);
        ComportType getComportementType() { return PEUR; };
        int getSeuil();
    private:
        int seuilAvantPeur;
};

#endif