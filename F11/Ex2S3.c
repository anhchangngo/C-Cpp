
#include <stdio.h>
#include <math.h>

int triplets(int a, int b, int c){
    if((a == b * c) || (b == a * c) || (c == a * b)){
        return 1;
    }
    else
    return 0;
}
/*
The function triplets has a constant time complexity since it involves basic arithmetic 
operations and comparisons, so we can consider it as O(1).
*/

void loop(int arr[], int day_a, int day_b, int day_c, int n){  // n is the length of array
    int a = arr[day_a];
    int b = arr[day_b];
    int c = arr[day_c];
    if(triplets(a, b, c) == 1 || triplets(a, c, b) == 1 || triplets(c, a, b) == 1){
        printf("(%d %d %d) \n", a, b, c);
    }
    if(day_c < n - 1){
        loop(arr, day_a, day_b, day_c + 1, n);
    }
    else if (day_b < n - 2){
        loop(arr, day_a, day_b + 1, day_b + 2, n);
    }
    else if (day_a < n - 3){
        loop(arr, day_a + 1, day_a + 2, day_a + 3, n);
    }   
}
/*
The loop function is a recursive function that goes through all possible triplets in the array.
It starts with an initial call with day_a = 0, day_b = 1, and day_c = 2.
It prints a triplet if it satisfies the conditions in the triplets function.
It then makes recursive calls with different combinations of day_a, day_b, and day_c until it exhausts all possible triplets.
The recursion depth is limited by the conditions in your if statements:

The recursion depth is limited by day_c, and it goes up to n - 1.
If day_c reaches n - 1, then day_b is incremented and day_c is reset.
If day_b reaches n - 2, then day_a is incremented and day_b and day_c are reset.
The number of recursive calls is proportional to the number of triplets, which is C(n, 3)
The complexity of code is O(n^3)
*/

int main(){
    int arr[] = {4, 15, 45, 9, 40, 27, 3, 5, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    loop(arr, 0, 1, 2, size);
}

/*
#include <stdio.h>
#include <math.h>

int isInArray(int number, int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return 1; // Number found in the array
        }
    }
    return 0; // Number not found in the array
}

void divide(int a[], int n){
    int z;
    int i;
    for (i = 0; i < n; i++){ //i cannot start from 0 because of cannot divide by 0
        for (int j = 1; j<sqrt(a[i]); j++){
            if (a[i]%j==0){
                z = a[i]/j;
                if (z != a[i] && z != j){
                    if (isInArray(z, a, n)==1 && isInArray(j, a, n)==1){
                        printf("{%d, %d, %d}\n", z, j, a[i]);
                    }
                }
                
            }
        }
    }
}


int main() {
    int a[] = {16, 4, 9, 8, 2, 100, 25, 36};
    int n = sizeof(a)/sizeof(a[0]);
    divide(a, n);
}
*/