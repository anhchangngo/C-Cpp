#include <stdio.h>
#include <math.h>

/*
Given an array of 10 elements: 4, 15, 28, 45, 40, 9, 53, 41, 8, 17, 3, 5
find all Pythagorean triplets that consist of 3 integer numbers (a, b, c) 
     a^2 + b^2 = c^2
*/

int Pythagorean(int a, int b, int c) {
    if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
        return 1;
    } else {
        return 0;
    }
}

void loop(int arr[], int day_a, int day_b, int day_c, int n) {
    int a = arr[day_a];
    int b = arr[day_b];
    int c = arr[day_c];
    if (Pythagorean(a, b, c) == 1 || Pythagorean(a, c, b) == 1 || Pythagorean(c, b, a) == 1) {
        printf("%d^2 + %d^2 = %d^2 \n", a, b, c);
    }
    if (day_c < n - 1) {
        loop(arr, day_a, day_b, day_c + 1, n);
    } else if (day_b < n - 2) {
        loop(arr, day_a, day_b + 1, day_b + 2, n);
    } else if (day_a < n - 3) {
        loop(arr, day_a + 1, day_a + 2, day_a + 3, n);
    }
}
// O(n^3)

int main() {
    int arr[] = {4, 15, 28, 45, 40, 9, 53, 41, 8, 17, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    loop(arr, 0, 1, 2, size);  // Start indices for a, b, and c
    return 0;
}
