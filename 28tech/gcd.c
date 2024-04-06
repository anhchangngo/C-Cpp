#include <stdio.h>
#include <math.h>

int gcd1(int a, int b){
    if(b == 0){
        return a;
    }
    else 
    return gcd1(b, a % b);
}

// bội chung nhỏ nhất
int lcm(int a, int b){
    return a / gcd1(a, b) * b;
}

// ước nguyên tô lớn nhất
int solve(int n){
    int res = 0;
    for(int i = 2; i <= sqrt(n); i++){
        while(n % i == 0){
            res = i;
            n /= i;
        }
    }
    if(n != 1){
        res = n;
    }
        return res;
}

// ước nguyên tố nhỏ nhất của n
int find(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return i;
        }
    }
    return n;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    printf("gcd : %d \n",gcd1(a, b));

    printf("lcm : %d \n", lcm(a, b));

    printf("uoc so nguyen to lon nhat %d : %d \n", a, solve(a));
    printf("uoc so nguyen to be nhat %d : %d \n", b, find(b));
    return 0;
}