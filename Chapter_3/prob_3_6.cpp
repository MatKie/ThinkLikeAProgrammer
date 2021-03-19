#include <iostream>
#include <time.h>
//Objective: Use same function to encode and decode

const int NUM_CHAR = 26;
char encode_array[NUM_CHAR];
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

bool check_duplicate(int random_number, int check_array[], const int check_array_size)
// Check if random_number is a number we already used
{
    for (int i = 0; i < check_array_size; i++)
    {
        if (random_number == check_array[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::string str = "Hello World! Are we doing good today?";

    srand((unsigned)time(NULL));

    // Cannot be a number between 0&25 bc else we cannot allocate 26
    // letters uniquely.
    int check_array[NUM_CHAR];
    for (int i = 0; i < NUM_CHAR; i++)
    {
        check_array[i] = -1;
    }

    for (int i = 0; i < NUM_CHAR; i++)
    // Make sure random number is not same as index or already used to
    // fulfill requirements of exercise. Retrying might not be best solution,
    // but quickest to implement.
    {
        int rand_number = rand() % NUM_CHAR;
        if (rand_number == i || check_duplicate(rand_number, check_array, NUM_CHAR))
        {
            i--;
        }
        else
        {
            encode_array[i] = (char)(rand_number + A);
            check_array[i] = rand_number;
        }
    }

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