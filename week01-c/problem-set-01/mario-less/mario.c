#include <cs50.h>
#include <stdio.h>

// Global Variables:
const int LOWER_LIMIT = 1, UPPER_LIMIT = 8;

// Functions Declaration:
int askForHeight(void);
void drawPyramid(int);

// Main Entry Point:
int main(void) {
    // Take input height:
    printf("Enter height between %i and %i inclusive ...\n", LOWER_LIMIT, UPPER_LIMIT);
    int height = askForHeight();

    // Draw the right-aligned pyramid:
    drawPyramid(height);

    return 0;
}

// Functions Implementation:
/*
    Take an input between LOWER_LIMIT and UPPER_LIMIT inclusive.
*/
int askForHeight(void) {
    int height = 0;
    do {
        height = get_int("Height: ");
    } while (height < LOWER_LIMIT || height > UPPER_LIMIT);

    return height;
}

/*
    Draw a pyramid with the given height.
*/
void drawPyramid(int height) {
    for (int i=0; i<height; i++) {
        // Draw the empty spaces:
        for (int j=height-1; j>i; j--) {
            printf(" ");
        }

        // Draw the bricks:
        for (int j=0; j<=i; j++) {
            printf("#");
        }

        // Go to the next line:
        printf("\n");
    }
}
