#include <iostream>

int main()
{
    // We want to find the mode (most common value) of this array
    const int ARRAY_SIZE = 12;
    int surveyData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};

    // We could sort it and then device a counting strategy to count
    // how often the value doesn't change  when going through the array
    // again in a top-of-the-hill fashion. This is double pass and the
    // better strategy, I remember because I read the same chapter a
    // month ago, is to create an array with ten positions initialised
    // to zero. We loop over the original array and take the values
    // as index to the second array adding one each time. Then we find
    // the maximum to this array.

    const int COUNT_ARRAY_SIZE = 10;
    int countArray[COUNT_ARRAY_SIZE];
    int max = 0;
    int max_index = 0;

    for (int i = 0; i < COUNT_ARRAY_SIZE; i++)
        countArray[i] = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
        countArray[surveyData[i] - 1]++;

    max = countArray[0];
    for (int i = 1; i < COUNT_ARRAY_SIZE; i++)
    {
        if (countArray[i] > max)
        {
            max = countArray[i];
            // Add one because real languages start arrays at zero ;)
            max_index = i + 1;
        }
    }
    std::cout << "Max values is " << max_index;
}