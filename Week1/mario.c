#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height of pyramid: ");
    }
    while (height < 1 || height > 8);

    for (int row = 0; row < height; row++)
    {
        for (int space = height - row - 1; space > 0; space--)
        {
            printf(" ");
        }

        for (int step = 0; step < row + 1; step++)
        {
            printf("#");
        }

        printf("\n");
    }
}