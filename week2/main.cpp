#include <iostream>

using namespace std;

void printArray(int* values, int values_count);

int main() {
    int values[100] = { 0, 1, 2, 3, 4, 7, 8, 9, 10, 11 };
    int values_count = 10;

    int* ptr_1 = &values[3];
    int* ptr_2 = &values[5];
    printArray(values, values_count);
    *ptr_1 = 12;
    *ptr_2 = 15;
    printArray(values, values_count);

    return 0;
}

void printArray(int* values, int values_count)
{
    // loop over values_count and print values[currentIndex]
    int currentIndex = 0;
    while (currentIndex < values_count) {
        cout << values[currentIndex] << endl;

        currentIndex++;
    }
}
