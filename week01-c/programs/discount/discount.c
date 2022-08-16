#include <cs50.h>
#include <stdio.h>

// Functions Declaration:
float sale(float, int);

// Main Entry Point:
int main(void) {
    float regular_price = get_float("Regular price: $");
    int percent = get_int("Percent off: %c", '%');

    float sale_price = sale(regular_price, percent);
    printf("Sale price: $%.2f\n", sale_price);

    return 0;
}



// Implemented Functions:
float sale(float price, int percent) {
    return price * (100 - percent)/100.0;
}
