#include<stdio.h>
int max(int arr[], int first, int last) {
    if (first == last)
        return arr[first];
    else{
    int mid = first + (last - first) / 2;
    int a = max(arr, first, mid);
    int b = max(arr, mid + 1, last);
    
    if (a < b)
        return b;
    else
        return a;
    }
}
int main(){
   int arr[] = {3,18,2,14,6};
   int n = sizeof(arr) / sizeof(arr[0]);
   int max_value = max(arr, 0, n - 1);
 printf("max = %d",max_value);
}