#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble_sort_iteration(int array[], int size){
    int check = 1;
    while (check == 1){
        check = 0;
        for (int i = 1; i < size; i ++ ){
            if (array[i - 1] > array[i]){
                swap(&array[i - 1], &array[i]);
                check = 1;
            }
        }
    }
}

void Bubble_sort_recursion(int array[], int size, int index, int check){
    if (check == 0 && index == size){
        return;
    }
    if (check == 1 && index == size){
        Bubble_sort_recursion(array, size, 1, 0);
        return;
    }
    if (array[index - 1] > array[index]){
        swap(&array[index - 1], &array[index]);
        Bubble_sort_recursion(array, size, index + 1, 1);
    }
    else{
        Bubble_sort_recursion(array, size, index + 1, check);
    }
}

void display_array(int array[], int size){
    for (int i = 0; i < size; i ++){
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(){
    int array[] = {1,6,2,87,1,74,2,8};
    int array_size = sizeof(array)/sizeof(array[0]);
    Bubble_sort_iteration(array, array_size);
    display_array(array, array_size);
    int array2[] = {1,6,2,87,1,74,2,8};
    Bubble_sort_recursion(array2, array_size, 1, 0);
    display_array(array2, array_size);
}

/*
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
*/