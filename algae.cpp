#include "algae.h"


//Initial Values of Algae
#define TOKEN    'A'
#define BREED    25
#define ILL      25
#define LIFE     5
#define L_FACTOR 2

Algae::Algae() : Seedless(TOKEN,BREED,ILL,LIFE,L_FACTOR)
{
//HACK:You can pass the arguments through the setters methods
}
