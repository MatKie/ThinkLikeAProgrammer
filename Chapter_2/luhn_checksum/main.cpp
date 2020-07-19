#include <iostream>
// Program intended to solve Luhn Checksum validation, fixed length of
// six. See page 36.
int double_int(int digit)
{
    int double_digit = 2 * digit;
    if (double_digit > 9)
    {
        return (1 + double_digit % 10);
    }
    else
    {
        return double_digit;
    }
}
int main()
{
    // First only read number digit by digit and sum it up.
    char digit;
    int checksum = 0;
    std::cout << "Please provide a six figure number\n";
    for (int i = 0; i < 6; i++)
    {
        std::cin >> digit;
        digit -= '0';
        // Double every other number starting from r.h.s.
        if (i % 2 != 0)
        {
            digit = double_int(digit);
        }
        checksum += digit;
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