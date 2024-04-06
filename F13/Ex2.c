#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSortImproved(int arr[], int n) {
  int left = 0;
  int right = n-1;
  int swapped = 1; // để kiểm tra xem trong một vòng lặp có sự hoán đổi

  while (left < right) {
    swapped = 0;  // nếu không có sự hoán đổi nào xảy ra, giá trị của swapped vẫn là 0 và vòng lặp while sẽ kết thúc
    // Traverse from left to right and compare adjacent elements with the maximum
    for (int i = left; i < right; i++) {
      if (arr[i] > arr[i+1]) {
        swap(&arr[i], &arr[i+1]);
        swapped = 1;  // để đánh dấu sự hoán đổi
      }
    }

    // Traverse from right to left and compare adjacent elements with the minimum
    for (int i = right; i > left; i--) {
      if (arr[i] < arr[i-1]) {
        swap(&arr[i], &arr[i-1]);
        swapped = 1;  // để đánh dấu sự hoán đổi
      }
    }
    left++;
    right--;
  }
}

int main() {
  int arr[] = {3, 1, 5, 8, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  bubbleSortImproved(arr, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
