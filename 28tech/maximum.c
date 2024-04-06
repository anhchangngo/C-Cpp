#include <stdio.h>

int main() {
     
   int a[]= {1, 3 , 6,  5, 9 , 8};
   int n = sizeof(a) / sizeof(a[0]); // The number of elements in array a
   int i = 2;
   int max = a[1];
   while(i < n){
     if(a[i] > max){
        max = a[i];
     }
     else 
     i = i + 1;
   }
   printf("The maximum of array a is : %d\n", max);
   return 0;
}

// Step 1: Given that Max = a1 and the index i = 2,
// Step2: If i > n then go to Step 6
// Step3: If ai > Max then Max = ai
// Step 4: Increment index i
// Step 5: Go to Step2
// Step 6: Return Max