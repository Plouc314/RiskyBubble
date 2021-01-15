# pragma once
# include "algorithm.cpp"

template<int size>
void bubble(std::array<int, size> & array, int depth);

template<int size>
void insertionSort(std::array<int, size> & array);

template<int size>
void approx(std::array<int, size> & array);

template<int size>
void riskyBubble(std::array<int, size> & array);

template<int size>
void quickInsert(std::array<int, size> & array);