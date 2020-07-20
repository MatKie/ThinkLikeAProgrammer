#include <iostream>

void space()
{
    std::cout << " ";
}
void hash()
{
    std::cout << "#";
}
void endl()
{
    std::cout << std::endl;
}

int main()
{
    for (int row = 0; row < 4; row++)
    {
        for (int i = 4 - row; i < 4; i++)
        {
            space();
        }
        for (int i = 2 * row; i < 8; i++)
        {
            hash();
        }
        endl();
    }

    endl();
    endl();

    // Build the second pattern. Switching the row index to negative
    // values and taking row as absolute value inverts the triangle from
    // pattern 1. Actually this is not completly right, we miss the
    // second full row of hashes.
    for (int row = -3; row < 5; row++)
    {
        for (int i = 4 - abs(row); i < 4; i++)
        {
            space();
        }
        for (int i = 2 * abs(row); i < 8; i++)
        {
            hash();
        }
        endl();
    }

    endl();
    endl();

    // Build _correct_ pattern 2.
    for (int row = -3; row < 1; row++)
    {
        // Upper Triangle
        for (int i = 4 - abs(row); i < 4; i++)
        {
            space();
        }
        for (int i = 2 * abs(row); i < 8; i++)
        {
            hash();
        }
        endl();
    }

    for (int row = 0; row < 4; row++)
    {
        // Lower Triangle
        for (int i = 4 - abs(row); i < 4; i++)
        {
            space();
        }
        for (int i = 2 * abs(row); i < 8; i++)
        {
            hash();
        }
        endl();
    }

    endl();
    endl();

    // Third pattern
    for (int row = 0; row < 4; row++)
    {
        // Leftmost spaces
        for (int i = 0; i < row; i++)
        {
            space();
        }
        // First Hashes
        for (int i = 0; i < row + 1; i++)
        {
            hash();
        }
        // Middle spaces
        int middle_spaces = 14 - 2 * row - (2 * (row + 1));
        for (int i = 0; i < middle_spaces; i++)
        {
            space();
        }
        // Second Hashes
        for (int i = 0; i < row + 1; i++)
        {
            hash();
        }
        // Rightmost spaces
        for (int i = 0; i < row; i++)
        {
            space();
        }
        endl();
    }
    for (int nrow = -3; nrow < 1; nrow++)
    {
        int row = abs(nrow);
        // Leftmost spaces
        for (int i = 0; i < row; i++)
        {
            space();
        }
        // First Hashes
        for (int i = 0; i < row + 1; i++)
        {
            hash();
        }
        // Middle spaces
        int middle_spaces = 14 - 2 * row - (2 * (row + 1));
        for (int i = 0; i < middle_spaces; i++)
        {
            space();
        }
        // Second Hashes
        for (int i = 0; i < row + 1; i++)
        {
            hash();
        }
        // Rightmost spaces
        for (int i = 0; i < row; i++)
        {
            space();
        }
        endl();
    }
}