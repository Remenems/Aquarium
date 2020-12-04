#include "ComportementGregaire.h"

#include <tuple>

using namespace std;

tuple<float,float> ComportementGregaire::calculDirection(vector<Bestiole*> voisins)
{
    if(voisins.size() == 0)
    {
        float direction = bestioleAssociee.getDirection();
        return make_tuple(direction,1);
    }
    else
    {
        // Calcul des directions moyennes (moyenne pondérée par les vitesses) des bestioles voisines
        float sommeDirect = 0;
        float sommeVitess = 0;

        for(int i = 0; i<voisins.size(); i++)
        {
            sommeDirect += (voisins.at(i)->getDirection() * voisins.at(i)->getVitesse());
            sommeVitess += voisins.at(i)->getVitesse();
        }
        float moyenne = sommeDirect / sommeVitess;
        // Retourne la direction moyenne, et une vitesse x1
        return make_tuple(moyenne,1);
    }
    
    
}
