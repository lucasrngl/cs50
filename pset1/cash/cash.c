#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;

    // Get user input (only numbers more or equal to 0)
    do
    {
        cents = get_int("How many cents? ");
    }
    while (cents < 0);

    return cents;
}

int calculate_quarters(int cents)
{
    int quarters = 0;

    // Verify if the module of cents / quarters is 0
    // If true, assign 1 to quarter count
    for (int i = cents; i > 0; i--)
    {
        if (i % 25 == 0)
        {
            quarters++;
        }
    }

    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;

    // Verify if the module of cents / dimes is 0
    // If true, assign 1 to dimes count
    for (int i = cents; i > 0; i--)
    {
        if (i % 10 == 0)
        {
            dimes++;
        }
    }

    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = 0;

    // Verify if the module of cents / nickels is 0
    // If true, assign 1 to nickels count
    for (int i = cents; i > 0; i--)
    {
        if (i % 5 == 0)
        {
            nickels++;
        }
    }

    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = 0;

    // Verify if the module of cents / pennies is 0
    // If true, assign 1 to pennies count
    for (int i = cents; i > 0; i--)
    {
        if (i % 1 == 0)
        {
            pennies++;
        }
    }

    return pennies;
}