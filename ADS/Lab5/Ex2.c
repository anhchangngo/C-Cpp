#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Binary Search
int binarySearch(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item) {
            return mid;
        } else if (arr[mid] < item) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

// Insertion Sort with Binary Search
void insertionSortWithBinarySearch(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Find the position for the current element using binary search
        int pos = binarySearch(arr, key, 0, j);

        // Shift the elements to make space for the current element
        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the current element in its correct position
        arr[j + 1] = key;
    }
}

int main() {
    int arr[1000];
    int n = 5;   // Number of elements in the random array
    // Or you can input any n you want by scanf("%d", &n);

    srand(time(NULL));
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 1000;
    }

    // Original array
    printf("Original random array with %d elements : ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Add a new value to the array
    int v = 800;  // You can change this value as needed
    arr[n++] = v;
    
	printf("Add element v with value 800\n");

    // Sort the array using Insertion Sort with Binary Search
    insertionSortWithBinarySearch(arr, n);

    // Sorted array
    printf("Sorted array after add new value %d : ", v);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Find the correct position for the new value
    int pos = binarySearch(arr, v, 0, n - 1);
    printf("The correct position for %d in the array is %d\n", v, pos);

    return 0;
}

// Complexity analysis of the algorithm

// Best case [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] when the linked list is already sorted.
/*
Function binarySearch(arr, item, low, high):
Since the element is already in its sorted position, the while loop in Step 1 will not execute
Step 1 :    while low <= high                   |  
Step 2 :        mid = low + (high - low) / 2    |  O(1)
Step 3 :       if arr[mid] == item              |  O(1)
Step 4 :             return mid                 |  O(1)
Step 5 :         else if arr[mid] < item        |  O(1)
Step 6 :             low = mid + 1              |  O(1)
Step 7 :         else                           |
Step 8 :             high = mid - 1             |  O(1)
Step 9 :     end while                          |
Step 10 :     return low                        |  O(1)
-> O(1)

Function insertionSortWithBinarySearch(arr, n):
Step 1 :   for i = 1 to n - 1                   |  O(n)
Step 2 :     key = arr[i]                       |  O(1)
Step 3 :     j = i - 1                          |  O(1)
Step 4 :  pos = binarySearch(arr, key, 0, j)    |  O(1) 
Step 5 :    while j >= pos                      |  O(j - pos) -> O(log n)
Step 6 :      arr[j + 1] = arr[j]               |  O(1)
Step 7 :      j = j - 1                         |  O(1)
Step 8 :    end while                           |
Step 9 :  arr[j + 1] = key                      |  O(1)
Step 10:  end for                               |
-> Complexity of Best Case : O(n * log n)
*/

// Average case [5, 2, 4, 6, 1, 3, 8, 10, 9, 7] when the linked list is distribute random
/*
Function binarySearch(arr, item, low, high):
Step 1 :    while low <= high                   |  O(log n)
Step 2 :        mid = low + (high - low) / 2    |  O(1)
Step 3 :       if arr[mid] == item              |  O(1)
Step 4 :             return mid                 |  O(1)
Step 5 :         else if arr[mid] < item        |  O(1)
Step 6 :             low = mid + 1              |  O(1)
Step 7 :         else                           |
Step 8 :             high = mid - 1             |  O(1)
Step 9 :     end while                          |
Step 10 :     return low                        |  O(1)
-> O(log n)

Function insertionSortWithBinarySearch(arr, n):
Step 1 :   for i = 1 to n - 1                   |  O(n)
Step 2 :     key = arr[i]                       |  O(1)
Step 3 :     j = i - 1                          |  O(1)
Step 4 :  pos = binarySearch(arr, key, 0, j)    |  O(log n)
Step 5 :    while j >= pos                      |  O(j - pos) -> O(n/2) on average
Step 6 :      arr[j + 1] = arr[j]               |  O(1)
Step 7 :      j = j - 1                         |  O(1)
Step 8 :    end while                           |
Step 9 :  arr[j + 1] = key                      |  O(1)
Step 10:  end for                               |
-> Complexity of Average Case : O(n * (log n + n/2)) -> O(n^2)
*/

// Worst case [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]  when the linked list is in descending order
/*
Function binarySearch(arr, item, low, high):
Step 1 :    while low <= high                   |  O(log n)
Step 2 :        mid = low + (high - low) / 2    |  O(1)
Step 3 :       if arr[mid] == item              |  O(1)
Step 4 :             return mid                 |  O(1)
Step 5 :         else if arr[mid] < item        |  O(1)
Step 6 :             low = mid + 1              |  O(1)
Step 7 :         else                           |
Step 8 :             high = mid - 1             |  O(1)
Step 9 :     end while                          |
Step 10 :     return low                        |  O(1)
-> O(log n)

Function insertionSortWithBinarySearch(arr, n):
Step 1 :   for i = 1 to n - 1                   |  O(n)
Step 2 :     key = arr[i]                       |  O(1)
Step 3 :     j = i - 1                          |  O(1)
Step 4 :  pos = binarySearch(arr, key, 0, j)    |  O(log n) -> O(n)
Step 5 :    while j >= pos                      |  O(j - pos)
Step 6 :      arr[j + 1] = arr[j]               |  O(1)
Step 7 :      j = j - 1                         |  O(1)
Step 8 :    end while                           |
Step 9 :  arr[j + 1] = key                      |  O(1)
Step 10:  end for                               |
-> Complexity of Worst Case : O(n * (log n + n)) -> O(n^2)
*/