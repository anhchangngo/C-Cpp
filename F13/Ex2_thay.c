/*

Given an array of n elements, the Bubble sort algorithm swaps repeatedly the adjacent elements if they are in the wrong order (ascending order). We want to implement an improve version of this sorting algorithm.
The idea is to sort both maximum (at the end) and minimum (at the beginning) in one array is sorted from both ends.
- Traverse from left to right and compare adjacent elements and the maximum
right side.
- Traverse from right to left and compare adjacent elements and the minimum is placed at left side.
- Repeat the process until the array is sorted

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int a[], int n){
    int swapped = 1;
    int begin = 0;
    int end = n - 1;

    while(swapped == 1){
        swapped = 0;
        for(int i = begin; i < end; i ++){
            if(a[i] > a[i + 1]){
                swap(&a[i], &a[i + 1]);
                swapped = 1;
            }
        }

        for(int j = end; j >= begin; j --){
            if(a[j] < a[j - 1]){
                swap(&a[j], &a[j - 1]);
                swapped = 1;
            }
        }
        begin ++;
        end --;
    }
}

int main(){
    int a[] = {1, 5, 2, 10, 9, 15};
    int size = sizeof(a) / sizeof(a[0]);

    bubbleSort(a, size);
    for(int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
}

// Complexity O(n^2)
// we need to process n elements so we need n iterations
// in each iterations, we have to make n comparisons (the loop for)
// in total, the complexity of the program is O(n^2)
// in the best scenario, when the array is sorted, the complexity is O(n).
