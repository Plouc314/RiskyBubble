# include <iostream>
# include <algorithm>
# include <vector>
# include <array>
# include <math.h>

void print_vec(std::vector<int> vec)
{
    for (int i=0; i<vec.size(); i++)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
}

template<int size>
void bubble(std::array<int, size> & array, int depth = -1)
{
    if (depth == -1) { depth = size; }
    int v;

    for (int i=0; i<depth-1; i++)
    {
    for (int j=0; j<size-i-1; j++)
    {
        if (array[j] > array[j+1])
        {
            v = array[j];
            array[j] = array[j+1];
            array[j+1] = v;
        }
    }
    }
}

template<int size>
void approx(std::array<int, size> & array)
{
    int min = *std::min_element(array.begin(), array.begin() + size);
    int max = min + 1;
    int idx;

    std::vector<int> array2;

    for (int i=0; i<size; i++)
    {

        idx = (int)(((float)(array[i] - min)) / (max - min) * i);

        if (idx > i) { idx = i; }

        if (array[i] > max)
        {
            max = array[i];
        }

        array2.insert(array2.begin() + idx, array[i]);
    }

    // swap vector and array
    for (int i=0; i<size; i++) { array[i] = array2[i]; }
}

template<int size>
void riskyBubble(std::array<int, size> & array)
{
    int depth = 2 * std::log10(size);

    for (int step=0; step<depth; step++)
    {
        approx<size>(array);
        bubble<size>(array, 2*depth);
    }

}