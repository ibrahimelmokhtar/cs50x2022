#include <stdio.h>

void print_array(int[], int);
int linear_search(int[], int, int);

int main(void) {
    int size = 7;
    int numbers[] = { 4, 6, 8, 2, 7, 5, 0 };
    print_array(numbers, size);

    linear_search(numbers, size, 0);
    linear_search(numbers, size, 100);
}

void print_array(int numbers[], int size) {
    printf("{ ");
    for (int i=0; i<size; i++) {
        printf("%i", numbers[i]);
        if (i != size-1) {
            printf(", ");
        } else {
            printf(" ");
        }
    }
    printf("}\n");
}

int linear_search(int numbers[], int size, int target) {
    for (int i=0; i<size; i++) {
        if (numbers[i] == target) {
            printf(">>> %i is found\n", target);
            return 0;
        }
    }

    printf(">>> %i is NOT found\n", target);
    return 1;
}
