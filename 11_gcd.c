// Program to find GCD of two numbers using recursion
#include <stdio.h>
#include <stdlib.h>

/* Recursive function to find GCD */
int gcd(int a, int b) {
    if (b == 0)              // base condition
        return a;
    else
        return gcd(b, a % b);   // recursive call
}

int main() {
    system("clear");
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 < 0 || num2 < 0) {
        printf("Please enter positive integers only.\n");
    } else {
        printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    }

    return 0;
}
