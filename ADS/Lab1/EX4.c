#include <stdio.h>
#include <math.h>

// Checks whether an integer n is prime or not
int prime(int n) {
    for(int i = 2; i <= sqrt(n); i++){  // O(sqrt(n))
      if(n % i == 0) return 0;  // n is not a prime number // O(1)
    }
    return 1; // n is a prime number
}
// complexity = O(sqrt(n))

// Checks whether an integer is a Sphenic number
int sphenic(int i) {
    int count = 0;  // The number of prime factors of n // O(1)
    int prime_factors[100];  // Stores 100 prime divisors of n // O(1)
    for (int j = 2; j <= i; j++) {  // O(n)
        if (i % j == 0 && prime(j)) {  // O(1) + O(sqrt(n)) because complexity of prime(int n) = O(sqrt(n))
            prime_factors[count++] = j;  // j satisfies the condition of being a prime divisor of n
        }
    }
    if (count == 3) { // because a sphenic number is a product of 3 numbers  // O(1)
        int p = prime_factors[0];
        int q = prime_factors[1];
        int r = prime_factors[2];
        if (p * q * r == i) {    // p, q, and r are three distinct prime numbers // O(1)
             printf("%d is a sphenic number because %d = %d * %d * %d\n", i, i, p, q, r);
            return 1;
        }
    }
  printf("%d is not a sphenic number.\n", i);
    return 0;
}
// complexity = O(1) + O(1) + O(n) * (O(1) + O(sqrt(n))) + O(1) + O(1) = O(n*sqrt(n))

int main() {
    int n;  //O(1)
    printf("Enter a natural number n: ");
    scanf("%d", &n);

    sphenic(n); // O(n*sqrt(n))

    return 0;
}
// complexity = O(1) + O(n * sqrt(n)= O(n * sqrt(n))

// Pseudocode
// Step 1: Read n from the user
// Step 2: Print "Enter a natural number n: "
// Step 3: Initialize count to 0
// Step 4: Initialize an array prime_factors with size 100
// Step 5: For i from 2 to n, do the following:
// Step 6: If i is divisible by 2 and i is not equal to 2, continue to the next iteration
// Step 7: Initialize prime to true
// Step 8: For j from 2 to the square root of i, do the following:
// Step 9: If i is divisible by j, set prime to false and break the loop
// Step 10: If prime is true, then:
// Step 11: Add i to prime_factors[count] and increment count by 1
// Step 12: If count is equal to 3, then:
// Step 13: Assign the first three elements of prime_factors to p, q, r respectively
// Step 14: If p * q * r is equal to i, then:
// Step 15: Print i, p, q, and r in the format "i = p * q * r"
// Step 16: End
