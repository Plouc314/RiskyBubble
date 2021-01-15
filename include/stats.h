# pragma once
# include "stats.cpp"

template<int size>
void fillRandom(std::array<int, size> & array, int min, int max);

template<int size>
float getAccuracy(std::array<int, size> & array);

template<int size>
float getBubbleDuration(std::array<int, size> & array);

template<int size>
float getRiskyBubbleDuration(std::array<int, size> & array);

template<int size>
float getQuickInsertDuration(std::array<int, size> & array);

template<int size>
float getBuiltInDuration(std::array<int, size> & array);