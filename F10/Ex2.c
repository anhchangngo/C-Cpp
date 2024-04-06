/*
In this context, we try to find co-prime numbers using at least a recursive function.
 Implement the recursive function (2 pts).
 Write a program to solve the above Problem using the recursive function (4 pts)
*/

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else 
    return gcd(b, a % b);
}

void co_prime(int arr[], int day_a, int day_b, int n){
    int a = arr[day_a];
    int b = arr[day_b];
     if(gcd(a, b) == 1 || gcd(b, a) == 1){
        printf("(%d %d) \n", a, b);
     }
    if (day_b < n - 1) {
        co_prime(arr, day_a, day_b + 1,n);
    } else if (day_a < n - 2) {
        co_prime(arr, day_a + 1, day_a + 2, n);
}
}

int main(){       
    int arr[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    co_prime(arr, 0, 1, size);
    return 0;
}


/*
code chat 
#include <stdio.h>

// Recursive function to calculate the GCD of two numbers
int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return findGCD(b, a % b);
    }
}

// Recursive function to find and print co-prime pairs in the array
void findCoPrimes(int arr[], int start, int end) {
    // Base case: no more pairs to check
    if (start >= end) {
        return;
    }

    int num1 = arr[start];

    // Iterate through the remaining elements
    for (int i = start + 1; i <= end; i++) {
        int num2 = arr[i];

        // Check if the GCD of the pair is 1 (they are co-prime)
        if (findGCD(num1, num2) == 1) {
            printf("(%d, %d), ", num1, num2);
        }
    }

    // Recursively call the function for the next element in the array
    findCoPrimes(arr, start + 1, end);
}

int main() {
    int arr[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the recursive function to find and print co-prime pairs
    findCoPrimes(arr, 0, n - 1);

    return 0;
}

*/