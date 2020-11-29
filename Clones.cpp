#include "Clones.h"

/*Clones( void )
{
     A compléter quand on aura fait les comportements 
}*/

IPrototypeBestiole Clones::getGregaire() const
{
    return this->bestioleGregaire;
}

IPrototypeBestiole Clones::getPeureuse() const
{
    return this->bestiolePeureuse;
}

IPrototypeBestiole Clones::getKamikaze() const
{
    return this->bestioleKamikaze;
}

IPrototypeBestiole Clones::getPrevoyante() const
{
    return this->bestiolePrevoyante;
}

IPrototypeBestiole Clones::getMultiple() const
{
    return this->bestioleMultiple;
}