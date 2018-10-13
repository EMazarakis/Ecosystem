#include "pine.h"

//Initial Values of Pine
#define TOKEN    'P'
#define SIZE     5
#define SEEDS    20
#define FOLIAGE  40
#define ILL      15
#define BREED    15
#define L_FACTOR 20
#define LIFE     -1

Pine::Pine() : Seeded(FOLIAGE,SEEDS,SIZE,TOKEN,BREED,ILL,LIFE,L_FACTOR)
{
//HACK:You can pass the arguments through the setters
}

