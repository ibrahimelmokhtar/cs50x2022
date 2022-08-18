#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) {
    string name = "CUSTOMER";
    if (argv[1]) {
        name = argv[1];
    }
    printf("Hello, %s\n", name);

    return 0;
}
