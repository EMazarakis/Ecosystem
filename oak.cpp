#include "oak.h"

//Initial Values of Oak
#define TOKEN    'O'
#define SIZE     5
#define SEEDS    15
#define FOLIAGE  30
#define ILL      20
#define BREED    20
#define L_FACTOR 15
#define LIFE     -1

Oak::Oak() : Seeded(FOLIAGE,SEEDS,SIZE,TOKEN,BREED,ILL,LIFE,L_FACTOR)
{
//HACK:You can pass the arguments through the setters
}

