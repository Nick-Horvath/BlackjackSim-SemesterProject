#include "card.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

card * deal(card * deck)
{
    int dealing = rand() % 52;

    return &(deck[dealing]);
}
