#include "deer.h"
#include <stdlib.h> //abs

#define DEER_SIZE 2
#define DEER_SPEED 4
#define DEER_NEEDED_FOOD 4    //per day

#define ADULT_DEER_SIZE 5
#define ADULT_DEER_SPEED 8
#define ADULT_DEER_NEEDED_FOOD 8    //per day

#define DEER_CAN_CLIMB  false
#define DEER_EAT_COUNT 2

Deer::Deer() : Herbivores(DEER_SIZE, DEER_SPEED, DEER_NEEDED_FOOD, DEER_CAN_CLIMB, DEER_EAT_COUNT, 'D')
{
//HACK:You can pass the arguments through the setters methods
}


int Deer::Eat(Animals *animalEaten, Plants *plantEaten){

    char plantToken = plantEaten->getToken();

    if( plantToken == 'G' ){    //Grass: Seedeles

        setEatenFoodAnimal( getEatenFoodAnimal() + getEatCountAnimal() );

        //UNDONE: Check if needeFood is complete

        plantEaten->loseLife( getEatCountAnimal() );
        cout << "Deer ate." << endl;
        return 1;
    }
    else if( plantToken == 'O' || plantToken == 'M' ){  //Oak & Maple: Seeded

        //absVALUE = | sizeAnimal - sizePlant | <= 4
        if(  abs( getSizeAnimal() - plantEaten->getSize() )  <= 4 ){    //sizePlant  = sizeAnimal + 4

            setEatenFoodAnimal( getEatenFoodAnimal() + getEatCountAnimal());

            //UNDONE: Check if needeFood is complete

            if( plantEaten->getSeeds() > 0 ){   //There are some seeds

                plantEaten->setSeeds( plantEaten->getSeeds() - getEatCountAnimal() );
            }
            else{

                plantEaten->setFoliage( plantEaten->getFoliage() - getEatCountAnimal() );
                plantEaten->loseLife( getEatCountAnimal() );
            }

            cout << "Deer ate." << endl;
            return 1;
        }
    }
    return 0;
}
