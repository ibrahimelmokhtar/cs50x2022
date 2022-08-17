#include <cs50.h>
#include <stdio.h>

// Functions Declaration:
long get_card_number(void);
int extract_card_prefix(long);
int luhn_algorithm(long);
string extract_card_type(int, int);

// Main Entry Point:
int main(void) {
    // Card numbers available for testing:
        // long card_number = 378282246310005; // AMEX >> 15-digits
        // long card_number = 371449635398431; // AMEX >> 15-digits
        // long card_number = 5105105105105100; // MASTERCARD >> 16-digits
        // long card_number = 5555555555554444; // MASTERCARD >> 16-digits
        // long card_number = 4003600000000014; // VISA >> 16-digits
        // long card_number = 4012888888881881; // VISA >> 16-digits
        // long card_number = 4111111111111111; // VISA >> 16-digits
        // long card_number = 6176292929; // INVALID

    // Obtain the card number:
    printf("Enter your card number ...\n");
    long card_number = get_card_number();

    // Extract the card prefix:
    int prefix = extract_card_prefix(card_number);
    printf(">>\tCard Prefix\t: %i\n", prefix);

    // Check the checksum using Luhn's Algorithm:
    int number_length = luhn_algorithm(card_number);
    if (number_length) {
        printf(">>\tNumber Length\t: %i\n", number_length);
    }

    // Know the card type:
    string test_result = extract_card_type(prefix, number_length);
    printf("Card Type: %s\n", test_result);

    return 0;
}

// Functions Implementation:
/*
    Get card number from the user.
*/
long get_card_number(void) {
    long card_number = 0;
    do {
        card_number = get_long("Card Number: ");
    } while (!card_number);

    return card_number;
}

/*
    Extract card number prefix.
*/
int extract_card_prefix(long number) {
    while (number/10 > 10) {
        number /= 10;
    }

    return number;
}

/*
    Check the card number validation using checksum.
*/
int luhn_algorithm(long card_number) {
    // Initial Values:
    int checksum = 0, number_length = 0;

    // While card_number != 0:
    while (card_number) {
        // Calculate the current last digit:
        int current_digit = card_number%10;
        int current_check = current_digit + current_digit*(number_length%2);

        // Sum individual digits within the current checksum, if required:
        if (current_check > 9) {
            current_check = current_check/10 + current_check%10;
        }

        // Update the checksum value:
        checksum += current_check;

        // Update the card number:
        card_number /= 10;

        // Update the card number length:
        number_length++;
    }

    // checksum validation:
    if (checksum%10 != 0) {
        number_length = 0;
    }

    return number_length;
}

/*
    Obtain card type using (number prefix) and (number length).
*/
string extract_card_type(int prefix, int number_length) {
    // The default card type:
    string card_type = "INVALID";

    // Check for AMEX and MasterCard types:
    switch (prefix) {
        case 34:
        case 37:
            card_type = (number_length == 15) ? "AMEX" : card_type;
            break;
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            card_type = (number_length == 16) ? "MASTERCARD" : card_type;
            break;
    }

    // Change prefix to single digit:
    prefix /= 10;

    // Check for Visa type:
    switch (prefix) {
        case 4:
            card_type = (number_length == 13 || number_length == 16) ? "VISA" : card_type;
            break;
        default:
            break;
    }

    return card_type;
}
