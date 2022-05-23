#include <iostream>

using namespace std;

int searchArray(const int* values, int values_count, int value);
int insertArray(int* values, int values_count, int value);
int* insertArray(int* values, int* values_count, int value);
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

    int *values = new int[100];
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

    delete[] values;

    int* values_2 = nullptr;
    int values_count_2 = 0;

    values_2 = insertArray(values_2, &values_count_2, 10);
    values_2 = insertArray(values_2, &values_count_2, 1);
    values_2 = insertArray(values_2, &values_count_2, 8);
    values_2 = insertArray(values_2, &values_count_2, 3);
    values_2 = insertArray(values_2, &values_count_2, 6);
    values_2 = insertArray(values_2, &values_count_2, 5);
    values_2 = insertArray(values_2, &values_count_2, 4);
    values_2 = insertArray(values_2, &values_count_2, 7);
    values_2 = insertArray(values_2, &values_count_2, 2);
    printArray(values_2, values_count_2);

    delete values_2;

    return 0;
}

int searchArray(const int* values, int values_count, int value)
{
    for (int i = 0; i < values_count; ++i) {
        if (values[i] >= value)
            return i;
    }

    return values_count;
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

int* insertArray(int* values, int* values_count, int value)
{
    // allocate a new values array with size values_count + 1
    int* new_values = new int[*values_count + 1];

    // copy all existing values from to the new array
    int index = searchArray(values, *values_count, value);
    for(int i = *values_count+1; i >= 0; --i) {
        if (*values_count == 0 || i == index) {
            new_values[index] = value;
        } else if (i < index) {
            new_values[i] = values[i];
        } else {
            new_values[i] = values[i - 1];
        }
    }

    // update values_count
    *values_count += 1;

    // deallocate the old values array
    delete[] values;

    return new_values;// return a pointer to the new values array
}

void printArray(int* values, int values_count)
{
    cout << "(" << values_count << ") ";
    for (int i = 0; i < values_count; ++i) {
        cout << values[i] << " ";
    }
    std::cout << std::endl;
}
