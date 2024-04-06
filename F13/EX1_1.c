// (3n^2 - n) / 2

#include <stdio.h>
#include <math.h>

int pentagonal(int x, int n){
    int pen = (3 * pow(n, 2) - n) / 2;
    if(pen == x){
        return 1;
    }
    else if (pen < x){
        return pentagonal(x, n + 1);
    }
    else {
        return 0;
    }
}

void check(int a[], int n){
    for(int i = 0; i < n; i ++){
        if(pentagonal(a[i], 1) == 1){
            printf("%d ", a[i]);
        }
    }
}


int main(){
    int a[7] = {1, 86, 4, 5, 10, 27, 12};
    int size = sizeof(a) / sizeof(a[0]);
    check(a, size);
    return 0;
}
