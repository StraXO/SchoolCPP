//
// Created by Thomas Holtkamp on 6/1/2022.
//

#ifndef WEEK3BJ_BLACKJACK_H
#define WEEK3BJ_BLACKJACK_H


#include <vector>
#include "Card/Card.h"

using namespace std;

class Blackjack {
private:
    vector<Card> cardDeck;
    vector<Card> playerCards;
    vector<Card> dealerCards;

public:
    Blackjack();

    vector<Card> getDeck(){
        return cardDeck;
    }

    vector<Card> getPlayerCards(){
        return playerCards;
    }

    vector<Card> getDealerCards(){
        return dealerCards;
    }

    vector<Card> generateDeck();

    void player_hit();

    void dealer_hit();

    int countPlayerCardValue();

    int countDealerCardValue();

    int countCardsInHand(vector<Card>& cardHand);

    void swapCard(vector<Card>& deck, Card& card1, Card& card2);

    void shuffleDeck(vector<Card>& deck, int times);

    void printDeck(const vector<Card>& deck);

    void printCard(const Card& card);
};


#endif //WEEK3BJ_BLACKJACK_H
