#include <stdio.h>

int main(void) {
    char* name = "Mokhtar";

    for (int i=0; name[i] != '\0'; i++) {
        printf("char: %c ... address: %p\n", *(name+i), (name+i));
    }

    return 0;
}
