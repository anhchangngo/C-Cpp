/*
Given an array of 10 elements: 2, 10, 27, 13, 90, 45, 5, 26, 49, 50.
In this problem, we try to find all co-prime numbers. Two integer numbers are co-prime if the
greatest common divisor of these two is 1.
The list of co-prime numbers from the above array is: {(2, 27), (2,13), (2,45), (2,5), (2,49), (10,
27), (10, 13), (10,49), (27,13), (27,5), (27,26), (27,50), (13,90), (13,45), (13,5), (13,49), (13,50),
(90,49), (90,49), (45,26), (45,49), (5,26), (5,49), (26,49), (49,50)}
*/

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else 
    return gcd(b, a % b);
}

void co_prime(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j ++){
            if(gcd(arr[i], arr[j]) == 1){
                printf("(%d, %d) \n", arr[i], arr[j]);
            }
        }
    }
}

int main(){       
    int arr[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    co_prime(arr, size);
    return 0;
}

// Calculate the complexity of your program (Best scenario, Worst scenario, Average). Justify your answer.
/*
Best Case: O(n) when all elements are co prime.
Worst Case: O(n^2) when the GCD computation is performed for each pair of elements.
Average Case: Between O(n) and O(n^2) depending on the distribution of co prime and non-co prime pairs.
*/