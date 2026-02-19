// Program to implement Bubble Sort 
#include <stdio.h>
#include <stdlib.h>

/* Function to perform Bubble Sort */
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0; // flag to check if any swapping happened in this pass

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        // If no two elements were swapped in inner loop, array is already sorted
        if (swapped == 0)
            break;
    }
}

/* Function to display the array */
void display(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    system("clear");
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array: ");
    display(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}
