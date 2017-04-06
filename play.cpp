#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "popdeck.h"
#include "deal.h"
using namespace std;

void play(card* deck)
{
    srand(time(0));
    bool bust = false;
    char hit;
    card * playerOne;
    card * playerTwo;
    card * dealerUp;
    card * dealerDown;
    card * addCard;
    card * dealerAdd;
    int playerTotal, dealerTotal;

    cout << "dealing" << endl;

    playerOne = deal(deck);
    playerTwo = deal(deck);
    dealerUp = deal(deck);
    dealerDown = deal(deck);

    cout << "Your cards are:" << endl;
    cout << "The " << playerOne->value << " of " << playerOne->suit << " and the " << playerTwo->value << " of " << playerTwo->suit << endl;
    cout << "The dealers face up card is " << dealerUp->value <<  " of " << dealerUp->suit << endl;

    if((dealerUp->value == 10 && dealerDown->value == 1) || (dealerDown->value == 10 && dealerUp->value == 1))
    {
        if((playerOne->value == 10 && playerTwo->value == 1) || (playerTwo->value == 10 && playerOne->value == 1))
        {
            cout << "Both you and the dealer have a natural. This is a stand off. Bets are returned, and play continues."<< endl;
        }
        else
        {
            cout << "The dealer has a natural. Your bet is collected." << endl;
        }
    }
    else if((playerOne->value == 10 && playerTwo->value == 1) || (playerTwo->value == 10 && playerOne->value == 1))
    {
        cout << "You have a natural. You are payed out." << endl;
    }
    else
    {
        if(playerOne->value == 1)
        {
            cout << "You have an ace, this may count as either 11 or 1." << endl;
            cout << "If you choose to count it as a one, your total is " << (playerTwo->value)+1 << endl;
            cout << "and if you choose to count it as 11 it is " << (playerTwo->value+11) << endl <<endl;
        }
        else if(playerTwo->value == 1)
        {
            cout << "You have an ace, this may count as either 11 or 1." << endl;
            cout << "If you choose to count it as a one, your total is " << (playerOne->value)+1 << endl;
            cout << "and if you choose to count it as 11 it is " << (playerOne->value+11) << endl <<endl;
        }
        else
        {
            playerTotal = (playerOne->value)+(playerTwo->value);
            dealerTotal = (dealerDown->value)+(dealerUp->value);
            cout << "Your current total is " << playerTotal << endl;
            while(bust == false)
            {
                cout << "Would you like to hit? y/n: ";
                cin >> hit;
                if(hit == 'n' || hit == 'N')
                {
                    break;
                }
                else
                {
                    addCard = deal(deck);
                    cout << "You are dealt the " << addCard->value << " of " << addCard->suit << endl;
                    playerTotal = playerTotal + addCard->value;
                }

                cout << "Your total is now " << playerTotal << endl;

                if(playerTotal == 21)
                {
                    cout << "Blackjack!" << endl;
                    break;
                }
                else if(playerTotal > 21)
                {
                    cout << "Bust" << endl;
                    bust = true;
                }

            }

            if(bust == true)
            {
                cout << "Your total exceeded 21. Your bet is collected." << endl;
            }
            else if(playerTotal == 21)
            {
                cout << "You hit into a Blackjack! You are payed out." << endl;
            }
            else
            {
                cout << "The dealers hand is the " << dealerUp->value << " of " << dealerUp->suit << " and the " << dealerDown->value << " of " << dealerDown->suit << endl;
                while(dealerTotal < 17)
                {
                    dealerAdd = deal(deck);
                    cout << "The dealer is dealt the " << dealerAdd->value << " of " << dealerAdd->suit <<endl;
                    dealerTotal = dealerTotal + dealerAdd->value;
                    cout << "The dealers total is now " << dealerTotal << endl;
                }
                if(dealerTotal > 21)
                {
                    cout << "The dealer busted. You are payed out." << endl;
                }
                else if(playerTotal > dealerTotal)
                {
                    cout << "You beat the dealer. You are payed out." << endl;
                }
                else if(playerTotal == dealerTotal)
                {
                    cout << "There is a stand off. Your bet is returned." << endl;
                }
                else
                {
                    cout << "The dealer beat you. Your bet is collected." << endl;
                }
            }
        }
    }
}
