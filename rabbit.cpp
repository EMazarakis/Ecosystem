#include "rabbit.h"

#define RABBIT_SIZE 1
#define RABBIT_SPEED 2
#define RABBIT_NEEDED_FOOD 2    //per day

#define ADULT_RABBIT_SIZE 2
#define ADULT_RABBIT_SPEED 6
#define ADULT_RABBIT_NEEDED_FOOD 4    //per day

#define RABBIT_CAN_CLIMB  false
#define RABBIT_EAT_COUNT 1

Rabbit::Rabbit() : Herbivores(RABBIT_SIZE, RABBIT_SPEED, RABBIT_NEEDED_FOOD, RABBIT_CAN_CLIMB, RABBIT_EAT_COUNT, 'R')
{
//HACK:You can pass the arguments through the setters methods
}


int Rabbit::Eat(Animals *animalEaten, Plants *plantEaten){

    char plantToken = plantEaten->getToken();

    if( plantToken == 'G' ){    //Grass: Seedeles

        setEatenFoodAnimal( getEatenFoodAnimal() + getEatCountAnimal() );

        //UNDONE: Check if needeFood is complete

        plantEaten->loseLife( getEatCountAnimal() );
        cout << "Rabbit ate." << endl;
        return 1;
    }
    else if( plantToken == 'O' || plantToken == 'M' ){  //Oak & Maple: Seeded

        //absVALUE = | sizeAnimal - sizePlant | = 0
        if(  abs( getSizeAnimal() - plantEaten->getSize() ) == 0 ){    //sizePlant  = sizeAnimal

            setEatenFoodAnimal( getEatenFoodAnimal() + getEatCountAnimal());

            //UNDONE: Check if needeFood is complete

            if( plantEaten->getSeeds() > 0 ){   //There are some seeds

                plantEaten->setSeeds( plantEaten->getSeeds() - getEatCountAnimal() );
            }
            else{

                plantEaten->setFoliage( plantEaten->getFoliage() - getEatCountAnimal() );
                plantEaten->loseLife( getEatCountAnimal() );
            }

            cout << "Rabbit ate." << endl;
            return 1;
        }
    }
    return 0;
}
