#include <iostream>

#include "classes/Blackjack.h"

void startGame();
bool askRestart();

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
    game.dealerHit();
    // player gets two cards
    game.playerHit();
    game.playerHit();

    // player start with a blackjack and wins!
    if (game.countPlayerCardValue() == 21) {
        std::cout << "Player wins with a blackjack!" << std::endl;
        return;
    }

    // player goes first
    game.playerTurn();

    if (game.countPlayerCardValue() > 21) {
        std::cout << "Bust, you lose!" << std::endl;
        return;
    }

    // then dealer goes
    game.dealerTurn();

    game.printPlayerCards();
    game.printDealerCards();

    if (game.countDealerCardValue() > 21) {
        std::cout << "Dealer busts, You win!" << std::endl;
        return;
    }

    if (game.countPlayerCardValue() > game.countDealerCardValue()) {
        std::cout << "Player wins!" << std::endl;
    } else if (game.countPlayerCardValue() < game.countDealerCardValue()) {
        std::cout << "Dealer wins!" << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
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