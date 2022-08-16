#include <cs50.h>
#include <stdio.h>

int main(void) {
    int number = get_int("Enter a number: ");

    if (number % 2 == 0) {
        printf(">> It's an EVEN number\n");
    } else {
        printf(">> It's an ODD number\n");
    }

    return 0;
}
