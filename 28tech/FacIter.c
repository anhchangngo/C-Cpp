#include<stdio.h>

// Factorial
// Iteration
int fac1(int n){
    int fac = 1;
    for(int i = 1; i <= n; i++){
        fac = fac * i;
    }
    return fac;
}

// Recursion
int fac2(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * fac2(n - 1);
    }
}

// A function is indirectly recursive if it calls its invoker and eventually results in the original call.
int multi(int n);
int fac3(int n){
    if(n == 0){
        return 1;
    }
    else{
        return multi(n);
    }
}

int multi(int n){
    return n * fac3(n -1);
}

// GCD
// Iteration
int gcd1(int a, int b){
    int tmp;
    while(b != 0){
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

// Recursion
int gcd2(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        a = a % b;  
    }
    return gcd2(b,a);
}

// Find max with multiple recursive calls
int max(int arr[], int first, int last){
    if(first == last){
        return arr[first];
    }
    int mid = first + (last - first) / 2;
    int a = max(arr, first, mid);
    int b = max(arr, mid + 1, last);
    if(a < b){
        return b;
    }
    else{
        return a;
    }
}

int main(){
    int ucln1 = gcd1(40,17);
    printf("%d \n", ucln1);
    int ucln2 = gcd2(300,30);
    printf("%d \n", ucln2);
    int gt1 = fac1(5);
    printf("%d \n", gt1);
    int gt2 = fac2(1);
    printf("%d \n", gt2);
    int gt3 = fac3(5);
    printf("%d \n", gt3);
    int a[] = {1, 2, 54, 7, 2, 9, 0};
    int size = sizeof(a) / sizeof(a[0]) - 1;
    int lon = max(a, 0, size);
    printf("%d\n", lon);
    return 0;
}