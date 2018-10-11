#include "wolf.h"

#define WOLF_SIZE 1
#define WOLF_ATTACK 2
#define WOLF_DEFENCE 2
#define WOLF_SPEED 2
#define WOLF_NEEDED_FOOD 2

#define ADULT_WOLF_SIZE 7
#define ADULT_WOLF_ATTACK 8
#define ADULT_WOLF_DEFENCE 6
#define ADULT_WOLF_SPEED 8
#define ADULT_WOLF_NEEDED_FOOD 8

#define WOLF_HIBERNATION false



Wolf::Wolf() : Carnivores(WOLF_SIZE, WOLF_ATTACK, WOLF_DEFENCE, WOLF_SPEED, WOLF_NEEDED_FOOD, WOLF_HIBERNATION, 'W')
{
//HACK:You can pass the arguments through the setters methods
}


int Wolf::Eat(Animals *animalEaten, Plants *plantEaten){

    char animalToken = animalEaten->getAnimalToken();

    if( animalToken == this->getAnimalToken() ){    //Same kind of animals

        cout << "Same kind of animals. Cannibalism is forbidden." << endl;
        return 0;
    }
    else{

        if( animalToken == 'S' ){    //Wolf did not eat Salmon

            cout << "Wolf did not eat Salmon." << endl;
            return 0;
        }
        else if( animalToken == 'D' ||animalToken == 'R' || animalToken == 'G'){
            //Wolf eats all the herbivores animals except Salmon

            if( (this->getSizeAnimal() >= animalEaten->getSizeAnimal()) && (this->getSpeedAnimal() > animalEaten->getSpeedAnimal()) ){

                this->setEatenFoodAnimal( this->getEatCountAnimal() + this->getEatenFoodAnimal() );
                this->setIsHungry(false);
                animalEaten->setIsAlive(false); //the eaten animal is dead now
                cout << "Wolf ate." << endl;
                return 1;   //is full
            }
            //return 0;
        }
        else{   //the other animal is carnivore. I suspect fight

            if( (this->getSizeAnimal() > animalEaten->getSizeAnimal()) || ( this->getSizeAnimal() == animalEaten->getSizeAnimal()  &&  this->getAttack() > animalEaten->getDefence() ) ){

                this->setEatenFoodAnimal( this->getEatCountAnimal() + this->getEatenFoodAnimal() );
                this->setIsHungry(false);
                animalEaten->setIsAlive(false); //the eaten animal is dead now
                cout << "Wolf ate." << endl;
                return 1;   //is full
           }
        }
    }

    return 0;
}
