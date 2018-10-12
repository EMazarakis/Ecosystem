#ifndef SEEDED_H
#define SEEDED_H

#include "plants.h"

//Seedless inherits from Plants
//Public Inheritance:
//public members of Plants are public members of Seedless
//protected members of Plants are protected members of Seedless
//Private members of Plants are not accessible from Seedless class directly,
//only through public/protected methods
class Seeded: public Plants
{
public:

    //Constructors (overloading)
    Seeded();
    Seeded(int FOL, int SEEDS, int SIZE, char TOKEN, int BREED, int ILL, int LIFE, int L_FACT);

 //Getters
    int getFoliage(void);
    int getSeeds(void);
    int getSize(void);

//Setters
    void setFoliage(int leafage);
    void setSeeds(int semen);
    void setSize(int dimension);

    void printMembersSeeded(void);

private:

    int foliage;
    int seeds;
    int size;
};

#endif // SEEDED_H
