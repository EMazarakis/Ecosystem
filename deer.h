#ifndef DEER_H
#define DEER_H


#include "herbivores.h"

class Deer : public Herbivores
{
public:

    Deer();
    int Eat(Animals *animalEaten, Plants *plantEaten);
};

#endif // DEER_H
