#ifndef HERBIVORES_H
#define HERBIVORES_H

#include "animals.h"


class Herbivores : public Animals
{
public:
    //Overloading Constructors
    Herbivores();
    Herbivores(int SIZE, int SPEED, int NEEDED_FOOD, int CAN_CLIMB, int EAT_COUNT, char TOK);

//setters
    void setToken(char tok);
    void setCanClimb(int climb);
    void setNeededFood(int nFood);

//getters
    char getToken(void);
    int getCanClimb(void);
    int getNeededFood(void);

     void printMembersHerbivores(void);


private:

    char token;
    bool canClimb;
    int neededFood;

};


#endif // HERBIVORES_H
