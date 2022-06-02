//
// Created by Thomas Holtkamp on 6/1/2022.
//

#include <iostream>
#include <algorithm>
#include <time.h>
#include <random>

#include "Blackjack.h"

using namespace std;

Blackjack::Blackjack() {
    this->cardDeck = generateDeck();
    shuffleDeck(this->cardDeck, this->cardDeck.size()*10);
}

vector<Card> Blackjack::generateDeck() {
    auto deck = vector<Card>();

    for (auto i = 0; i < 4; i++) {
        for (auto j = 0; j < 13; j++) {
            deck.emplace_back(i, j);
        }
    }

    return deck;
}

void Blackjack::swapCard(vector<Card> &deck, Card &card1, Card &card2) {
    auto card1Index = find(deck.begin(), deck.end(), card1) - deck.begin();
    auto card2Index = find(deck.begin(), deck.end(), card2) - deck.begin();

    deck[card1Index] = card2;
    deck[card2Index] = card1;
}

void Blackjack::shuffleDeck(vector<Card> &deck, int times) {
    for (auto i = 0; i < times; i++) {
        auto card1 = deck[randomNumber() % deck.size()];
        auto card2 = deck[randomNumber() % deck.size()];
        swapCard(deck, card1, card2);
    }
}

void Blackjack::printDeck(const vector<Card> &deck) {
    for (auto& card : deck) {
        printCard(card);
    }
}

void Blackjack::printCard(const Card &card) {
    string cardRank;
    string cardSuit;

    switch (card.getRank()) {
        case cardRank::ACE:     cardRank = "A";     break;
        case cardRank::TWO:     cardRank = "2";     break;
        case cardRank::THREE:   cardRank = "3";     break;
        case cardRank::FOUR:    cardRank = "4";     break;
        case cardRank::FIVE:    cardRank = "5";     break;
        case cardRank::SIX:     cardRank = "6";     break;
        case cardRank::SEVEN:   cardRank = "7";     break;
        case cardRank::EIGHT:   cardRank = "8";     break;
        case cardRank::NINE:    cardRank = "9";     break;
        case cardRank::TEN:     cardRank = "10";    break;
        case cardRank::JACK:    cardRank = "J";     break;
        case cardRank::QUEEN:   cardRank = "Q";     break;
        case cardRank::KING:    cardRank = "K";     break;
    }

    switch (card.getSuit()) {
        case cardSuit::CLUBS:       cardSuit =  "C";    break;
        case cardSuit::DIAMONDS:    cardSuit =  "D";    break;
        case cardSuit::HEARTS:      cardSuit =  "H";    break;
        case cardSuit::SPADES:      cardSuit =  "S";    break;
    }

    cout << "Card: " << cardRank << cardSuit << endl;
}

void Blackjack::playerHit() {
    this->playerCards.emplace_back(this->cardDeck[0]);
    this->cardDeck.erase(this->cardDeck.begin());
}

void Blackjack::dealerHit() {
    this->dealerCards.emplace_back(this->cardDeck[0]);
    this->cardDeck.erase(this->cardDeck.begin());
}

void Blackjack::playerTurn() {
    while (playerHits()) {
        // player gets another card
        this->playerHit();

        // player has busted
        if (this->countPlayerCardValue() > 21) {
            std::cout << "Player busted!" << std::endl;
            return;
        }
    }
}

bool Blackjack::playerHits() {
    std::string input;
    while (input != "h" && input != "s") {
        this->printPlayerCards();
        this->printDealerCards();

        std::cout << "Hit or stand? h or s" << std::endl;
        std::cin >> input;
    }

    if (input == "h") {
        return true;
    }

    return false;
}

bool Blackjack::dealerShouldHit() {
    if (this->countDealerCardValue() < 17) {
        return true;
    }

    return false;
}

void Blackjack::dealerTurn() {
    while (this->dealerShouldHit()) {
        // dealer gets another card
        this->dealerHit();

        // dealer has busted
        if (this->countDealerCardValue() > 21) {
            std::cout << "Dealer busted!" << std::endl;
            return;
        }
    }
}

int Blackjack::countPlayerCardValue() {
    return countCardsInHand(this->playerCards);
}

int Blackjack::countDealerCardValue() {
    return countCardsInHand(this->dealerCards);
}

int Blackjack::countCardsInHand(vector<Card>& cardHand) {
    int sum = 0;
    for (auto& dealerCard : cardHand) {
        sum += dealerCard.getValue();
    }

    // if contains ace, check if it can be 1 or 11
    if (sum > 21 && !cardHand.empty()) {
        for (auto& dealerCard : cardHand) {
            if (dealerCard.getRank() == cardRank::ACE) {
                sum -= 10;
                break;
            }
        }
    }

    return sum;
}

int Blackjack::randomNumber() {
    mt19937 mersenne(random_device{}());
    uniform_int_distribution<int> distribution(0, 100);
    return distribution(mersenne);
}

void Blackjack::printPlayerCards() {
    std::cout << "Player: " << this->countPlayerCardValue();
    for (Card playerCard : this->getPlayerCards()) {
        std::cout << " " << playerCard.getValue();
    }
    std::cout << std::endl;
}

void Blackjack::printDealerCards() {
    std::cout << "Dealer: " << this->countDealerCardValue();
    for (Card dealerCard : this->getDealerCards()) {
        std::cout << " " << dealerCard.getValue();
    }
    std::cout << std::endl;
}