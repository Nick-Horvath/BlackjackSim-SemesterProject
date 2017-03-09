#include "card.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

card * deal(card* deck)
{
     card * dealt = new card[4];

     for(int i = 0; i > 4; i++)
     {
         dealt[i] = deck[rand() % 52];
     }

     cout << "Your card is " << dealt[0].value << " of " << dealt[0].suit << endl;
     cout << "The dealer deals himself a card face down." << endl;
     cout << "Your next card is " << dealt[2].value << " of " << dealt[2].suit << endl;
     cout << "The dealers up-card is " << dealt[3].value << " of " << dealt[3].suit << endl;

     return dealt;
}
