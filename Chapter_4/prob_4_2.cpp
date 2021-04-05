#include <iostream>
// Give out substring of a string

int length(char *s)
{
    int count = 0;
    while (s[count] != 0)
    {
        count++;
    }
    return count;
}

// Our function returns a pointer to a char

char *substring(char *s, int position, int length)
{
    // We allocate a char array but only point to first element
    char *sub = new char[length];
    for (int i = 0; i < length; i++)
    {
        sub[i] = s[i + position - 1];
    }
    return sub;
}

void test_substring()
{
    char *str = new char[7];
    int position = 3;
    int length = 4;
    char *sub;
    str[0] = 'a';
    str[1] = 'b';
    str[2] = 'c';
    str[3] = 'd';
    str[4] = 'e';
    str[5] = 'f';
    str[6] = 'g';

    sub = substring(str, position, length);
    std::cout << sub << std::endl;
}
void test2_substring()
{
    char *str = new char[0];
    int position = 0;
    int length = 1;
    char *sub;

    sub = substring(str, position, length);
    std::cout << sub << std::endl;
}

int main()
{

    test_substring();
    test2_substring();
    return 0;
}