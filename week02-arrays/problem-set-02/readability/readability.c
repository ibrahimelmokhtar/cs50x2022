#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

// Functions Declaration:
int coleman_liau_index(int, int, int);

int main(void) {
    // Obtain user input:
    string s = get_string("Text: ");

    // Count letters, words, and sentences:
    int i = 0, letters = 0, sentences = 0;
    int words = 1;  // to count the last word ... it does NOT end with ' '
    while (s[i] != '\0') {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?') {
            // Sentences counter:
            sentences++;
        } else if (s[i] == ' ') {
            // Words counter:
            words++;
        } else if (islower(s[i]) || isupper(s[i])) {
            // Letters counter:
            letters++;
        }

        i++;
    }

    // Calculate the index:
    int index = coleman_liau_index(letters, words, sentences);

    // Display appropriate message:
    if (index < 1) {
        printf(">>> Before Grade 1\n");
    } else if (index >= 16) {
        printf(">>> Grade 16+\n");
    } else {
        printf(">>> Grade %i\n", index);
    }

    return 0;
}

// Functions Implementations:
int coleman_liau_index(int letters, int words, int sentences) {
    float L = (letters*100.0) / words;
    float S = (sentences*100.0) / words;

    return round(0.0588*L - 0.296*S - 15.8);
}
