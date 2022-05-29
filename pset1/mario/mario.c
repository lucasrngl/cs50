#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input;

    // Get user input
    do
    {
        input = get_int("Type a number: ");
    }
    while (input < 1 || input > 8);

    // Generate a new line
    for (int i = 0; i < input; i++)
    {
        // Align the hashes to right according to line
        for (int k = input - (i + 1); k > 0; k--)
        {
            printf(" ");
        }

        // Print hashes according to line
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}