#include <cs50.h>
#include <stdio.h>

int main(void) {
    string s = "Hello";
    char* p = &s[0];

    printf("string  >>> address: %p ... value: %s\n", s, s);
    printf("pointer >>> address: %p ... value: %c\n", p, *p);

    return 0;
}
