#include<stdio.h>

/*
Pseudo-code :
  function check(int a, int b, int c)
Step 1 : if (a + b > c) && (a + c > b) && (b + c > a)
Step 2 : return 1
Step 3 : else
Step 4 : return 0

  function triangle(int arr[], int day_a, int day_b, int day_c, int n)
Step 5 : int x = arr[day_a]
         int y = arr[day_b]
         int z = arr[day_c]
Step 6 : if check(x, y, z) == 1 || check(y, z, x) == 1 || check(z, x, y) == 1
Step 7 : printf("(%d %d %d) \n", x, y, z)
Step 8 : if day_c < n - 1
Step 9 : triangle(arr, day_a, day_b, day_c + 1, n)
Step 10: else if day_b < n - 2
Step 11: triangle(arr, day_a, day_b + 1, day_b + 2, n)
Step 12: else if day_a < n - 3
Step 13: triangle(arr, day_a + 1, day_a + 2, day_a + 3, n)

  function main()
Step 14: int arr[] = {4, 6, 3, 7, 9, 5, 8, 1}
Step 14: int size = sizeof(arr) / sizeof(arr[0])
Step 14: printf("Triangles possible : \n")
Step 14: return 0;
*/

int check(int a, int b, int c){
    if((a + b > c) && (a + c > b) && (b + c > a)){  // O(1)
        return 1;
    }
    else {
        return 0;
    }
}

// The function check has time complexity always constant 
// since it has basic arithmetic operations and comparisons, 
// so complexity :  O(1)

void triangle(int arr[], int day_a, int day_b, int day_c, int n){ // n is the length of array
    int x = arr[day_a];
    int y = arr[day_b];
    int z = arr[day_c];
    if(check(x, y, z) == 1 || check(y, z, x) == 1 || check(z, x, y) == 1){
        printf("(%d %d %d) \n", x, y, z);
    }
    if(day_c < n - 1){
        triangle(arr, day_a, day_b, day_c + 1, n);
    }
    else if (day_b < n - 2){
        triangle(arr, day_a, day_b + 1, day_b + 2, n);
    }
    else if (day_a < n - 3){
        triangle(arr, day_a + 1, day_a + 2, day_a + 3, n);
    }   
}

/*
function triangle() that goes through all possible check(has complexity O(1)) that we call in the array.
It starts with an initial call with day_a = 0, day_b = 1, and day_c = 2.
It prints a check if it satisfies the conditions in the check function.
It then makes recursive calls with different combinations of day_a, day_b, and day_c until it exhausts all possible check.
The recursion depth is limited by the conditions if statements:

The recursion depth is limited by day_c, and it goes up to n - 1.
If day_c reaches n - 1, then day_b is incremented and day_c is reset.
If day_b reaches n - 2, then day_a is incremented and day_b and day_c are reset.
The number of recursive calls is proportional to the number of check, which is C(n, 3)
The complexity of code is O(n^3)
*/

int main(){
    int arr[] = {4, 6, 3, 7, 9, 5, 8, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Triangles possible : \n");
    triangle(arr, 0, 1, 2, size);
    return 0;
}
// we call the fuction triangle() once it has complexity of O((n^3))
// thus to complete the main() function, the total complexity O((n^3))
