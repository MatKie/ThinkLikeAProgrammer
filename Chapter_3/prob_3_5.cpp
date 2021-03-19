#include <iostream>
//Objective: Use same function to encode and decode

const int NUM_CHAR = 26;
const char encode_array[NUM_CHAR] = {'B',
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

char decode_array[NUM_CHAR];

std::string encode(std::string str, const char uppercase[26])

{
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

    return cipher;
}

int main()
{
    std::string str = "Hello World! Are we doing good today?";

    std::string cipher = encode(str, encode_array);

    std::cout << cipher << std::endl;
    for (int i = 0; i < NUM_CHAR; i++)
    {
        // We want to map the value of encode_array at each index
        // to normal alphabet.
        int encode_value = (int)encode_array[i] - A;
        int alphabet_value = i + A;
        decode_array[encode_value] = (char)alphabet_value;
    }

    std::string decode = encode(cipher, decode_array);

    std::cout << decode << std::endl;
}