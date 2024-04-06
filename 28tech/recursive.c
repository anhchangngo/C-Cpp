#include <stdio.h>
    int fibo(int n){
      if (n == 1){
        return 0;
      }
      else if (n == 2 || n == 3){
        return 1;
      }
      else{
      return fibo(n - 1) + fibo(n - 2);
    }
    }

    int f(int n)
{
    // Stop condition
    if (n == 0 || n == 1)
        return 1;
 
    // Recursive condition
    else
        return n * f(n - 1);
}

    int main() {
        int n;
        printf("Input the value of n :");
        scanf("%d", &n);
        printf("The value of fibonacci(%d) is ", n);
        for(int i = 1; i <= n; i++){
        printf("%d ", fibo(i));
        }
        printf("\n");
        printf("factorial of %d is: %d", n, f(n));
        return 0;
        }