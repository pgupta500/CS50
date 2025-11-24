#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int size = strlen(text);

    int sentences = 0;
    int letters = 0;
    int words = 1;

    for (int i = 0; i < size; i++)
    {
        char c = text[i];

        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
        else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            letters++;
        }
        else if (c == ' ')
        {
            words++;
        }
    }

    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1){
        printf("Before Grade 1\n");
    }
    else if (index >= 16){
         printf("Grade 16+\n");
    }
    else{
        printf("Grade %i\n", index);
    }
}
