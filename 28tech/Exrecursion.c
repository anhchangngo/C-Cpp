#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/* dãy ngược thuận giống nhau  : 3 2 1 1 2 3
void in(int n){
    if(n < 1){
        return;
    }
    else {
        printf("%d ", n);
        in(n - 1);
        printf("%d ", n);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    in(n);
}
*/

/*
Input: 
set[] = {'a', 'b'}, k = 3

Output:
aaa
aab
aba
abb
baa
bab
bba
bbb

void printCombinations(char set[], int n, int k, char prefix[], int prefixLength) {
    if (k == 0) {
        for (int i = 0; i < prefixLength; i++) {
            printf("%c", prefix[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        prefix[prefixLength] = set[i];
        printCombinations(set, n, k - 1, prefix, prefixLength + 1);
    }
}

int main() {
    char set[] = {'a', 'b'};
    int n = sizeof(set) / sizeof(set[0]);
    int k = 3;

    char prefix[k];  // Array to store the current combination
    printCombinations(set, n, k, prefix, 0);

    return 0;
}
*/

/*
n, n-5, n-10, …, 0, 5, 10, …, n-5, n

void printPattern(int n, int m, bool flag) 
{ 
    printf("%d", m);
  
    // If we are moving back toward the n and 
    // we have reached there, then we are done 
    if (flag == false && n == m) 
        return; 
  
    // If we are moving toward 0 or negative. 
    if (flag) { 
        // If m is greater, than 5, recur with true flag 
        if (m - 5 > 0) 
            printPattern(n, m - 5, true); 
        else // recur with false flag 
            printPattern(n, m - 5, false); 
    } 
    else // If flag is false. 
        printPattern(n, m + 5, false); 
} 
  
// Recursive function to print the pattern 
// variance where m is the input int32 value 
void PrintPattern(int m) 
{ 
    if (m > 0) { 
        printf("%d\n", m);
        PrintPattern(m - 5); 
    } 
  
    printf("%d\n", m);
} 
  
// Driver code 
int main() 
{ 
    int n = 16; 
      
      // Function call 
    PrintPattern(n); 
    return 0; 
}
*/

/*
Input: x = 3
Output: 1 1 1
        2 1
        3

int plus(int n){
    if(n == 0){
        return 0;
    }
        return n % 10 + plus(n / 10);
}

int main(){
    int n = 3450;
    int cnt = plus(n);
    printf("%d ", cnt);
    return 0;
}
*/

/*
Input : 3
Output : 6
Explanation : 1 + 2 + 3 = 6

int plus(int n){
    if(n == 0){
    return 0;
    }
    return n + plus(n - 1);
}

int main(){
    int n = 5;
    int sum = plus(n);
    printf("%d ", sum);
}
*/

/* check prime 
bool isPrime(int n, int i);

// Default parameter for i
bool isPrimeDefault(int n) {
    return isPrime(n, 2);
}

bool isPrime(int n, int i) {
    // Base cases
    if (n <= 1) {
        return false;
    }
    if (i * i > n) {
        return true;
    }
    if (n % i == 0) {
        return false;
    }

    // Check for next divisor
    return isPrime(n, i + 1);
}

// Driver Program
int main() {
    int n = 15;
    if (isPrimeDefault(n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
*/

/*
#include <stdio.h>

// Function to calculate and return the power of any given number
int power(int num, unsigned int n) {
    if (n == 0)
        return 1;
    int temp = power(num, n / 2);
    if (n % 2 == 0)
        return temp * temp;
    else
        return num * temp * temp;
}

// Function to check power representations recursively
int checkRecursive(int x, int n, int curr_num, int curr_sum) {
    // Initialize the number of ways to express x as n-th powers
    int results = 0;

    // Calculate the power of curr_num raised to n
    int p = power(curr_num, n);

    // Iterate while the sum is less than x
    while (p + curr_sum < x) {
        // Recursively check the next number
        results += checkRecursive(x, n, curr_num + 1, p + curr_sum);
        curr_num++;
        p = power(curr_num, n);
    }

    // If the sum of powers is equal to x, increase the result
    if (p + curr_sum == x)
        results++;

    // Return the final result
    return results;
}

// Driver Code
int main() {
    int x = 10, n = 2;
    printf("%d\n", checkRecursive(x, n, 1, 0));
    return 0;
}
*/

/*
#include <stdio.h>

void printRec(char *number, int extraOnes, int remainingPlaces) {
    if (remainingPlaces == 0) {
        printf("%s ", number);
        return;
    }

    char number1[10]; // Assuming a maximum length of 10 for the number
    snprintf(number1, sizeof(number1), "%s1", number);
    printRec(number1, extraOnes + 1, remainingPlaces - 1);


    if (extraOnes > 0) {
        char number0[10]; // Assuming a maximum length of 10 for the number
        snprintf(number0, sizeof(number0), "%s0", number);
        printRec(number0, extraOnes - 1, remainingPlaces - 1);
    }
}

void printNums(int n) {
    char str[10]; // Assuming a maximum length of 10 for the number
    str[0] = '\0';
    printRec(str, 0, n);
}

// Driver code
int main() {
    int n = 4;

    // Function call
    printNums(n);
    return 0;
}

*/

