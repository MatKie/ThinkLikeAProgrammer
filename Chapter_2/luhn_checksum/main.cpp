#include <iostream>
// Program intended to solve Luhn Checksum validation, fixed length of
// six. See page 36.

int main()
{
    // First only read number digit by digit and sum it up.
    char digit;
    int checksum = 0;
    std::cout << "Please provide a six figure number\n";
    for (int i = 0; i < 6; i++)
    {
        std::cin >> digit;
        checksum += (digit - '0');
    }
    std::cout << checksum << "\n";

    // Check if number is valid by seeing if it ends in a zero
    if (checksum % 10 != 0)
    {
        std::cout << "Not a valid number!\n";
        return 1;
    }
    else
    {
        std::cout << "This is a valid number!\n";
        return 0;
    }
    return 0;
}