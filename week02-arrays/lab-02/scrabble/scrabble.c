#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

const int POINTS[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
};

// Functions Declaration:
int players_number(void);
int compute_score(string);

// Main Entry Point:
int main(void) {
    // Obtain number of players:
    const int N = 2;

    // Take words and calculate scores:
    string words[N];
    int scores[N];
    for (int i=0; i<N; i++) {
        // Obtain each player word:
        words[i] = get_string("Player %i: ", i+1);

        // Calculate each word score:
        scores[i] = compute_score(words[i]);
    }

    // Check the winner:
    if (scores[0] > scores[1]) {
        printf("Player 1 wins!\n");
    } else if (scores[0] < scores[1]) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}

// Functions Implementation:
/*
    Compute words score based on given POINTS array.
*/
int compute_score(string s) {
    int score = 0, i = 0;
    while (s[i] != '\0') {
        int index = toupper(s[i]) - 'A';
        if (index >= 0 && index <= 'Z' - 'A') {
            score += POINTS[index];
        }
        i++;
    }

    return score;
}
