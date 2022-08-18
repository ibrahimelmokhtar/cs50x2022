#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) {
    if (argc > 2) {
        printf("Error: Too many command-line arguments\n");
        return 1;
    } else if (argc < 2) {
        printf("Error: Missing command-line arguments\n");
        return 1;
    }

    printf("Hello, %s\n", argv[1]);
    return 0;
}
