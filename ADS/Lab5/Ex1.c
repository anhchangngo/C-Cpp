#include<stdio.h>

// Binary Search
int binarySearch(int a[], int size, int x){
    int low = 0, high = size - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] == x){
            return a[mid];
        }
        else if (a[mid] < x){
            low = mid + 1;
        }
        else {   // a[mid] > x
            high = mid - 1;
        }
    }
    return low; // display the positions when we add new value
}

// Insert a value at a given position in an array
void insertAtPosition(int a[], int size, int pos, int value) {
    for (int i = size - 1; i > pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos] = value;
}

void displayArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int a[] = {1, 2, 4, 7, 8, 9, 15};  // Sorted array
    int size_a = sizeof(a) / sizeof(a[0]);

    int v = 5;   // A new value v is added

    printf("Original array a: ");
    displayArray(a, size_a);

    int pos = binarySearch(a, size_a, v);

    insertAtPosition(a, size_a + 1, pos, v);
    
    printf("Array after add new value %d: ", v);
    displayArray(a, size_a + 1);

    printf("The correct position for %d in array is %d \n", v, pos);
    return 0;
}