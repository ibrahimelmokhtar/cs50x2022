#include <cs50.h>
#include <stdio.h>

int string_length(string);

int main(void) {
    string sentence = get_string("Enter sentence: ");

    int length = string_length(sentence);

    printf("Sentence length: %i\n", length);

    return 0;
}

int string_length(string s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }

    return i;
}
