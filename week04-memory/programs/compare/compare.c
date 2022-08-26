#include <cs50.h>
#include <stdio.h>

int main(void) {
    char* s = get_string("first string: ");
    char* t = get_string("second string: ");

    // Compare:
    for (int i=0; s[i] != '\0'; i++) {
        if (*(s+i) != *(t+i)) {
            printf("Different strings\n");
            return 1;
        }
    }

    printf("Same strings\n");

    return 0;
}
