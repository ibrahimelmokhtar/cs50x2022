#include <stdio.h>

void swap(int*, int*);

int main(void) {
    int x = 1, y = 2;
    printf("x: %i ... y: %i\n", x, y);
    swap(&x, &y);
    printf("x: %i ... y: %i\n", x, y);

    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
