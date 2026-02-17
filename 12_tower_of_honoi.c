// Program to implement tower of honoi using recursion
#include <stdio.h>
#include <stdlib.h>

/* Recursive function to solve Tower of Hanoi */
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {   // base case
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towerOfHanoi(n - 1, source, auxiliary, destination);               // Step 1
    printf("Move disk %d from %c to %c\n", n, source, destination);   // Step 2
    towerOfHanoi(n - 1, auxiliary, destination, source);             // Step 3
}

int main() {
    system("clear");
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of disks must be positive.\n");
    } else {
        printf("Steps to solve Tower of Hanoi:\n");
        towerOfHanoi(n, 'A', 'C', 'B');
    }

    return 0;
}
