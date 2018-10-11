#include "seedless.h"

Seedless::Seedless(){}

Seedless::Seedless(int TOKEN, int BREED, int ILL, int LIFE, int L_FACT) : Plants(TOKEN,BREED,ILL,LIFE,L_FACT){}


void Seedless::loseLife(int eatenLife){ setLife( getLife() - eatenLife ); }

void Seedless::growthPlant(int flag){

    if ( flag ){    //1: means growth
        setLife( getLife() + getLifeFactor() );
        return ;
    }

    //0: means no growth
    setLife( getLife() - getLifeFactor() );
}


void Seedless::breedPlant(void){
    //TODO
}
