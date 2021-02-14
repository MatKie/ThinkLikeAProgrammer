#include <iostream>
#include <stdlib.h>

struct student
{
    int grade;
    int studentID;
    std::string name;
};

int compare_studentID(const void *voidA, const void *voidB)
{
    // Return zero if both int are equal, >0 if B>A and <0 if A>B.
    // Cast void pointers struct student pointers
    student *Ap = (student *)(voidA);
    student *Bp = (student *)(voidB);
    // Dereference pointer, maybe could do that all at once
    student A = *Ap;
    student B = *Bp;
    // subtract the element you want
    return B.studentID - A.studentID;
}
int compare_grade(const void *voidA, const void *voidB)
{
    // Return zero if both int are equal, >0 if B>A and <0 if A>B.
    // Cast void pointers struct student pointers
    student *Ap = (student *)(voidA);
    student *Bp = (student *)(voidB);
    // Dereference pointers with arrow notation
    int A = Ap->grade;
    int B = Bp->grade;
    // subtract the elements
    return B - A;
}

int main()
{

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
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compare_studentID);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << studentArray[i].name << std::endl;
        std::cout << studentArray[i].studentID << std::endl;
        std::cout << studentArray[i].grade << std::endl;
    }

    std::cout << std::endl;
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compare_grade);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << studentArray[i].name << std::endl;
        std::cout << studentArray[i].studentID << std::endl;
        std::cout << studentArray[i].grade << std::endl;
    }
}
