#include <cs50.h>
#include <stdio.h>

// Functions Declaration:
void drawCoins(int);
void drawBricks(int);

// Main Entry Point:
int main(void) {
    int n = get_int("Number of items: ");
    drawCoins(n);
    drawBricks(n);

    return 0;
}

// Draw Coin Containers:
void drawCoins(int n) {
    printf(">>> Coin Containers ... \n");
    for (int i=0; i<n; i++) {
        printf("?");
    }
    printf("\n");
}

// Draw Theme Bricks:
void drawBricks(int n) {
    printf(">>> Bricks ... \n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("#");
        }
        printf("\n");
    }
}
