#include <iostream>

int main()
{
    std::cout << "Enter a Number!" << std::endl;
    char digit;
    while (true)
    {
        digit = std::cin.get();
        // Cast char to integer to find out what the in value for eol is.
        std::cout << int(digit) << std::endl;
        // EOL value is 10!.
    }
}