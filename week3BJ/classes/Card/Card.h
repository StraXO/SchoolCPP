//
// Created by Thomas Holtkamp on 6/1/2022.
//

#ifndef WEEK3BJ_CARD_H
#define WEEK3BJ_CARD_H

#include "cardSuit.h"
#include "cardRank.h"

class Card {
    cardSuit suit{};
    cardRank rank{};

public:
    Card(int suit, int rank) {
        this->suit = static_cast<cardSuit>(suit);
        this->rank = static_cast<cardRank>(rank);
    }

    [[nodiscard]] cardSuit getSuit() const {
        return suit;
    }

    [[nodiscard]] cardRank getRank() const {
        return rank;
    }

    [[nodiscard]] int getValue() const {
        switch (this->rank) {
            case cardRank::ACE:
                return 11;
            case cardRank::TWO:
                return 2;
            case cardRank::THREE:
                return 3;
            case cardRank::FOUR:
                return 4;
            case cardRank::FIVE:
                return 5;
            case cardRank::SIX:
                return 6;
            case cardRank::SEVEN:
                return 7;
            case cardRank::EIGHT:
                return 8;
            case cardRank::NINE:
                return 9;
            case cardRank::TEN:
            case cardRank::JACK:
            case cardRank::QUEEN:
            case cardRank::KING:
                return 10;
            default:
                return 0;
        }
    }

    bool operator==(const Card& other) {
        return this->suit == other.suit && this->rank == other.rank;
    }
};


#endif //WEEK3BJ_CARD_H
