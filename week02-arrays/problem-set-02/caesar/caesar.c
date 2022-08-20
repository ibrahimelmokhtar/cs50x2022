#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Functions Declaration:
bool is_digit_key(string);
void cipher(string, int);

// Main Entry Point:
int main(int argc, string argv[]) {
    // Check key is digit:
    bool is_digit = is_digit_key(argv[1]);

    // Display appropriate error message, if needed:
    if (argc != 2 || atoi(argv[1]) < 0 || !is_digit) {
        printf(">>> Usage: ./caesar key\n");
        return 1;
    }

    // Obtain encryption key from command-line:
    int key = atoi(argv[1]);

    // Obtain plain text from the user:
    string plaintext = get_string("plaintext:  ");

    // Encrypt plain text:
    printf("ciphertext: ");
    cipher(plaintext, key);

    return 0;
}

// Functions Implementation:
bool is_digit_key(string s) {
    bool is_digit = true;
    int i = 0;
    while (s[i] != '\0') {
        if (!isdigit(s[i])) {
            is_digit = false;
            break;
        }
        i++;
    }

    return is_digit;
}

void cipher(string plain, int key) {
    int i = 0;
    while (plain[i] != '\0') {
        char current_char = plain[i];

        // Change char based on its case:
        if (islower(plain[i])) {
            current_char = 'a' + (plain[i] - 'a' + key) % 26;
        } else if (isupper(plain[i])) {
            current_char = 'A' + (plain[i] - 'A' + key) % 26;
        }

        // Display encrypted char:
        printf("%c", current_char);

        i++;
    }
    printf("\n");
}
