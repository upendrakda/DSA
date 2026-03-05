// Program to implent Sequential search
#include <stdio.h>
#include <stdlib.h>

/* Function to perform sequential search */
int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; // Return index if key is found
    }
    return -1; // Return -1 if key is not found
}

int main() {
    system("clear");
    int n, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = sequentialSearch(arr, n, key);

    if (result != -1)
        printf("Element %d found at position %d.\n", key, result + 1);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}
