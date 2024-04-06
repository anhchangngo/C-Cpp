#include <stdio.h>

// Using Recursion
int palindrome(char a[], int left, int right) {             
    if (left >= right){
        return 1; // A palindrome with 0 or 1 element is always true O(1)
    }
    if (a[left] == a[right]){
        return palindrome(a, left + 1, right - 1);         // T(n - 2) where T(n) is the time complexity of the recursive
    }
    else{
        return 0;                                          // O(1)
    }
}
/*
T(n) = T(n - 2) + O(1)
T(n) = T(n - 4) + O(1) + O(1)
.....
The recurrence relation continues until the base case is reached when left >= right
We find that it takes n/2 recursive to reach the base case, as each recursive  reduces the size of the array by 2
-> Complexity = O(n/2) = O(n)
*/

// Display array to see if it is Palindrome
void displayPalindrome(char a[], int size) {
    if (palindrome(a, 0, size - 1)) {   // O(n)
        printf("The array is a palindrome\n");   // O(1)
    } else {
        printf("The array is not a palindrome\n");   // O(1)
    }
}

int main() {
    char a1[] = {1, 2, 3, 2, 1}; // O(1)
    char a2[] = {1, 2, 3, 6};    // O(1)
    char a3[] = {'a', 'b', 'c', 'c', 'b', 'a'}; // O(1)

    displayPalindrome(a1, sizeof(a1) / sizeof(a1[0])); // O(n)
    displayPalindrome(a2, sizeof(a2) / sizeof(a2[0])); // O(n)
    displayPalindrome(a3, sizeof(a3) / sizeof(a3[0])); // O(n)

    return 0; // O(1)
}
/*
-> Complexity = O(1) + O(1) + O(1) + O(n) + O(n) + O(n) + O(1)
              = O(n)
*/