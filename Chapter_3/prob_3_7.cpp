#include <iostream>
#include <time.h>

int max_index(int *data, const int SIZE)
{
    int max = data[0];
    int imax = 0;
    for (int i = 1; i < SIZE; i++)
    {
        if (data[i] > max)
        {
            imax = i;
            max = data[i];
        }
    }
    return imax;
}

int mode(int *data, const int SIZE, const int NR_RANGE)
{
    int min = 0;
    int max = NR_RANGE - 1;
    // More flexible if min, max are not given wrt NR_RANGE
    int indexes[(max - min) + 1];
    for (int i = 0; i < (max - min) + 1; i++)
    {
        indexes[i] = 0;
    }
    for (int i = 0; i < SIZE; i++)
    {
        indexes[data[i]]++;
    }

    int this_mode = max_index(indexes, (max - min) + 1);
    return this_mode;
}

int main()
{
    srand((unsigned)time(NULL));
    const int SIZE = 200;
    const int NR_RANGE = 10;
    int data[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        data[i] = rand() % NR_RANGE;
    }

    int this_mode = mode(data, SIZE, NR_RANGE);
    std::cout << "MODE IS: " << this_mode << std::endl;
}