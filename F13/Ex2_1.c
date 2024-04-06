/*
Given an array of n elements, the Selection sort algorithm selects the minimum or maximum on
every pass on the array, and place it at its correct position (ascending order).
We want to implement an improve version of this sorting algorithm. The idea is to sort both
maximum (at the end) and minimum (at the beginning) in one:
        Find the minimum and place it on the left.
        Find the maximum and place it on the right.
        Repeat the process until the array is sorted.
*/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int a[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int min_idx = left;
        int max_idx = right;

        for (int i = left + 1; i < right; i++) {
            if (a[i] < a[min_idx]) {
                min_idx = i;
            } else if (a[i] > a[max_idx]) {
                max_idx = i;
            }
        }

        // Swap minimum element with the leftmost element
        swap(&a[min_idx], &a[left]);

        // If the maximum element was at the leftmost position, update its index
        if (max_idx == left) {
            max_idx = min_idx;
        }

        // Swap maximum element with the rightmost element
        swap(&a[max_idx], &a[right]);

        // Move the boundaries inward
        left++;
        right--;
    }
}

int main() {
    int a[] = {1, 8, 2, 0, 17, 4, 20};
    int size = sizeof(a) / sizeof(a[0]);

    printf("Unsorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    selectionSort(a, size);

    printf("\nSorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}


