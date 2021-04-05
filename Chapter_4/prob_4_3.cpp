#include <iostream>

// Write a replace function which replaces every occurrence of
// target with replace in source.

int length(char *s)
{
    int count = 0;
    while (s[count] != 0)
    {
        count++;
    }
    return count;
}
bool compare(char *source, int index, int target_lenth, char *target)
{
    for (int i = 0; i < target_lenth; i++)
    {
        if (source[index + i] != target[i])
        {
            return false;
        }
    }
    return true;
}

void replace(char *&source, char *target, char *replace)
{
    // How many replacements to be made and how does it change length.
    int source_length = length(source);
    int target_length = length(target);
    int replace_length = length(replace);
    int replacements = 0;

    for (int i = 0; i <= source_length - target_length; i++)
    {
        if (compare(source, i, target_length, target))
        {
            replacements++;
            i--;
            i = i + target_length;
        }
    }
    // Calculate new length
    int new_length = source_length + replacements * (replace_length - target_length);
    char *new_s = new char[new_length];

    int j = 0; // old source iterator variable
    for (int i = 0; i < new_length;)
    {
        if (compare(source, j, target_length, target))
        {
            for (int k = 0; k < replace_length; k++)
            {
                new_s[i] = replace[k];
                i++;
            }
            j = j + target_length;
        }
        else
        {
            new_s[i] = source[j];
            i++;
            j++;
        }
    }

    // Rewire pointers and put null terminator
    new_s[new_length] = 0;
    delete[] source;
    source = new_s;
}

void test_replace()
{
    char *s = new char[9];
    char *target = new char[3];
    char *replacement = new char[4];
    s[0] = 'a';
    s[1] = 'b';
    s[2] = 'c';
    s[3] = 'd';
    s[4] = 'a';
    s[5] = 'b';
    s[6] = 'e';
    s[7] = 'e';
    s[8] = 0;
    target[0] = 'a';
    target[1] = 'b';
    target[2] = 0;
    replacement[0] = 'x';
    replacement[1] = 'y';
    replacement[2] = 'z';
    replacement[3] = 0;

    std::cout << s << std::endl;
    replace(s, target, replacement);
    std::cout << s << std::endl;
}

int main()
{
    test_replace();
    return 0;
}