#include <stdio.h>

int main() {
    int arr[5] = {3, 2, 1, 4, 6};

    // Find the minimum and maximum elements in the array
    int min_idx = 0;
    int max_idx = 4;
    for (int i = 0; i < 5; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
        if (arr[4 - i] > arr[max_idx]) {
            max_idx = 4 - i;
        }
    }

    // Swap the minimum and maximum elements to their correct positions
    int temp = arr[min_idx];
    arr[min_idx] = arr[0];
    arr[0] = temp;

    temp = arr[max_idx];
    arr[max_idx] = arr[4];
    arr[4] = temp;

    // Sort the remaining elements in ascending order
    for (int i = 1; i < 4; i++) {
        int min_idx = i;
        for (int j = i + 1; j < 5; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    // Print the sorted array
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
