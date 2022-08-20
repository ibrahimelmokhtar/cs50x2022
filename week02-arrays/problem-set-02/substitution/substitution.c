#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Functions Declaration:
bool is_valid_key(string);
void cipher(string, string);

int main(int argc, string argv[]) {
    // Check key is a valid 26 characters long:
    bool is_valid = (argc == 2) ? is_valid_key(argv[1]) : false;

    // Display appropriate error message, if needed:
    if (argc != 2) {
        printf(">>> Usage: ./substitution key\n");
        return 1;
    } else if (!is_valid) {
        printf(">>> Key must contain 26 characters.\n");
        return 1;
    }

    // Obtain encryption key from command-line:
    string key = argv[1];

    // Obtain plain text from the user:
    string plaintext = get_string("plaintext:  ");

    // Encrypt plain text:
    printf("ciphertext: ");
    cipher(plaintext, key);

    return 0;
}

// Functions Implementation:
bool is_valid_key(string s) {
    bool is_valid = true;
    if (strlen(s) != 26) {
        is_valid = false;
    }

    return is_valid;
}

void cipher(string plain, string key) {
    char cipher = '\n';
    for (int i=0; i<strlen(plain); i++) {
        cipher = plain[i];

        // Change char based on its case:
        if (islower(plain[i])) {
            cipher = tolower(key[plain[i] - 'a']);
        } else if (isupper(plain[i])) {
            cipher = toupper(key[plain[i] - 'A']);
        }

        // Display encrypted char:
        printf("%c", cipher);
    }
    printf("\n");
}
