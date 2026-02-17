// Program to find the factorial of a number using recursion
#include <stdio.h>
#include <stdlib.h>

/* Recursive function to find factorial */
int factorial(int n) {
    if (n == 0 || n == 1)        // base condition
        return 1;
    else
        return n * factorial(n - 1);   // recursive call
}

int main() {
    int num;

    system("clear");

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial of a negative number is not defined.\n");
    } else {
        printf("Factorial of %d is %d\n", num, factorial(num));
    }

    return 0;
}
