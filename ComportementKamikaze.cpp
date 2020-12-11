#include "ComportementKamikaze.h"

#include <tuple>
#include <math.h>

using namespace std;

const int ComportementKamikaze::coefficientFonce = 3;

tuple<float,float> ComportementKamikaze::calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee)
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
        for(long unsigned int i = 0; i< voisins.size();i++)
        {
            float distance = bestioleAssociee.distanceEntreBestioles(*(voisins.at(i)));
            if(distance < minDist)
            {
                minDist = distance;
                minIndex = i;
            }
        }
        //retourne la direction pour atteindre la bestiole la plus proche, et une vitesse x3
        float diffY = voisins.at(minIndex)->getY() - bestioleAssociee.getY();
        float diffX = voisins.at(minIndex)->getX() - bestioleAssociee.getX();
        
        float direction = (diffX==0)? M_PI/2 : atan(diffY / diffX) ;
        return make_tuple(direction,coefficientFonce);
    }
}
