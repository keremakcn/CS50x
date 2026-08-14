#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int y = 1;
    int a = 0;
    do
    {
        height = get_int("Do you want how many stepness: ");
    }
    while (height <= 0 || height > 8);

    for (int q = 0; q < height; q++, y++)
    {
        for (a = height; a > y; a--)
        {
            printf(" ");
        }
        for (int i = 0; i < y; i++)
        {
            printf("#");
        }
        {
            printf("  ");
        }
        for (int b = 0; b < y; b++)
        {
            printf("#");
        }
        {
            printf("\n");
        }
    }
}
