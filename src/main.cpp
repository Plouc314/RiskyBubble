# include <iostream>
# include <vector>
# include <array>
# include <stdlib.h>
# include <time.h>
# include "algorithm.h"
# include "stats.h"

template<int size>
void print_array(std::array<int, size> array)
{
    for (int i=0; i<array.size(); i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main(){

    srand(time(NULL));

    const int size = 100000;

    std::array<int, size> array;

    fillRandom<size>(array, 0, size);

    float t = getBuiltInDuration<size>(array);

    float acc = getAccuracy<size>(array);

    std::cout << acc << ' ' << t << std::endl;
}