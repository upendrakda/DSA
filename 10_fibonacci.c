// Program to find the fibonacci sequence using recursion
#include <stdio.h>
#include <stdlib.h>

/* Recursive function to find nth Fibonacci number */
int fibonacci(int n) {
    if (n == 0)
        return 0;          // base case
    else if (n == 1)
        return 1;          // base case
    else
        return fibonacci(n - 1) + fibonacci(n - 2);  // recursive call
}

int main() {
    system("clear");
    
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number.\n");
    } else {
        printf("Fibonacci sequence:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}
