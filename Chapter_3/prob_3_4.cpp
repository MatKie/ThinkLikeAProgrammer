#include <iostream>

int main()
{
    const int NUM_CHAR = 26;
    const char uppercase[NUM_CHAR] = {'B',
                                      'W',
                                      'V',
                                      'H',
                                      'K',
                                      'M',
                                      'R',
                                      'F',
                                      'L',
                                      'U',
                                      'I',
                                      'E',
                                      'T',
                                      'J',
                                      'A',
                                      'O',
                                      'Z',
                                      'Y',
                                      'D',
                                      'Q',
                                      'X',
                                      'G',
                                      'C',
                                      'N',
                                      'P',
                                      'S'};
    // Get the starting point, number of letters, and offset
    // between start lower and upper case letters.
    const int A = (int)'A';
    const int letters = 26;
    const int offset = (int)'a' - A;

    std::string str = "Hello World! Are we doing good today?";
    const int STRING_SIZE = str.size();
    std::string cipher;

    for (int i = 0; i <= STRING_SIZE; i++)
    {
        int casted_letter = (int)str[i] - A;
        // Capital letter
        if (casted_letter < letters && casted_letter >= 0)
        {
            cipher += uppercase[casted_letter];
        }
        // Lower case letters
        else if (casted_letter < (letters + offset) && casted_letter >= offset)
        {
            cipher += uppercase[casted_letter - offset];
        }
        else
        {
            cipher += str[i];
        }
    }

    std::cout << cipher << std::endl;
}