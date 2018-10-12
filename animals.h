#ifndef ANIMALS_H
#define ANIMALS_H

#include "plants.h"
#include <stdlib.h> //srand, rand, abs

class Animals
{
public:

    //Constructors Overloading
    Animals();
    Animals(int SIZE, int SPEED, int EAT_COUNT, bool HIBERNATION, char TOK);

    //virtual keyword only at the header file
    virtual void printMembersHerbivores(void);
    virtual void printMembersCarnivores(void);
    virtual char getToken(void);

    virtual void setAttack(int attck);
    virtual void setDefence(int defnce);
    virtual int getAttack(void);
    virtual int getDefence(void);


//TODO: FOR THE BELOW 3
    void Move(void);
    virtual int Eat(Animals *animalEaten, Plants *plantEaten);
    void Raise(void);

//setters
    void setNameAnimal(char *nameAnimal);
    void setSizeAnimal(int sizeAnimal);
    void setHungerCountAnimal(int hungerCountAnimal);
    void setEatenFoodAnimal(int eatenFoodAnimal);
    void setEatCountAnimal(int eatCountAnimal);
    void setX_Animal(int xAnimal);
    void setY_Animal(int yAnimal);
    void setSpeedAnimal(int speedAnimal);
    void setIsAlive(bool alive);
    void setIsHungry(bool hungry);
    void setInHeat(bool heat);
    void setInHibernation(bool hibernation);
    void setHibernates(bool hibernts);
    void setAnimalToken(char tok);

//getters
    char *getNameAnimal(void);
    int  getSizeAnimal(void);
    int  getHungerCountAnimal(void);
    int  getEatenFoodAnimal(void);
    int  getEatCountAnimal(void);
    int  getX_Animal(void);
    int  getY_Animal(void);
    int  getSpeedAnimal(void);
    bool getIsAlive(void);
    bool getIsHungry(void);
    bool getInHeat(void);
    bool getInHibernation(void);
    bool getHibernates(void);
    char getAnimalToken(void);

    void printMembersAnimals(void);


private:

    char *name;
    int size;
    int hungerCount;
    int eatenFood;
    int eatCount;
    int x_y[2];
    int speed;
    char animalToken;

    bool isAlive;
    bool isHungry;
    bool inHeat;
    bool inHibernation;

    bool hibernates;

};

#endif // ANIMALS_H
