#include <stdio.h>
#include <math.h>

/* cách trâu bò
int prime(int n){
    if (n <= 1){
        return 0;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;  // n is not prime
    }
    return 1;
}

int primeFactorization(int n){
    if (n <= 1){
        return 0;
    }
    for(int i = 2; i <= n; i++){
        if(n % i == 0 && prime(i) == 1){
            printf("%d ", i);
            return primeFactorization(n / i);
        }
}
return 1;
}
*/

// cách thông minh (iteration)
void pt(int n){
    for(int i = 2; i <= sqrt(n); i ++){
        while(n % i == 0){
            printf("%d * ", i);
            n /= i;
        }
    }
    if(n != 1)
    printf("%d ", n);
}

/*
void pt1(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){ 
            int cnt = 0;
            while(n % i == 0){
                ++cnt;
                n /= i;
            }
            printf("%d^%d", i, cnt);
            if(n != 1) printf("*");
        }
    }
    if(n != 1)
    printf("%d^1", n);
}
*/

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d = ", a);
    pt(a);
    printf("\n");
    printf("%d = ", b);
    pt(b);

    return 0;
}

/*
chat 
#include <stdio.h>

void primeFactorization(int n, int divisor) {
    if (n <= 1) {
        return;
    }

    if (n % divisor == 0) {
        printf("%d ", divisor);
        primeFactorization(n / divisor, divisor);
    } else {
        primeFactorization(n, divisor + 1);
    }
}

int main() {
    int num;

    // Input the number from the user
    printf("Enter a natural number: ");
    scanf("%d", &num);

    // Check if the number is valid
    if (num <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Perform prime factorization
    printf("Prime factorization of %d: ", num);
    primeFactorization(num, 2);  // Start with the smallest prime factor

    printf("\n");

    return 0;
}

pseudo-code
fuction primeFactorization(int n, int divisor)
Step 1 : if n <= 1
Step 2 : return
Step 3 : if n % divisor == 0
Step 4 : print divisor
Step 5 : primeFactorization(n / divisor, divisor)
Step 6 : else
Step 7 : primeFactorization(n, divisor + 1)

function main()
Step 8 : input num
Step 9 : if num <= 0
Step 10: print Please enter a positive integer
Step 11: return 1
Step 12: print num
Step 13: primeFactorization(num, 2)
Step 14: return 0

The best-case scenario is O(1) because the algorithm terminates quickly when the input is 1.
The average-case time complexity is O(log n) because, on average, the algorithm divides the input by its smallest prime factor until it reaches 1.
The worst-case time complexity is O(sqrt(n)) because the algorithm checks divisibility up to the square root of the input number in the worst case.

*/