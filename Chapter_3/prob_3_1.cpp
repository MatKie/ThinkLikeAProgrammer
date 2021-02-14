#include <iostream>
#include <stdlib.h>

int compare_int(const void *voidA, const void *voidB)
{
    // Return zero if both int are equal, >0 if B>A and <0 if A>B.
    // Cast void pointers to int pointers
    int *intA = (int *)(voidA);
    int *intB = (int *)(voidB);
    // Dereference pointers and subtract
    return *intB - *intA;
}

int main()
{
    struct student
    {
        int grade;
        int studentID;
        std::string name;
    };

    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronice"}};

    // Supply address to first item we want to compare
    // Problem: we cant just put &studentArray[0].StudentID here because
    // then qsort still switches blocks of memory of sizeof(student) back
    // and forth and that results in wrong ordering.
    qsort(&studentArray[0].grade, ARRAY_SIZE, sizeof(student), compare_int);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << studentArray[i].name << std::endl;
        std::cout << studentArray[i].studentID << std::endl;
        std::cout << studentArray[i].grade << std::endl;
    }
}
