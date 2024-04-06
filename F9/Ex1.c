#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool PrimeNum (int n) {
    if (n<=1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n%i == 0) {
            return false;
        } 
    }
    return true;
}
// O(log n)

bool findSphenic(int num, int count) {
    if (num == 1 && count == 3) {
        return true;
    } 
    if (count > 3 || num == 1) {
        return false;
    }
    for (int j = 1; j <= num; j++) {
        if (num % j == 0 && PrimeNum(j)) {
            if ((num/j) % j == 0) return false;  // neu co 2 so nguyen to trung nhau loai
            if (findSphenic(num / j, count + 1)) {  // num chia cho so nguyen to va count tang them 1 don vi de xet gia tri khac
                return true;
            }
        }
    }
    return false;
}

void display (int n) {
    for (int k = 1; k<=n; k++) {
        if (findSphenic(k, 0)) {
            printf("%d\n", k);
        }
    }
}

int main() {
    int num;
    printf("Type in a number: ");
    scanf("%d", &num);
    display(num);
    return 0;
}

/*
The complexity of the given program can be analyzed as follows:

PrimeNum Function

Best Case: O(1) - If the input number is less than or equal to 1, the function returns 'false' immediately.
Worst Case: O(√n) - If the input number is a prime number, the loop will run up to √n times to check for divisibility.
Average Case: O(√n) - The loop will run approximately √n/2 times on average for prime numbers.
findSphenic Function

Best Case: O(1) - If the input number is 1 and the count is 3, the function returns 'true' immediately.
Worst Case: O(n√n) - The loop runs up to n times, and in each iteration, PrimeNum function is called, which has a complexity of O(√n).
Average Case: O(n√n) - The performance is dependent on the input 'num', and it involves checking prime numbers and their divisors.
display Function

Best Case: O(n) - If none of the numbers from 1 to n are sphenic, the function iterates through the loop once for each number.
Worst Case: O(n * n√n) - Calls to findSphenic function for each number from 1 to n, with a complexity of O(n√n) for each call.
Average Case: O(n * n√n) - It involves multiple calls to findSphenic function with varying input numbers.
Therefore, the overall complexity of the main program can be considered as follows:

Best Case: O(n)
Worst Case: O(n * n√n)
Average Case: O(n * n√n)
*/