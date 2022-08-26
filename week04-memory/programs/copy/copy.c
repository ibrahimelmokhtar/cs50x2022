#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    char* s = get_string("first string: ");
    char* t = NULL;

    // Count length of s:
    int length=0;
    while (s[length] != '\0') {
        length++;
    }

    // Allocate specific number of bytes of memory:
    t = malloc(((length+1)*sizeof(char)));
    if (t == NULL) {
        printf("Memory is NOT allocated correctly\n");
        return 1;
    }

    // Copy s into t:
    for (int i=0; i <= length+1; i++) {
        t[i] = s[i];
    }

    // Check that there is already a string to manipulate:
    if (length > 0) {
        // Uppercase the first char:
        t[0] = toupper(t[0]);

        // Display the result:
        printf("s: %s ... t: %s\n", s, t);
    }


    // Free the allocated memory:
    free(t);

    return 0;
}
