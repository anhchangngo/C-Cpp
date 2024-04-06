#include <stdio.h>
#include <math.h>

int isCenteredCube(int x, int i){ // x is the number to compare
    // O(log(n))
    // we need k operations such as (i + k)^3 + k^3 > n
    // k = log(3n) = log(n)
    int cube = pow(i, 3) + pow(i + 1, 3);
    if(cube == x){
        return 1;
    } 
    else if(cube < x){
        return isCenteredCube(x, i + 1);
    }
    else{
        return 0;
    }
}

void check(int a[], int n){
    for(int i = 0; i < n; i ++){
        // we have a loop from 0 to n-1 => we need n operations
        // to check all n elements in a given array
        // in each iterations, we call the function isCenteredCube() once
        // it has complexity of O(log(n))
        // thus to complete the check() function, the total complexity O(nlog(n))
        if(isCenteredCube(a[i], 1) == 1){
            printf("%d is Centered Cube \n", a[i]);
        }
    }
}

int main(){
    int a[10] = {9, 20, 87, 192, 54, 45, 91, 34, 4, 35};
    int size = sizeof(a) / sizeof(a[0]);
    check(a, size);
    return 0;
}

/*
Pseudo-code 
   function isCenteredCube(int x, int i)
   Step 1 : cube = pow(i, 3) + pow(i + 1, 3)
   Step 2 : if cube == x
   Step 3 : return 1
   Step 4 : else if cube < x
   Step 5 : return isCenteredCube(x, i + 1)
   Step 6 : else
   Step 7 : return 0

   function check(int a[], int n)
   Step 8 : for(int i = 0; i < n; i ++)
   Step 9 : if isCenteredCube(a[i], 1) == 1
   Step 10: print "a[i] is Centered Cube"
   Step 11: end for

   function main()
   Step 12: int a[10] = {9, 20, 87, 192, 54, 45, 91, 34, 4, 35}
   Step 13: int size = sizeof(a) / sizeof(a[0])
   Step 14: check(a, size)
   Step 15: return 0

*/