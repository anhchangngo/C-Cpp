#include <stdio.h>
#include <math.h>

int isPrime(num) {
 if (num <= 1)
 return 0;
 for (int i = 2; i <= sqrt(num); i++) {
 if (num % i == 0)
 return 0;
 }
 return 1;
}

int main() {
 int arr[] = {4, 15, 28, 40, 9, 53, 41, 8, 17, 3, 5};
 int n = sizeof(arr) / sizeof(arr[0]);
 for (int i = 0; i < n; i++) {
 int a = arr[i], b = arr[i >> 1], c = arr[i >> 2];
 if ((a * a + b * b == c * c) && isPrime(a) && isPrime(b) && isPrime(c)) {
 printf("Hello %d, %d %d\n", a, b, c);
 }
 }
 return 0;
}

#include <stdio.h>

// Function to find all co-prime numbers in an array
void findCoPrime(int arr[], int n) {
    // Base case: if the array has only one element, return it as co-prime
    if (n == 1) {
        printf("%d ", arr[0]);
        return;
    }

    // Recursive case: find all co-prime numbers in the subarray
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (gcd(arr[i], arr[j]) == 1) {
                printf("%d %d ", arr[i], arr[j]);
            }
        }
    }
}

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    // Test array: 2, 10, 27, 13, 90, 45, 5, 26, 49, 50
    int arr[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function to find all co-prime numbers in the array
    findCoPrime(arr, n);

    return 0;
}
