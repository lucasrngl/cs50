#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Init count variables
    int letterCount = 0;
    int sentenceCount = 0;
    // wordCount starts w/ 1 because I presume that we'll always have at least one word
    int wordCount = 1;

    // Get user input
    string text = get_string("Text: ");

    // Get the text length
    int len = strlen(text);

    // For loop to count every letter, setence and word
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letterCount++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentenceCount++;
        }
        else if (isspace(text[i]))
        {
            wordCount++;
        }
    }

    float letterAverage = ((float) letterCount / (float) wordCount) * 100;
    float sentenceAverage = ((float) sentenceCount / (float) wordCount) * 100;
    // Apply Coleman-Liau index to get the text grade
    int grade = round(0.0588 * letterAverage - 0.296 * sentenceAverage - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }

    printf("Grade %i\n", grade);
}