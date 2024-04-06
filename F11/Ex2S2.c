/*

improve the Selection Sort by using Binary Recursion
Sorted part 1   | Unsorted part     | Sorted part II
- Find the minimum and maximum recursively from the unsorted part (two recursive functions)
- Put the minimum at the end of the sorted part I (which is empty at the beginning)
- Put the maximum at the front of the sorted part II (which is empty at the beginning)

*/

#include <stdio.h>

// Function to find the index of the minimum element in the array within a given range
int findMinIndexInRange(int arr[], int start, int end) {
    int minIndex = start;
    
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    
    return minIndex;
}
/*
int findMinIndexInRange(int arr[], int start, int end) {
    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    int leftMin = findMinIndexInRange(arr, start, mid);
    int rightMin = findMinIndexInRange(arr, mid + 1, end);

    return (arr[leftMin] < arr[rightMin]) ? leftMin : rightMin;
}
*/
// Function to find the index of the maximum element in the array within a given range
int findMaxIndexInRange(int arr[], int start, int end) {
    int maxIndex = start;
    
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    
    return maxIndex;
}

/*
int findMaxIndexInRange(int arr[], int start, int end) {
    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    int leftMax = findMaxIndexInRange(arr, start, mid);
    int rightMax = findMaxIndexInRange(arr, mid + 1, end);

    return (arr[leftMax] > arr[rightMax]) ? leftMax : rightMax;
}

*/
// Function to swap two elements in the array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Recursive function for binary selection sort
// Recursive function for binary selection sort
void binarySelectionSort(int arr[], int start, int end) {
    if (start >= end) {
        // Base case: if the range is empty or has only one element, it is already sorted
        return;
    }

    // Find the index of the minimum and maximum elements in the remaining range
    int minIndex = findMinIndexInRange(arr, start, end);
    int maxIndex = findMaxIndexInRange(arr, start, end);

    // Swap the minimum element with the first element in the unsorted part
    swap(arr, minIndex, start);

    // If the maximum element was at the first position, update maxIndex to the new first position
    if (maxIndex == start) {
        maxIndex = minIndex;
    }

    // Swap the maximum element with the last element in the unsorted part
    swap(arr, maxIndex, end);

    // Recursively call binary selection sort for the remaining range
    binarySelectionSort(arr, start + 1, end - 1);
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Call the binary selection sort function
    binarySelectionSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}