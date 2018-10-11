#ifndef SEEDED_H
#define SEEDED_H


#include "plants.h"
#include <iostream>
using namespace std;

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
