#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, string argv[])
{
    if (argc == 2 && only_digits(argv[1]))
    {
        int key = atoi(argv[1]);
        string plain = get_string("plaintext: ");
        int length = strlen(plain);

        printf("ciphertext: ");

        for (int i = 0; i < length; i++)
        {
            if (plain[i] >= 'a' && plain[i] <= 'z')
            {
                printf("%c", (((plain[i] - 'a') + key) % 26) + 'a');
            }
            else if (plain[i] >= 'A' && plain[i] <= 'Z')
            {
                printf("%c", (((plain[i] - 'A') + key) % 26) + 'A');
            }
            else
            {
                printf("%c", plain[i]);
            }
        }

        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
}
