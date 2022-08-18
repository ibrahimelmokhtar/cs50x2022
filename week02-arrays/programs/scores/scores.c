#include <cs50.h>
#include <stdio.h>

int main(void) {
    int scores_number = get_int("How many scores? ");
    int scores[scores_number];
    int total = 0;

    for (int i=0; i<scores_number; i++) {
        scores[i] = get_int("Score: ");
        total += scores[i];
    }
    printf("Average score: %.2f\n", total / (float) scores_number);

    return 0;
}
