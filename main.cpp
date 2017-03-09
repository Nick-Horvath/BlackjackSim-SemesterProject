#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include "card.h"
#include "popdeck.h"
#include "deal.h"

using namespace std;

int main()
{
    char rulescall;
    card * deck = new card[54];
    card * dealt;

    cout << "Welcome to my Blackjack simulator and metrics tracker. This program aims to allow " << endl;
    cout << "users to practice hands of blackjack as well as keep track of their win-loss ratio for " << endl;
    cout << "various dealer-player hand combinations. Would you like to see the rules?" << endl;
    cout << "y/n:";
    cin >> rulescall;

    if(rulescall == 'y')
    {
        cout << "Before dealing beings, players may bet any amount within an accepted range." << endl;
        cout << "Dealing begins with the dealer dealing one card face up to each player, including themselves. " << endl;
        cout << "Next, they deal a second card face up to each player, and one card face down to themselves, " << endl;
        cout << "currently known to no one. " << endl << endl;

        cout << "After the deal, play begins. The player to the left decides whether to hit or stand, " << endl;
        cout << "based on the cards they have. Once all players have taken their turn, the dealer takes his turn, " << endl;
        cout << "which is based entirely on the cards they were dealt. They have no choice to hit or stay." << endl;
        cout << "The object of the game is to use the cards you are dealt to make a total of 21, or a blackjack. " << endl;
        cout << "Note: all number cards have pip value, face cards are 10, and aces are 1 or 11, determined by the " << endl;
        cout << "player. " << endl;
        cout << "A player may 'Hit', or request another card from the dealer in order to get closer to 21. They " << endl;
        cout << "may 'Stay', or decline another card, if they are satisfied with their total. They may take as " << endl;
        cout << "many cards as they want, but as soon as the cards in their hand total greater than 21, they 'Bust', " << endl;
        cout << "or lose immediately. Their turn ends and their bet is collected by the house. " << endl;
        cout << "Winning and losing are determined by the following." << endl << endl;

        cout << "Any player whose cards total up to higher than the dealers' cards gets paid out by the house. " << endl;
        cout << "In the event of a tie, no one wins and chips are returned. There are a few special cases to " << endl;
        cout << "consider before the game begins." << endl << endl;

        cout << "Naturals: If a player has an ace and a 10-card, they have a natural. These pay back at an increased rate, "<< endl;
        cout << "and end that players turn. If the dealer has a natural, all player who do not lose, and those who do " << endl;
        cout << "get their chips back." << endl << endl;

        cout << "Doubling Down: If a players first two cards total 9, 10, or 11, they have the option to double down. " << endl;
        cout << "In this case, they get one extra card. With this new hand of 3, the game resumes normally." << endl << endl;

        cout << "Splitting pairs: If a player is dealt two of the same cards, they can choose to play both as seperate hands. " << endl;
        cout << "They match their original bet for the second hand, and play continues." << endl << endl;

        cout << "With the basic rules and special cases complete, lets play!" << endl << endl;

        cout << "Press and alphanumeric key and enter to continue.";
        char cont;
        cin >> cont;
    }
    else
    {
        cout << "Lets play!" << endl << endl;
    }

    cout << "This program uses a six-deck shoe.";

    popdeck(deck);

    cout << "Deck:" << endl;
    for (int i = 0; i < 52; i++)
    {
        cout << deck[i].value << " of " << deck[i].suit << endl;
    }

    cout << endl;

    cout << "Dealing" << endl << endl;

    dealt = deal(deck);

    return 0;
}
