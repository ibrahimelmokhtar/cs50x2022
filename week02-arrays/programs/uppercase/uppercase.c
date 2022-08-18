#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    string s = get_string("Input: ");

    for (int i=0, n=strlen(s); i<n; i++) {
        // Run this solution:
        // if (s[i] >= 'a' && s[i] <= 'z') {
        //     s[i] = s[i] - ('a'-'A');
        // }

        // OR this solution: (using <ctype.h>)
        s[i] = toupper(s[i]);
    }

    printf("Output: %s\n", s);

    return 0;
}
