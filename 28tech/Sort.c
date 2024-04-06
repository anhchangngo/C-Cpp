#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap 
void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// Selection Sort  O(n^2)
void selectionSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        // dung bien i de luu chi so cua phan tu be nhat
        int min_pos = i;
        // duyet tat ca ca phan tu dung sau phan tu hien tai
    for(int j = i + 1; j < n; j++){
        if(a[j] < a[min_pos]){ // giam dan >
            min_pos = j;
        }
    }
    int tmp = a[i];
    a[i] = a[min_pos];
    a[min_pos] = tmp;
    }
}
/*
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
*/

// Bubble Sort  O(n^2)
int bubbleSort(int a[], int n){
    int swapped = 1; // để kiểm tra xem trong một vòng lặp có sự hoán đổi
    while(swapped == 1){
        swapped = 0;  // nếu không có sự hoán đổi nào xảy ra, giá trị của swapped vẫn là 0 và vòng lặp while sẽ kết thúc
        for(int i = 0; i < n; i++){
            if(a[i - 1] > a[i]){
                swap(&a[i - 1], &a[i]);
                swapped = 1;  // để đánh dấu sự hoán đổi
            }
        }
    }
    return 0;
}
/*
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
    // Base case 
    if (n == 1) 
        return; 
  
    int count = 0; 
    // One pass of bubble sort. After 
    // this pass, the largest element 
    // is moved (or bubbled) to end. 
    for (int i=0; i<n-1; i++) 
        if (arr[i] > arr[i+1]){ 
            swap(&arr[i], &arr[i+1]); 
            count++; 
        } 
  
      // Check if any recursion happens or not 
      // If any recursion is not happen then return 
      if (count==0) 
           return; 
  
    // Largest element is fixed, 
    // recur for remaining array 
    bubbleSort(arr, n-1); 
} 
  
void printArray(int arr[], int n) 
{ 
    for (int i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bubbleSort(arr, n); 
    printf("Sorted array : \n"); 
    printArray(arr, n); 
    return 0; 
} 
*/

// Insertion Sort
void insertionSort(int a[], int n){
    for(int i = 0; i < n; i++){
    // lay ra phan tu chi so i
    int x = a[i], pos = i - 1;
    while(pos >= 0 && x < a[pos]){ // vi tri hien tai nam trong mang va < dg xet
        a[pos + 1] = a[pos];
        --pos; // xet vi tri phan tu truoc pos
    }
    a[pos + 1] = x; // x > hon tren sau vi tri hien tai
    }
}
/*
void insertionSortRecursive(int arr[], int n) 
{ 
    if (n <= 1) 
        return; 
  
    insertionSortRecursive(arr, n - 1); 
  
    int last = arr[n - 1]; 
    int j = n - 2; 
  
    while (j >= 0 && arr[j] > last) { 
        arr[j + 1] = arr[j]; 
        j--; 
    } 
    arr[j + 1] = last; 
} 

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main() 
{ 
    int arr[] = { 12, 11, 13, 5, 6 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    insertionSortRecursive(arr, n); 
    printArray(arr, n); 
  
    return 0; 
} 
*/

// Merge Sort    O(nlogn)
/* Chia dãy ban đầu thành dãy con cho tới khi còn 1 phần tử
sau đó trộn 2 dãy con tăng dần thành 1 dãy tăng dần 
*/

// tron 2 day con : day 1 [l, m] day 2 : [m + 1, r]
int merge(int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int cnt = 0;
    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    // Merge the temporary arrays back into a[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            cnt += n1 - i;
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
    return cnt;
}

int mergeSort(int a[], int l, int r){
    /*
    if(l >= r) return;
    int m = (l + r)/2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
    */
   int dem = 0;
   if(l < r){
    int m = (l + r)/2;
    dem += mergeSort(a, l, m);
    dem += mergeSort(a, m + 1, r);
    dem += merge(a, l, m, r);
   }
   return dem;
}

int main() {
    /*
    int a[1000], n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    */
    /*
    selectionSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    */
   /*
    bubbleSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    */
   /*
   insertionSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }   
    */
   /*
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand() % 1000;
    }
    int ans = mergeSort(a, 0, n - 1);
    printf("%d ", ans);  
    */
    int t; scanf("%d", &t);
    srand(time(NULL));
    while(t --){
        int n = 1000;
        int a[1000];
        for(int i = 0; i < n; i++){
            a[i] = rand() % 1000;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i] > a[j]){
                    ++ cnt;
                }
            }
        }
    int ans = mergeSort(a, 0, n - 1);
    printf("%d %d \n", cnt, ans); 
    }
    return 0;
}