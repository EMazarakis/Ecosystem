#ifndef WOLF_H
#define WOLF_H

#include "carnivores.h"

class Wolf : public Carnivores

{
public:
    Wolf();
    int Eat(Animals *animalEaten, Plants *plantEaten);

};


#endif // WOLF_H
