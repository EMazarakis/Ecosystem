#include "fox.h"

#define FOX_SIZE 1
#define FOX_ATTACK 1
#define FOX_DEFENCE 1
#define FOX_SPEED 1
#define FOX_NEEDED_FOOD 2

#define ADULT_FOX_SIZE 4
#define ADULT_FOX_ATTACK 5
#define ADULT_FOX_DEFENCE 5
#define ADULT_FOX_SPEED 6
#define ADULT_FOX_NEEDED_FOOD 6

#define FOX_HIBERNATION false

Fox::Fox() : Carnivores(FOX_SIZE, FOX_ATTACK, FOX_DEFENCE, FOX_SPEED, FOX_NEEDED_FOOD, FOX_HIBERNATION, 'F')
{
//HACK:You can pass the arguments through the setters methods
}


int Fox::Eat(Animals *animalEaten, Plants *plantEaten){

    char animalToken = animalEaten->getAnimalToken();

    if( animalToken == this->getAnimalToken() ){    //Same kind of animals

        cout << "Same kind of animals. Cannibalism is forbidden." << endl;
        return 0;
    }
    else{

        if( animalToken == 'S' ){    //Fox did not eat Salmon

            cout << "Fox did not eat Salmon." << endl;
            return 0;
        }
        else if( animalToken == 'D' ||animalToken == 'R' || animalToken == 'G'){
            //Fox eats all the herbivores animals except Salmon

            if( (this->getSizeAnimal() >= animalEaten->getSizeAnimal()) && (this->getSpeedAnimal() > animalEaten->getSpeedAnimal()) ){

                this->setEatenFoodAnimal( this->getEatCountAnimal() + this->getEatenFoodAnimal() );
                this->setIsHungry(false);
                animalEaten->setIsAlive(false); //the eaten animal is dead now
                cout << "Fox ate." << endl;
                return 1;   //is full
            }
            //return 0;
        }
        else{   //the other animal is carnivore. I suspect fight

            if( (this->getSizeAnimal() > animalEaten->getSizeAnimal()) || ( this->getSizeAnimal() == animalEaten->getSizeAnimal()  &&  this->getAttack() > animalEaten->getDefence() ) ){

                this->setEatenFoodAnimal( this->getEatCountAnimal() + this->getEatenFoodAnimal() );
                this->setIsHungry(false);
                animalEaten->setIsAlive(false);     //the eaten animal is dead now
                cout << "Fox ate." << endl;
                return 1;   //is full
           }
        }
    }

    return 0;
}
