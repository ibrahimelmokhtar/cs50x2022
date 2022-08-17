#include <cs50.h>
#include <stdio.h>

// Global Variables:
const int PENNY = 1, NICKEL = 5, DIME = 10, QUARTER = 25;

// Functions Declaration:
int get_cents(void);
int calculate_quarters(int);
int calculate_dimes(int);
int calculate_nickels(int);
int calculate_pennies(int);

// Main Entry Point:
int main(void) {
    // Take input height:
    printf("Enter owed cents ...\n");
    int cents = get_cents();

    // Calculate the output:
    int quarters = calculate_quarters(cents);
    int dimes = calculate_dimes(cents);
    int nickels = calculate_nickels(cents);
    int pennies = calculate_pennies(cents);

    // Display the calculated results:
    int coins = quarters + dimes + nickels + pennies;
    printf("Number of coins: %i ... [Q: %i, D: %i, N: %i, P: %i]\n", coins, quarters, dimes, nickels, pennies);

    return 0;
}

// Functions Implementation:
/*
    Take an input for owed cents.
*/
int get_cents(void) {
    int cents = 0;
    do {
        cents = get_int("Cents: ");
    } while (cents <= 0);

    return cents;
}

int calculate_quarters(int cents) {
    return cents / QUARTER;
}

int calculate_dimes(int cents) {
    return (cents % QUARTER) / DIME;
}

int calculate_nickels(int cents) {
    return ((cents % QUARTER) % DIME) / NICKEL;
}

int calculate_pennies(int cents) {
    return ((cents % QUARTER) % NICKEL) / PENNY;
}
