#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    string name;
    string number;
} person;

void print_array(person[], int);
int linear_search(person[], int, string);

int main(void) {
    const int size = 2;
    person people[size];

    people[0].name = "Ibrahim";
    people[0].number = "+2-123-456-7890";

    people[1].name = "David";
    people[1].number = "+1-098-765-4321";

    print_array(people, size);

    linear_search(people, size, "Ibrahim");
    linear_search(people, size, "Samar");

}

void print_array(person people[], int size) {
    printf("{ ");
    for (int i=0; i<size; i++) {
        printf("(%s, %s)", people[i].name, people[i].number);
        if (i != size-1) {
            printf(", ");
        } else {
            printf(" ");
        }
    }
    printf("}\n");
}

int linear_search(person people[], int size, string target) {
    for (int i=0; i<size; i++) {
        if (strcmp(people[i].name, target) == 0) {
            printf(">>> %s is found with phone number: %s\n", target, people[i].number);
            return 0;
        }
    }
    printf(">>> %s is NOT found\n", target);
    return 1;
}
