#include <cs50.h>
#include <stdio.h>

int main(void) {
    printf("Enter TWO integers ...\n");
    long x = get_long(">> x: ");
    long y = get_long(">> y: ");
    printf(">> x + y = %li\n", x+y);

    return 0;
}
