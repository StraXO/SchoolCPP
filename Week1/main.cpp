#include <random>
#include <ctime>
#include <iostream>

using namespace std;

int randomNumber();
int readNumber();

int main() {
    int guessCount{1};
    std::cout << "Let's play a game. I'm thinking of a number." << std::endl;
    std::cout << "You have 7 tries to guess what it is." << std::endl;

    int numberToGuess = randomNumber();

    while (guessCount <= 7) {
        int guessInput = readNumber();
        cout << "Guess #" << guessCount << ": " << guessInput << endl;

        if (numberToGuess < guessInput) {
            cout << "Your guess is too high." << endl;
        } else if (numberToGuess > guessInput) {
            cout << "Your guess is too low." << endl;
        } else if (numberToGuess == guessInput) {
            cout << "Correct! You win!" << endl;
        } else {
            cout << "Sorry, you lose. The correct number was " << numberToGuess << "." << endl;
        }

        guessCount++;
    }

    return 0;
}

int randomNumber()
{
    // Initialize our mersenne twister with a random seed based on the clock
    std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
    // Create a reusable random number generator
    std::uniform_int_distribution<> generator(1, 100);

    return generator(mersenne);
}

int readNumber() {
    string guessInput;
    try {
        cin >> guessInput;
        return stoi(guessInput);
    } catch (std::exception& msg) {
    }

    return readNumber();
}