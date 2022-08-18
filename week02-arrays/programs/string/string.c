#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    string sentence = get_string("Sentence: ");

    printf(">>> Entered sentence: ");
    for (int i=0, n=strlen(sentence); i<n; i++) {
        printf("%c", sentence[i]);
    }

    printf("\n");

    return 0;
}
