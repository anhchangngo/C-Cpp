/*
Given an array of natural numbers as following: 4, 15, 45, 9, 40, 27, 3, 5, 10.
In this problem, we try to find all triplets (a, b, c) where a number is the product of two other
numbers in the array i.e. a = b*c; or b = a*c; or c = a*b.
The expect outcome of the above array is: {(15, 3, 5}, (45, 9, 5), (4, 40, 10), (9, 27, 3), (15, 45, 3)}
*/

#include <stdio.h>
#include <math.h>

int triplets(int a, int b, int c){
    if((a == b * c) || (b == a * c) || (c == a * b)){
        return 1;
    }
    else
    return 0;
}

void loop(int arr[], int n){  // n is the length of array
    for (int i = 0; i < n; i++){
        for(int k = i + 1; k < n; k++){
            for(int j = k + 1; j < n; j++){
                if (triplets(arr[i], arr[k], arr[j])){
                    printf("(%d %d %d) \n", arr[i], arr[k], arr[j]);
                }
            }
        }
    }
}

int main(){
    int arr[] = {4, 15, 45, 9, 40, 27, 3, 5, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    loop(arr, size);
}