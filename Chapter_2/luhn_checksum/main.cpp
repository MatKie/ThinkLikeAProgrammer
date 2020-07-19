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
    // Read arbitrary lenght input.
    char digit;
    int casted_digit;
    int checksum_even = 0;
    int checksum_odd = 0;
    int doubled_digit, checksum;
    int i = 0;
    // Init digit outside loop to push reading the new digit to the end
    // of the loop therefore avoiding processing the EOL character.
    std::cout << "Please provide an integer number\n";
    digit = std::cin.get();
    while (int(digit) != 10)
    {
        casted_digit = digit - '0';
        int doubled_digit = double_int(casted_digit);
        // For even number of figures, add the doubled digit to
        // checksum_even and for odd number of figures to checksum_odd.
        if (i % 2 == 1)
        {
            checksum_even += doubled_digit;
            checksum_odd += casted_digit;
        }
        else
        {
            checksum_even += casted_digit;
            checksum_odd += doubled_digit;
        }
        // Read next digit and increase loop variable.
        digit = std::cin.get();
        i++;
    }
    i--; // Necessary because we increased it while reading EOL.
    if (i % 2 == 0)
    {
        checksum = checksum_odd;
    }
    else
    {
        checksum = checksum_even;
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