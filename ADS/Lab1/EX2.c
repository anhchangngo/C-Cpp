// Exercise 2:
// Complete this given function void findMax(int *max, int a), which assigns a value a to max if a > max.

#include <stdio.h>
#include <math.h>

void findMAX(int *max, int a){  // int *max : receives a pointer to an integer variable, where the maximum value will be stored
    if(a > *max){  //O(1)
    *max = a;  // // Update max if a is greater
}
}

int main() {
    int a = 20;
    int max = 10;
    findMAX(&max, a);  // passing a pointer to the max variable and the value of a
    printf("The maximum number : %d", max);
    return 0;
}