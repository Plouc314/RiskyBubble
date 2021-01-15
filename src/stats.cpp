# include <stdlib.h>
# include <algorithm>
# include <chrono>
# include "algorithm.h"

int randint(int min, int max)
{
    return rand() % (max - min) + min + 1;
}

template<int size>
void fillRandom(std::array<int, size> & array, int min, int max)
{
    for (int i=0; i<size; i++)
    {
        array[i] = randint(min, max);
    }
}

template<int size>
float getAccuracy(std::array<int, size> & array)
{
    float fails = 0;
    int last = array[0];

    for (int i=0; i<size; i++)
    {
        if (last > array[i]){
            fails++;
        }

        last = array[i];
    }

    return 1 - (fails / size);
}

template<int size>
float getBubbleDuration(std::array<int, size> & array)
{
    auto t1 = std::chrono::high_resolution_clock::now();
    bubble<size>(array);
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    return (float) duration;
}

template<int size>
float getRiskyBubbleDuration(std::array<int, size> & array)
{
    auto t1 = std::chrono::high_resolution_clock::now();
    riskyBubble<size>(array);
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    return (float) duration;
}

template<int size>
float getQuickInsertDuration(std::array<int, size> & array)
{
    auto t1 = std::chrono::high_resolution_clock::now();
    quickInsert<size>(array);
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    return (float) duration;
}

template<int size>
float getBuiltInDuration(std::array<int, size> & array)
{
    auto t1 = std::chrono::high_resolution_clock::now();
    std::sort(array.begin(), array.end());
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    return (float) duration;
}