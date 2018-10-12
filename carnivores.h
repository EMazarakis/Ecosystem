#ifndef CARNIVORES_H
#define CARNIVORES_H


#include"animals.h"

class Carnivores : public Animals
{
public:
    //Constuctors overloading
    Carnivores();
    Carnivores(int SIZE, int ATTACK, int DEFENCE, int SPEED, int NEEDED_FOOD, int HIBERNATION, char TOK);


    //setters
    void setAttack(int attck);
    void setDefence(int defnce);
    void setToken(char tok);
    void setCanClimb(int climb);
    void setNeededFood(int nFood);

    //getters
    int getAttack(void);
    int getDefence(void);
    char getToken(void);
    int getCanClimb(void);
    int getNeededFood(void);

    void printMembersCarnivores(void);

private:

    int attack;
    int defence;

    char token;
    bool canClimb;
    int neededFood;

};

#endif // CARNIVORES_H
