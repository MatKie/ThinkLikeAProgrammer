#include <iostream>
int compare_int(const void *voidA, const void *voidB)
{
    int *intA = (int *)(voidA);
    int *intB = (int *)(voidB);
    return *intB - *intA;
}
double find_median(int salesArray[], const int SIZE)
{
    float halfIndex = 0.;
    int index1 = -1;
    int index2 = -1;

    qsort(salesArray, SIZE, sizeof(int), compare_int);
    if (SIZE % 2 != 0)
    {
        index1 = floor(SIZE / 2);
        return salesArray[index1];
    }
    halfIndex = SIZE / 2.;
    index1 = halfIndex;
    index2 = halfIndex - 1;

    return (salesArray[index1] + salesArray[index2]) / 2.;
}
int main()
{
    const int NUM_AGENTS = 3;
    const int NUM_EVEN = 12;
    const int NUM_ODD = 13;

    int sales_even[NUM_AGENTS][NUM_EVEN] = {
        {1856, 498, 30924, 87478, 328, 2656, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}};

    std::cout << find_median(sales_even[0], NUM_EVEN) << std::endl;
    std::cout << find_median(sales_even[1], NUM_EVEN) << std::endl;
    std::cout << find_median(sales_even[2], NUM_EVEN) << std::endl;

    // Add 0) a +1 of median one 1) a 0 2) a -0.5 of median one
    // Effect should be 0) median +0.5, 1) median is the next lower value  2) median -0.5.
    int sales_odd[NUM_AGENTS][NUM_ODD] = {
        {1856, 498, 30924, 87478, 328, 2656, 387, 3754, 387587, 2873, 276, 32, 2257},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534, 0},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434, 248}};

    std::cout << find_median(sales_odd[0], NUM_ODD) << std::endl;
    std::cout << find_median(sales_odd[1], NUM_ODD) << std::endl;
    std::cout << find_median(sales_odd[2], NUM_ODD) << std::endl;
}