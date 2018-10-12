#ifndef PLANTS_H
#define PLANTS_H

#include <iostream>
using namespace std;


class Plants
{
public:

//Constructors (overloading)
    Plants();
    Plants(char TOKEN, int BREED, int ILL, int LIFE,int L_FACT);

//virtual functions

    virtual int getFoliage(void);
    virtual int getSeeds(void);
    virtual int getSize(void);
    virtual void setFoliage(int leafage);
    virtual void setSeeds(int semen);
    virtual void setSize(int dimension);

    virtual  void loseLife(int eatenLife);

//getters
    char *getName();
    int getX();
    int getY();
    char getToken();
    int getBreedProb();
    int getIllProb();
    int getLife();
    int getLifeFactor();

//setters
    void setName(char *plantName);
    void setX(int x);
    void setY(int y);
    void setToken(char plantSymbol);
    void setBreedProb(int Bprob);
    void setIllProb(int Iprob);
    void setLife(int plantLife);
    void setLifeFactor(int changeLife);

    void printMembersPlants(void);

private:
    char *name;
    int x_y[2];         //Represent the coordinates of the Plant into the  grid
    char token;         //Symdol which represents the plant into  the grid
    int breedingProb;   //Breeding probability per season
    int illnessProb;    //Ilness probability per season
    int life;           //Dead :life == 0
    int lifeFactor;     //
};


#endif // PLANTS_H
