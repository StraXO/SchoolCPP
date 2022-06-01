#include <iostream>

#include "classes/Blackjack.h"

void startGame();
bool askRestart();
bool playerHits(Blackjack& game);
bool dealerShouldHit(Blackjack& game);

void playerHit(Blackjack& game);
void dealerHit(Blackjack& game);

void printPlayerCards(Blackjack& game);
void printDealerCards(Blackjack& game);

int main() {
    startGame();

    while (askRestart()) {
        startGame();
    }

    return 0;
}

void startGame() {
    std::cout << "Time for some Blackjack!" << std::endl;

    Blackjack game; // create a new game

    // dealer gets one card
    game.dealer_hit();
    // player gets two cards
    game.player_hit();
    game.player_hit();

    // player start with a blackjack and wins!
    if (game.countPlayerCardValue() == 21) {
        std::cout << "Player wins with a blackjack!" << std::endl;
        return;
    }

    // player goes first
    playerHit(game);

    // then dealer goes
    dealerHit(game);

    printPlayerCards(game);
    printDealerCards(game);

    if (game.countPlayerCardValue() > game.countDealerCardValue()) {
        std::cout << "Player wins!" << std::endl;
    } else if (game.countPlayerCardValue() < game.countDealerCardValue()) {
        std::cout << "Dealer wins!" << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }
}

bool playerHits(Blackjack& game) {
    std::string input;
    while (input != "h" && input != "s") {
        printPlayerCards(game);
        printDealerCards(game);

        std::cout << "Hit or stand? h or s" << std::endl;
        std::cin >> input;
    }

    if (input == "h") {
        return true;
    }

    return false;
}

bool dealerShouldHit(Blackjack& game) {
    if (game.countDealerCardValue() < 17) {
        return true;
    }

    return false;
}

void printPlayerCards(Blackjack& game) {
    std::cout << "Player: " << game.countPlayerCardValue();
    for (Card playerCard : game.getPlayerCards()) {
        std::cout << " " << playerCard.getValue();
    }
    std::cout << std::endl;
}

void printDealerCards(Blackjack& game) {
    std::cout << "Dealer: " << game.countDealerCardValue();
    for (Card dealerCard : game.getDealerCards()) {
        std::cout << " " << dealerCard.getValue();
    }
    std::cout << std::endl;
}

void playerHit(Blackjack& game) {
    while (playerHits(game)) {
        // player gets another card
        game.player_hit();

        // player has busted
        if (game.countPlayerCardValue() > 21) {
            std::cout << "Player busted!" << std::endl;
            return;
        }
    }
}

void dealerHit(Blackjack& game) {
    while (dealerShouldHit(game)) {
        // dealer gets another card
        game.dealer_hit();

        // dealer has busted
        if (game.countDealerCardValue() > 21) {
            std::cout << "Dealer busted!" << std::endl;
            return;
        }
    }
}

bool askRestart() {
    // ask player to restart
    std::cout << "Play again? (y/n)" << std::endl;
    char answer;
    std::cin >> answer;
    if (answer == 'y') {
        return true;
    }

    return false;
}