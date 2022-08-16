#include <cs50.h>
#include <stdio.h>

// Functions Declaration:
void meow(int);

// Main Entry Point:
int main(void) {
    int count = get_int("meow n times? ");
    meow(count);

    return 0;
}



// Implemented Functions:
void meow(int count) {
    for (int i=0; i<count; i++) {
        printf("meow");
        if (i != count-1) {
            printf(" .. ");
        } else {
            printf("\n");
        }
    }
}
