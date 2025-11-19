#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents = get_cents();

    int quarters = calculate_quarters(cents);
    cents -= quarters * 25;

    int dimes = calculate_dimes(cents);
    cents -= dimes * 10;

    int nickels = calculate_nickels(cents);
    cents -= nickels * 5;

    int pennies = calculate_pennies(cents);
    cents -= pennies;

    int coins = quarters + dimes + nickels + pennies;

    printf("%i\n", coins);
}

int get_cents(void)
{
    int c;
    do
    {
        c = get_int("Enter number of cents: ");
    }
    while (c < 1);
    return c;
}

int calculate_quarters(int cents)
{
    return cents / 25;
}

int calculate_dimes(int cents)
{
    return cents / 10;
}

int calculate_nickels(int cents)
{
    return cents / 5;
}

int calculate_pennies(int cents)
{
    return cents;
}