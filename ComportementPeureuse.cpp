#include "ComportementPeureuse.h"

#include <tuple>

using namespace std;

tuple<float,float> ComportementPeureuse::calculDirection(vector<Bestiole*> voisins)
{
    if(voisins.size() >= ComportementPeureuse::seuilAvantPeur)
    {
        //La bestiole change de direction, va dans la direction opposée aux bestioles voisines, à une vitesse x2
        float moyenneDirection = 0;
        for(int i = 0; i<voisins.size(); i++)
        {
            moyenneDirection += voisins.at(i)->getDirection() / voisins.size();
        }
        return make_tuple(moyenneDirection /* nvelle directon*/, 2);
    }
    else
    {
        //Ne change pas de direction
        return make_tuple(bestioleAssociee.getDirection(), 1);
    }
    
    return make_tuple(0,0);
}
