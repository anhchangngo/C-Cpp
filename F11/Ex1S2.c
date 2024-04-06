#include <stdio.h>

void recursiveSelectionSort(int arr[], int startIndex, int size) {
    if (startIndex < size) {
        // Find the index of the minimum element in the unsorted part
        int minIndex = startIndex;
        for (int i = startIndex + 1; i < size; ++i) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }

        // Swap the found minimum element with the first element
        int temp = arr[startIndex];
        arr[startIndex] = arr[minIndex];
        arr[minIndex] = temp;

        // Recursively sort the rest of the array
        recursiveSelectionSort(arr, startIndex + 1, size);
    }
}

int main() {
    // Example array
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Call the recursive selection sort function
    recursiveSelectionSort(arr, 0, size);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
