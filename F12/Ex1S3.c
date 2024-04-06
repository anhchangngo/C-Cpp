/*
In this context, we would like to find all twin primes from a given array of naturals. 
A twin prime is a prime number that is either 2 less or 2 more than another prime number (p, p+2) or (p+2, p).
For example, an array is given {3, 101, 96, 47, 41, 7, 65, 9, 13, 5, 79, 45, 30, 11, 43). 
The list of twin primes is {3, 5), (7, 5), {13, 11), {41, 43}.
*/

#include <stdio.h>
#include <math.h>

int prime(int n){
    if(n <= 1){
        return 0;
    }
    for(int i = 2; i <= sqrt(n); i ++){
        if(n % i == 0) return 0;
    }
    return 1;
}
// O(log n)
// We need sqrt(n) operations

int twin_primes(int a, int b){
    if(((a == b + 2) || (b == a + 2)) && prime(a) && prime(b)){
        return 1;
    }
    else{
    return 0;
    }
}
// O(1)
// it only performs a few arithmetic and logical operations.


void loop(int arr[], int day_a, int day_b, int n){
    int a = arr[day_a];
    int b = arr[day_b];
    if(twin_primes(a, b) == 1 || twin_primes(b, a) == 1){
        printf("(%d %d) \n", a, b);
    }
    if(day_b < n - 1){
        loop(arr, day_a, day_b + 1, n);
    }
    else if (day_a < n - 2){
        loop(arr, day_a + 1, day_a + 2, n);
    }
}
// O(n^2)
// The recursion depth is at most n/2 because day_a and day_b move forward alternately.
// For each recursive call, the twin_primes function is called, which has a constant time complexity.
// Therefore, the overall time complexity of the loop function is O(n) for each recursive call
// and i call 2 loop fuction


int main(){
    int arr[] = {3, 101, 96, 47, 41, 7, 65, 9, 13, 5, 79, 45, 30, 11, 43};
    int size = sizeof(arr) / sizeof(arr[0]);
    loop(arr, 0, 1, size);
}