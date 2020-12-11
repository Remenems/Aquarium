#ifndef _CMULTIPLE_H_
#define _CMULTIPLE_H_

#include "IComportement.h"

#include "ComportementPeureuse.h"
#include "ComportementGregaire.h"
#include "ComportementKamikaze.h"
#include "ComportementPrevoyante.h"

#include <vector>

using namespace std;

class ComportementMultiple : public IComportement
{
    public:
        ComportementMultiple(Bestiole* bestioleAss);
        tuple<float,float> calculDirection(vector<Bestiole*> voisins);

    private:
        vector<IComportement> comportements;
        
        IComportement* comportementActif;
        int tempsAvantChangementDeComportement;

        static const int tempsEntreDeuxChangementsDeComportement = 10;
};

#endif