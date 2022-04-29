#include <random>
#include <ctime>
#include <iostream>
#include "io.h"

using namespace std;

int randomNumber();
bool endGame();
void startGame();

int main() {
    bool shouldStop = false;

    while (!shouldStop) {
        startGame();
        shouldStop = endGame();
    }

    return 0;
}

int randomNumber()
{
    // Initialize our mersenne twister with a random seed based on the clock
    mt19937 mersenne(static_cast<unsigned int>(time(nullptr)));

    // Create a reusable random number generator
    uniform_int_distribution<> generator(1, 100);
    return generator(mersenne);
}

void startGame() {
    int currentGuessCount{1};
    const int numberToGuess = randomNumber();

    cout << "Let's play a game. I'm thinking of a number.\n";
    cout << "You have 7 tries to guess what it is.\n";

    // start game
    while (currentGuessCount <= 7) {
        cout << "Guess #" << currentGuessCount << ": ";

        bool isCorrectResponse = writeResponse(numberToGuess, readNumber());
        if (isCorrectResponse)
            return;

        currentGuessCount++;
    }

    cout << "Sorry, you lose. The correct number was " << numberToGuess << ".\n";
}

bool endGame() {
    // ask for replay
    string input;
    while (input != "y" || input != "n") {
        cout << "Would you like to play again (y/n)? ";
        cin >> input;

        if (input == "y") {
            startGame();
        } else if (input == "n") {
            cout << "Thank you for playing.\n";
            return true;
        }
    }

    return false;
}