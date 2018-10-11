#ifndef GRASS_H
#define GRASS_H

#include "seedless.h"


//Grass inherits from Seedless
//Public Inheritance:
//public members of Seedless are public members of Grass
//protected members of Seedless are protected members of Grass
//Private members of Seedless are not accessible from Grass class directly,
//only through public/protected methods
class Grass: public Seedless
{
public:
    Grass();

};

#endif // GRASS_H

