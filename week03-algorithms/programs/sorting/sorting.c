#include <cs50.h>
#include <stdio.h>
#include <time.h>

// Functions Declaration:
void print_array(int[], int);
void reset_array(int [], int[], int);
void selection_sort(int[], int);
void bubble_sort(int[], int);
void merge_sort(int[], int);

// Main Entry Point:
int main(void) {
    const int size = 8;
    int numbers[size];
    // int reset[] = { 0, 1, 1, 2, 3, 4, 6, 8 };
    int reset[] = { 1, 4, 2, 8, 0, 6, 1, 3 };

    reset_array(numbers, reset, size);
    printf(">>> Start Selection Sort:\n");
    print_array(numbers, size);
    selection_sort(numbers, size);
    printf("\n");

    reset_array(numbers, reset, size);
    printf(">>> Start Bubble Sort:\n");
    print_array(numbers, size);
    bubble_sort(numbers, size);
    printf("\n");

    reset_array(numbers, reset, size);
    printf(">>> Start Merge Sort:\n");
    print_array(numbers, size);
    merge_sort(numbers, size);
    printf("\n");

    return 0;
}

// Functions Implementation:
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

void reset_array(int numbers[], int reset[], int size) {
    for (int i=0; i<size; i++) {
        numbers[i] = reset[i];
    }
}

void selection_sort(int numbers[], int size) {
    for (int i=0; i<size-1; i++) {
        int smallest = numbers[i];
        int smallest_index = i;
        for (int j=i; j<size; j++) {
            // if found a smaller number than current small number:
            if (numbers[j] < smallest) {
                // Update the smallest number and smallest index:
                smallest = numbers[j];
                smallest_index = j;
            }
        }
        // Swap these TWO numbers:
        int temp = numbers[i];
        numbers[i] = numbers[smallest_index];
        numbers[smallest_index] = temp;

        // Display the updated array:
        print_array(numbers, size);
    }
}


void bubble_sort(int numbers[], int size) {
    for (int i=0; i<size; i++) {
        // to quit the algorithm if no swapping occurred:
        bool is_swapped = false;

        for (int j=0; j<size-1-i; j++) {
            if (numbers[j] > numbers[j+1]) {
                // swapping occurred:
                is_swapped = true;

                // Swap these TWO numbers:
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;

                // Display the updated array:
                print_array(numbers, size);
            }
        }

        // quit if no swapping occurred:
        if (!is_swapped) {
            break;
        }
    }
}

void merge_sort(int numbers[], int size) {
}
