#include "ComportementKamikaze.h"

#include <tuple>
#include <math.h>

using namespace std;

tuple<float,float> ComportementKamikaze::calculDirection(vector<Bestiole*> voisins)
{
    //Recherche de la bestiole la plus proche (Calcul de la distance à partir des x,y)
    if(voisins.size() == 0)
    {
        return make_tuple(bestioleAssociee.getDirection(), bestioleAssociee.getVitesse());
    }
    else
    {
        float minDist = MAXFLOAT;
        int minIndex = -1;
        for(int i = 0; i< voisins.size();i++)
        {
            float distance = bestioleAssociee.distanceEntreBestioles(voisins.at(i));
            if(distance < minDist)
            {
                minDist = distance;
                minIndex = i;
            }
        }
        //retourne la direction pour atteindre la bestiole la plus proche, et une vitesse x3
        float diffY = get<1>(voisins.at(minIndex)->getPosition()) - get<1>(bestioleAssociee.getPosition());
        float diffX = get<0>(voisins.at(minIndex)->getPosition()) - get<0>(bestioleAssociee.getPosition());
        float direction;
        if(diffX == 0)
        {
            float direction = M_PI / 2;
        }
        else
        {
            float direction = atan(diffY / diffX);
        }    
        return make_tuple(direction,coefficientFonce);
    }
}