#ifndef SEEDLESS_H
#define SEEDLESS_H

#include "plants.h"

//Seedless inherits from Plants
//Public Inheritance:
//public members of Plants are public members of Seedless
//protected members of Plants are protected members of Seedless
//Private members of Plants are not accessible from Seedless class directly,
//only through public/protected methods
class Seedless: public Plants
{
public:

    //Constructor (overloading)
    Seedless();
    Seedless(int TOKEN, int BREED, int ILL, int LIFE, int L_FACT);

//Declaring the methods of the class
    void growthPlant(int flag);     //success OR failure of growthing

    void loseLife(int eatenLife);            //When plant is eaten by animal

    void breedPlant(void);
};

#endif // SEEDLESS_H
