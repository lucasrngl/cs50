#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char ALPHABET[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

bool only_digits(string s);

int main(int argc, string argv[])
{
    // Verify if user digits number or even digit something
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv to int, and get the module of argv / 26 to use in ALPHABET array
    int key = atoi(argv[1]) % 26;

    // Get user input
    string input = get_string("plaintext: ");

    // Get input length
    int len = strlen(input);
    // Declare the cipher variable with "len" length
    char cipher[len];

    // Runs ALPHABET array
    for (int i = 0; i < 26; i++)
    {
        // Runs input length
        for (int j = 0; j < len; j++)
        {
            // Verify if it's an alphanumeric
            if (isalnum(input[j]))
            {
                // Verify equality, upper or lowercase
                if (input[j] == ALPHABET[i] || input[j] == toupper(ALPHABET[i]))
                {
                    // If i + key is greater than ALPHABET length, It adapt the index to get the right letter in the array
                    if (i + key > 25)
                    {
                        // Auxiliar variable to help on the adaptation
                        int aux = key - (25 - i) - 1;
                        // Only to know if is upper or lowercase
                        if (isupper(input[j]))
                        {
                            cipher[j] = toupper(ALPHABET[aux]);
                        }
                        else
                        {
                            cipher[j] = ALPHABET[aux];
                        }
                    }
                    // If i + key isn't greater than 25, this code runs
                    else
                    {
                        // To know again if is lower or uppercase
                        if (isupper(input[j]))
                        {
                            cipher[j] = toupper(ALPHABET[i + key]);
                        }
                        else
                        {
                            cipher[j] = ALPHABET[i + key];
                        }
                    }
                }
            }
            // If isn't alphanumeric, we recycle the char
            else
            {
                cipher[j] = input[j];
            }
        }
    }

    printf("ciphertext: ");

    // Runs cipher array to print correct on the screen
    for (int i = 0; i < len; i++)
    {
        printf("%c", cipher[i]);
    }

    printf("\n");
}

// This function verify if the user inputs a digit or other char
bool only_digits(string s)
{
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }

    return true;
}