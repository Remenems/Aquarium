#include "Clones.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Clones::Clones( int clock )
{
    bestioleGregaire = new SimpleBestiole(0,1,1,1,clock + 100, 0.5, 0.005, new ComportementGregaire(), M_PI, 2);
    bestiolePeureuse = new SimpleBestiole(0,1,1,1,clock + 100, 0.5, 0.005, new ComportementPeureuse(), M_PI, 2);
    bestioleKamikaze = new SimpleBestiole(0,1,1,1,clock + 100, 0.5, 0.005, new ComportementKamikaze(), M_PI, 2);
    bestiolePrevoyante = new SimpleBestiole(0,1,1,1,clock + 100, 0.5, 0.005, new ComportementPrevoyante(), M_PI, 2);
    bestioleMultiple = new SimpleBestiole(0,1,1,1,clock + 100, 0.5, 0.005, new ComportementMultiple(), M_PI, 2);
}

Bestiole* Clones::getGregaire() const
{
    return this->bestioleGregaire;
}

Bestiole* Clones::getPeureuse() const
{
    return this->bestiolePeureuse;
}

Bestiole* Clones::getKamikaze() const
{
    return this->bestioleKamikaze;
}

Bestiole* Clones::getPrevoyante() const
{
    return this->bestiolePrevoyante;
}

Bestiole* Clones::getMultiple() const
{
    return this->bestioleMultiple;
}