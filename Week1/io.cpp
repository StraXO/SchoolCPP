//
// Created by Thomas Holtkamp on 4/29/2022.
//
#include <random>
#include <iostream>

using namespace std;

int readNumber() {
    string guessInput;
    int inputInt;

    try {
        cin >> guessInput;
        inputInt = stoi(guessInput);
        while (inputInt < 1 || inputInt > 100) {
            cout << "Input must be between 1 and 100\n";
            cin >> guessInput;
            inputInt = stoi(guessInput);
        }
    } catch (exception& msg) {
        return readNumber();
    }

    return inputInt;

}

bool writeResponse(int answer, int guessNumber) {
    if (answer < guessNumber) {
        cout << "Your guess is too high.\n";
    } else if (answer > guessNumber) {
        cout << "Your guess is too low.\n";
    } else {
        cout << "Correct! You win!\n";
        return true;
    }

    return false;
}