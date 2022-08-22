#include <cs50.h>
#include <stdio.h>

double fact_iteration(int);
double fact_recursion(int);

int main(void) {
    int number = 0;
    do {
        number = get_int("Number: ");
    } while (number < 0);

    double factorial_result = 0;
    for (int i=0; i<=100; i++) {
        factorial_result = fact_iteration(i);
        printf(">>> Iterative Result: %.0f\n", factorial_result);
    }

    factorial_result = fact_recursion(number);
    printf(">>> Recursive Result: %.0f\n", factorial_result);

    return 0;
}

// This can handle input number of 100 ...
double fact_iteration(int n) {
    double product = 1;
    while (n > 1) {
        product *= n;
        n--;
    }
    return product;
}

// This has memory limit dealing with input numbers greater than 12 ...
double fact_recursion(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * fact_recursion(n-1);
}
