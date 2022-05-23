#include <iostream>
#include <vector>

int main()
{
    std::vector<int> array { 0, 1, 2 };
    array.resize(5); // set size to 5

    std::cout << "The length is: " << array.size() << std::endl;

    for (int element: array)
        std::cout << element << ' ';

    return 0;
}

