#include <random>
#include <ctime>
#include <iostream>

using namespace std;

int randomNumber();
int readNumber();
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

int readNumber() {
    string guessInput;
    int inputInt;

    try {
        cin >> guessInput;
        inputInt = stoi(guessInput);
        while (inputInt < 1 || inputInt > 100) {
            cout << "Input must be between 1 and 100" << endl;
            cin >> guessInput;
            inputInt = stoi(guessInput);
        }
    } catch (exception& msg) {
        return readNumber();
    }

    return inputInt;
}

void startGame() {
    int currentGuessCount{1};
    const int numberToGuess = randomNumber();

    cout << "Let's play a game. I'm thinking of a number." << endl;
    cout << "You have 7 tries to guess what it is." << endl;

    // start game
    while (currentGuessCount <= 7) {
        cout << "Guess #" << currentGuessCount << ": ";
        const int guessInput = readNumber();

        if (numberToGuess < guessInput) {
            cout << "Your guess is too high." << endl;
        } else if (numberToGuess > guessInput) {
            cout << "Your guess is too low." << endl;
        } else {
            cout << "Correct! You win!" << endl;
            return;
        }

        currentGuessCount++;
    }

    cout << "Sorry, you lose. The correct number was " << numberToGuess << "." << endl;
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
            cout << "Thank you for playing." << endl;
            return true;
        }
    }

    return false;
}