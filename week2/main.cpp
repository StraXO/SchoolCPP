#include <iostream>

using namespace std;

int searchArray(const int* values, int values_count, int value);
int insertArray(int* values, int values_count, int value);
int *insertArray(int *values, int *values_count, int value);
void printArray(int* values, int values_count);

int main() {
    int search_values[] = { 1, 2, 3, 4, 5 };
    if(searchArray(search_values, sizeof(search_values) / sizeof(int), 3) != 2) {
        std::cout << "searchArray returned an incorrect value!!";
        return 0;
    }

    if(searchArray(search_values, sizeof(search_values) / sizeof(int), 4) != 3) {
        std::cout << "searchArray returned an incorrect value!!";
        return 0;
    }

    std::cout << "searchArray OK!!" << std::endl;

    int values[100];
    int values_count = 0;

    values_count = insertArray(values, values_count, 10);
    values_count = insertArray(values, values_count, 1);
    values_count = insertArray(values, values_count, 8);
    values_count = insertArray(values, values_count, 3);
    values_count = insertArray(values, values_count, 6);
    values_count = insertArray(values, values_count, 5);
    values_count = insertArray(values, values_count, 4);
    values_count = insertArray(values, values_count, 7);
    values_count = insertArray(values, values_count, 2);
    printArray(values, values_count);

    return 0;
}

int searchArray(const int* values, int values_count, int value)
{
    int position = values_count;

    while (position > 0) {
        if (values[position-1] < value)
            return position;

        position--;
    }

    return position;
}


int insertArray(int* values, int values_count, int value)
{
    // insert the specified value in the array
    int index = searchArray(values, values_count, value);

    // shift elements that are bigger to the right by 1
    int shiftIndex = values_count;
    while (shiftIndex > index) {
        values[shiftIndex] = values[shiftIndex-1];
        shiftIndex--;
    }

    // insert the value on correct index
    values[index] = value;

    return values_count + 1;// return the new number of elements
}

int *insertArray(int *values, int *values_count, int value)
{
    // TODO: allocate a new values array with size values_count + 1

    // TODO: copy all existing values from to the new array

    // TODO: copy the new value into the array, sorted ofcourse!

    // TODO: update values_count

    // TODO: deallocate the old values array

    return // TODO: return a pointer to the new values array
}

void printArray(int* values, int values_count)
{
    // loop over values_count and print values[currentIndex]
    int currentIndex = 0;

    cout << "printArray: ";
    while (currentIndex < values_count) {
        cout << values[currentIndex];

        if (currentIndex < values_count-1)
            cout << ", ";

        currentIndex++;
    }
}
