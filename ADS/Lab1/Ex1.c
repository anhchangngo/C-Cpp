//Exercise 1:
//  Write a pseudocode and implement a program in C to swap the first and last digits
//  of a positive integer.

#include <stdio.h>
 int main () {
     int n;
     printf("Input the value of n : ");
    scanf("%d", &n);
     int m = n % 10; // Last number of n
     int p = 0; // accumulate and store the intermediate digits of n
     // x manages the position of digits when reassembling the number after swapping
     int x = 10;  // It needs to be a power of 10 to position the digits correctly.
if(n < 9){
        printf("INVALID");  // 1-digit numbers and negative numbers are eliminated
    }
    else {
    n = n / 10; // separate the last digit
    while (n / 10 != 0) {  // so that n has more than 1 digit
         p += (n % 10) * x;  // last digit of n times x
         x *= 10;  // x is then multiplied by 10 in preparation for the next digit
        n = n / 10;  // separate the last digit and isolates the next digit
     }
    m = m  * x + p + n;
    printf("Swap the first and last digits of a positive integer : %d\n", m);
    }
     return 0;
 }

// Pseudocode
// Step 1 : Declare an integer variable n
// Step 2 : Given that the last number is m = n % 10
// Step 3 : Declare an integer variable p and initialize it to 0
// Step 4 : Declare an integer variable x and initialize it to 10
// Step 5 : If n > 9 then go to Step 6
// Step 6 : Divide n to 10
// Step 7 : While n is greater than 0:
// Step 8 : Set p to (n % 10) * x + p
// Step 9 : Multiply x by 10
// Step 10 : Set n to n / 10
// Step 11 : Set m to m * x + p + n
// Step 12 : Display m (The result)