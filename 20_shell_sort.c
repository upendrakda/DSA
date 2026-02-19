// Program to implement Shell Sort
#include <stdio.h>
#include <stdlib.h>

/* Function to perform Shell Sort */
void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    // Start with a big gap, then reduce the gap
    for (gap = n / 2; gap > 0; gap /= 2) {

        // Perform gapped insertion sort
        for (i = gap; i < n; i++) {
            temp = arr[i];

            // Shift earlier gap-sorted elements up until correct location found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Put temp in its correct location
            arr[j] = temp;
        }
    }
}

/* Function to display the array */
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    system("clear");
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array: ");
    display(arr, n);

    shellSort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}
