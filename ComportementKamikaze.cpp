#include "ComportementKamikaze.h"

#include <tuple>
#include <math.h>

using namespace std;

const int ComportementKamikaze::coefficientFonce = 3;

tuple<float,float> ComportementKamikaze::calculDirection(vector<Bestiole*> voisins, Bestiole& bestioleAssociee)
{
    //si pas de voisins détectés, on ne change ni la direction ni la vitesse
    if(voisins.size() == 0)
    {
        return make_tuple(bestioleAssociee.getDirection(), bestioleAssociee.getVitesse());
    }
    else
    {
        //Recherche de la bestiole la plus proche parmi les voisines détectées (Calcul de la distance à partir des x,y)
        float minDist = MAXFLOAT;
        int minIndex = -1;
        for(long unsigned int i = 0; i< voisins.size();i++)
        {
            float distance = bestioleAssociee.distanceEntreBestioles(*(voisins.at(i)));
            //si la bestiole est pour le moment la plus proche on la retient pour avoir au final la plus proche
            if(distance < minDist)
            {
                minDist = distance;
                minIndex = i;
            }
        }
        //retourne la direction pour atteindre la bestiole la plus proche, et une vitesse x3
        float diffY = voisins.at(minIndex)->getY() - bestioleAssociee.getY();
        float diffX = voisins.at(minIndex)->getX() - bestioleAssociee.getX();
        //on cherche à atteindre la position actuelle de la bestiole sans prévoir ces prochains déplacements
        float direction = (diffX==0)? M_PI/2 : atan(diffY / diffX) ;
        return make_tuple(direction,coefficientFonce);
    }
}
