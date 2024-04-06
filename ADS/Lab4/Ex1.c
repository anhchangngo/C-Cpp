#include<stdio.h>

// Using Recursion
/* Pseudo-code :
   function int digit_sum1(int n):      
   Step 1.   i = n % 10                      |  O(1)
   Step 2.   if n == 0                       |  O(1)
   Step 3.      return 0                     |  O(1)
   Step 4.   else                            |
   Step 5.    return  i + digit_sum1(n/10)   | O(log(n))

   Complexity : O(1 + 1 + 1 + log(n)) = log(n)
*/
int digit_sum1(int n){
    int i = n % 10;  // i is remainder of n divided by 10
    if(n == 0){
        return 0;
    }
    else
        return i + digit_sum1(n/10);  // add the last digit to the sum of the remaining digits
}

// Using Iteration
/* Pseudo-code :
   function int digit_sum2(int n):
   Step 1.    sum = 0             |  O(1)
   Step 2.    while n != 0        |  O(log(n))
   Step 3.      i = n % 10        |  O(1)
   Step 4.      sum = sum + i     |  O(1)
   Step 5.      n /= 10           |  O(1)
   Step 6.    end while           |
   Step 7.    return sum          |  O(1)

   Complexity : O(1 + (log(n) * 1 * 1 * 1) + 1) = O(log(n))
*/
int digit_sum2(int n){
    int sum = 0;
    while(n != 0){
        int i = n % 10;  // i is remainder of n divided by 10
        sum = sum + i;
        n /= 10;  // remove the last digit from n
    }
    return sum;
}

int main(){
    int sum1 = digit_sum1(103509);  // O(log(n))
    printf("Using Recursion the digit sum of 103509 is : %d \n", sum1);
    int sum2 = digit_sum2(9512);   // O(log10(n))
    printf("Using Iteration the digit sum of 9512 is : %d ", sum2);
    return 0;
}
// -> Complexity : O(log(n)) + O(log(n)) = O(log(n))