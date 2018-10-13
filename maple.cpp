#include "maple.h"

//Initial Values of Maple
#define TOKEN    'M'
#define SIZE     2
#define SEEDS    10
#define FOLIAGE  20
#define ILL      5
#define BREED    5
#define L_FACTOR 10
#define LIFE     -1

Maple::Maple() : Seeded(FOLIAGE,SEEDS,SIZE,TOKEN,BREED,ILL,LIFE,L_FACTOR)
{
//HACK:You can pass the arguments through the setters
}
