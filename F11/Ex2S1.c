/*
We would like to improve the factorization by using Divide and Conquer strategy and Binary recursion:
Step 1: Given a natural number N;
Step 2: Find two biggest divisors of N denoted by d1, d2;
Step 3: If a divisor d1 or d2 is not a prime, then call step 1 for d1 or d2, respectively; else
continue;
Step 4: If d1 and d2 are both prime then exit;
*/

#include <stdio.h>

void printFactor(int factor, int isLast) {
    printf("%d", factor);
    if (!isLast) {
        printf(" * ");
    }
}

void primeFactorization(int n) {
    if (n <= 1) {
        return;
    }

    int divisor = 2;
    while (divisor * divisor <= n) {
        if (n % divisor == 0) {
            printFactor(divisor, 0);
            primeFactorization(n / divisor);
            return;
        }
        divisor++;
    }

    // If n is a prime number greater than 1
    printFactor(n, 1);
}

int main() {
    int n;

    // Input from the user
    printf("Enter a natural number N: ");
    scanf("%d", &n);

    // Check if the input is valid
    if (n < 2) {
        printf("Prime factorization is not possible for numbers less than 2.\n");
    } else {
        printf("Prime factorization of %d: ", n);
        primeFactorization(n);
        printf("\n");
    }

    return 0;
}

/*
The while loop iterates until the square of the divisor exceeds 'n', which is approximately √n.
The recursive calls depend on the prime factorization of 'n', and in the worst case (prime number), it is logarithmic (log n).
Therefore, the overall time complexity is O(√n * log n).
*/