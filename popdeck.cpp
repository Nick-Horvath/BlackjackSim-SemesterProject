#include "card.h"

void popdeck(card* deck)
{
    for (int i = 0; i < 13; i++)
    {
        deck[i].value = i+1;
        deck[i].suit = "Spades";
    }
    for (int i = 0; i < 13; i++)
    {
        deck[i+13].value = i+1;
        deck[i+13].suit = "Clubs";
    }
    for (int i = 0; i < 13; i++)
    {
        deck[i+26].value = i+1;
        deck[i+26].suit = "Hearts";
    }
    for (int i = 0; i < 13; i++)
    {
        deck[i+39].value = i+1;
        deck[i+39].suit = "Diamonds";
    }
}

