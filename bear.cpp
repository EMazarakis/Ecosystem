#include "bear.h"


#define BEAR_SIZE 3
#define BEAR_ATTACK 6
#define BEAR_DEFENCE 6
#define BEAR_SPEED 4
#define BEAR_NEEDED_FOOD 5

#define ADULT_BEAR_SIZE 10
#define ADULT_BEAR_ATTACK 10
#define ADULT_BEAR_DEFENCE 10
#define ADULT_BEAR_SPEED 4
#define ADULT_BEAR_NEEDED_FOOD 10

#define BEAR_HIBERNATION true

Bear::Bear() : Carnivores(BEAR_SIZE, BEAR_ATTACK, BEAR_DEFENCE, BEAR_SPEED, BEAR_NEEDED_FOOD, BEAR_HIBERNATION, 'B')
{
//HACK:You can pass the arguments through the setters methods
}



int Bear::Eat(Animals *animalEaten, Plants *plantEaten){

    char animalToken = animalEaten->getAnimalToken();

    if( animalToken == this->getAnimalToken() ){    //Same kind of animals

        cout << "Same kind of animals. Cannibalism is forbidden." << endl;
        return 0;
    }
    else{

        //Bear eats all the herbivores animals
        if( animalToken == 'D' ||animalToken == 'R' || animalToken == 'G' || animalToken == 'S' ){

            this->setEatenFoodAnimal( this->getEatCountAnimal() + this->getEatenFoodAnimal() );
            this->setIsHungry(false);
            animalEaten->setIsAlive(false); //the eaten animal is dead now
            cout << "Bear ate." << endl;
            return 1;   //is full
        }
        else{   //the other animal is carnivore. I suspect fight

            if( this->getSizeAnimal() == 10 ){  //The  bear is adult

                this->setEatenFoodAnimal( this->getEatCountAnimal() + this->getEatenFoodAnimal() );
                this->setIsHungry(false);
                animalEaten->setIsAlive(false); //the eaten animal is dead now
                cout << "Bear ate." << endl;
                return 1;   //is full
            }
            else if( (this->getSizeAnimal() > animalEaten->getSizeAnimal()) || (this->getAttack() > animalEaten->getDefence()) ){

                this->setEatenFoodAnimal( this->getEatCountAnimal() + this->getEatenFoodAnimal() );
                this->setIsHungry(false);
                animalEaten->setIsAlive(false); //the eaten animal is dead now
                cout << "Bear ate." << endl;
                return 1;   //is full
           }
        }
    }

    return 0;
}
