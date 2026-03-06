// Program to implement Binaryn Search
#include <stdio.h>
#include <stdlib.h>

/* Function to perform Binary Search */
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = low + (high - low) / 2; // to avoid overflow

        if (arr[mid] == key)
            return mid; // key found at index mid
        else if (arr[mid] < key)
            low = mid + 1; // search in right half
        else
            high = mid - 1; // search in left half
    }

    return -1; // key not found
}

int main() {
    system("clear");
    int n, key, result;

    printf("Enter number of elements (sorted): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in sorted order: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Element %d found at position %d.\n", key, result + 1);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}
