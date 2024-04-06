#include<stdio.h>

/* Linear Search
bool ls(int a[], int n, int x){
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            return true;
        }
        return false;
    }
}
*/

/*
Recursion Linear Search
#include <stdio.h>

// Define a function to perform the linear search
int linearSearch(int arr[], int size, int key)
{
    // If the size of the array is zero, return -1
    if (size == 0) {
        return -1;
    }

    // Check if the element at the current index
    // is equal to the key
    if (arr[size - 1] == key) {
        
        // If equal, return the index
        return size - 1;
    }
    // If not equal, call the function again
    // with the size reduced by 1
    return linearSearch(arr, size - 1, key);
}

// Driver code
int main()
{
    int arr[] = { 5, 15, 6, 9, 4 };
    int key = 4;
    int index
        = linearSearch(arr, sizeof(arr) / sizeof(int), key);
    if (index == -1) {
        printf("Key not found in the array.\n");
    }
    else {
        printf("The element %d is found at %d index of the "
               "given array \n",
               key, index);
    }
    return 0;
}
*/

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
    return -1;
}

/*
Recursion Binary Search
#include <stdio.h>
 
// A recursive binary search function. It returns location
// of x in given array arr[l..r] if present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    // checking if there are elements in the subarray
    if (r >= l) {
 
        // calculating mid point
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then it can only
        // be present in left subarray
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
 
        // Else the element can only be present in right
        // subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not present in array
    return -1;
}
 
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int size = sizeof(arr) / sizeof(arr[0]);
    // element to be searched
    int x = 10;
    // calling binary search
    int index = binarySearch(arr, 0, size - 1, x);
 
    if (index == -1) {
        printf("Element is not present in array");
    }
    else {
        printf("Element is present at index %d", index);
    }
 
    return 0;
}
*/

void addValue(int a[], int size, int y){  // y is the value that we add
    int i = size - 1;   // i is the last number of array
    while(i > 0 && a[i] > y){
        a[i + 1] = a[i];
        i --; 
    }
    // gan gia tri moi vao dung vi tri
    a[i + 1] = y;
}

int main(){
    int a[] = {1, 2, 4, 7, 8, 9, 15};  // Sorted array
    int size_a = sizeof(a) / sizeof(a[0]);

    int v[] = {5, 12, 18};   // New values to be added
    int size_v = sizeof(v) / sizeof(v[0]);
    
    printf("The array a : ");
    for(int i = 0; i < size_a; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    // New values v added
    for(int k = 0; k < size_v; k++){
        int value = v[k];
        addValue(a, size_a + k, value);
    // Check position that new value was added
    int pos = binarySearch(a, size_a + k + 1, value);
    if(pos != -1){
        printf("Vale %d is found in %d of array a \n", value, pos);
    }
    }
    printf("\n");

    printf("Array after a was add : ");
    for(int i = 0; i < size_a + size_v; i ++){
        printf("%d ", a[i]);
    }
    
    return 0;
}

/*
// C program for transposition to
// improve the Linear Search Algorithm
#include <stdio.h>

// Structure of the array
struct Array {

	int A[10];
	int size;
	int length;
};

// Function to print the array element
void Display(struct Array arr) {
	int i;

	// Traverse the array arr[]
	for (i = 0; i < arr.length; i++) {
		printf("%d ", arr.A[i]);
	}
	printf("\n");
}

// Function that swaps two elements
// at different addresses
void swap(int* x, int* y)
{
	// Store the value store at
	// x in a variable temp
	int temp = *x;

	// Swapping of value
	*x = *y;
	*y = temp;
}

// Function that performs the Linear
// Search Transposition
int LinearSearchTransposition(struct Array* arr, int key) {
	int i;

	// Traverse the array
	for (i = 0; i < arr->length; i++) {

		// If key is found, then swap
		// the element with it's
		// previous index
		if (key == arr->A[i]) {

			// If key is first element
			if (i == 0)
				return i;

			swap(&arr->A[i],
				&arr->A[i - 1]);

			return i;
		}
	}
	return -1;
}

// Driver Code
int main() {
	// Given array arr[]
	struct Array arr
		= { { 2, 23, 14, 5, 6, 9, 8, 12 },
			10,
			8 };

	printf("Elements before Linear"
		" Search Transposition: ");

	// Function Call for displaying
	// the array arr[]
	Display(arr);

	// Function Call for transposition
	LinearSearchTransposition(&arr, 14);

	printf("Elements after Linear"
		" Search Transposition: ");

	// Function Call for displaying
	// the array arr[]
	Display(arr);
	return 0;
}
*/

/*
// C program to implement the move to
// front to optimized Linear Search
#include <stdio.h>

// Structure of the array
struct Array {

	int A[10];
	int size;
	int length;
};

// Function to print the array element
void Display(struct Array arr)
{
	int i;

	// Traverse the array arr[]
	for (i = 0; i < arr.length; i++) {
		printf("%d ", arr.A[i]);
	}
	printf("\n");
}

// Function that swaps two elements
// at different addresses
void swap(int* x, int* y)
{
	// Store the value store at
	// x in a variable temp
	int temp = *x;

	// Swapping of value
	*x = *y;
	*y = temp;
}

// Function that performs the move to
// front operation for Linear Search
int LinearSearchMoveToFront(
	struct Array* arr, int key)
{
	int i;

	// Traverse the array
	for (i = 0; i < arr->length; i++) {

		// If key is found, then swap
		// the element with 0-th index
		if (key == arr->A[i]) {
			swap(&arr->A[i], &arr->A[0]);
			return i;
		}
	}
	return -1;
}

// Driver code
int main()
{
	// Given array arr[]
	struct Array arr
		= { { 2, 23, 14, 5, 6, 9, 8, 12 },
			10,
			8 };

	printf("Elements before Linear"
		" Search Move To Front: ");

	// Function Call for displaying
	// the array arr[]
	Display(arr);

	// Function Call for Move to
	// front operation
	LinearSearchMoveToFront(&arr, 14);

	printf("Elements after Linear"
		" Search Move To Front: ");

	// Function Call for displaying
	// the array arr[]
	Display(arr);
	return 0;
}

*/

/*

*/