#include <stdio.h>
#include <stdlib.h>

// Functions Declaration:
int get_int(char*);
float get_float(char*);
char* get_string(char*);

// Main Entry Point:
int main(void) {
    int i = get_int("integer: ");
    printf(">>> integer: %i\n", i);

    float f = get_float("float: ");
    printf(">>> float: %.2f\n", f);

    char* s = get_string("string: ");
    printf(">>> string: %s\n", s);


    return 0;
}

// Functions Implementation:
int get_int(char* message) {
    printf("%s", message);

    int input;
    scanf("%i", &input);

    return input;
}

float get_float(char* message) {
    printf("%s", message);

    float input;
    scanf("%f", &input);

    return input;
}

char* get_string(char* message) {
    printf("%s", message);

    char* input = malloc(100);
    // scanf("%s", input);  // This will take only ONE word ... until it finds a SPACE ' ' character.
    scanf("\n%[^\n]%*c", input);

    return input;
}
