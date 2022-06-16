//
// Created by Thomas Holtkamp on 6/1/2022.
//

#ifndef WEEK3BJ_BLACKJACK_H
#define WEEK3BJ_BLACKJACK_H


#include <vector>
#include "Card/Card.h"

using namespace std;

class Blackjack {
    vector<Card> cardDeck;
    vector<Card> playerCards;
    vector<Card> dealerCards;

    int randomNumber();

public:
    Blackjack();

    ~Blackjack(){
        cardDeck.~vector();
        playerCards.~vector();
        dealerCards.~vector();
    }

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

    void playerHit();

    void dealerHit();

    bool playerHits();
    bool dealerShouldHit();

    void playerTurn();
    void dealerTurn();

    void printPlayerCards();
    void printDealerCards();

    int countPlayerCardValue();

    int countDealerCardValue();

    int countCardsInHand(vector<Card>& cardHand);

    void swapCard(vector<Card>& deck, Card& card1, Card& card2);

    void shuffleDeck(vector<Card>& deck, int times);

    void printDeck(const vector<Card>& deck);

    void printCard(const Card& card);
};


#endif //WEEK3BJ_BLACKJACK_H
