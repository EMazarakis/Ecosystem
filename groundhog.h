#ifndef GROUNDHOG_H
#define GROUNDHOG_H

#include "herbivores.h"

class Groundhog : public Herbivores
{
public:
    Groundhog();
    int Eat(Animals *animalEaten, Plants *plantEaten);
};

#endif // GROUNDHOG_H
