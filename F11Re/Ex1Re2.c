// Pass-by-Reference 

#include <stdio.h>

void Count(int *n){
    int count_odd = 0;
    int count_even = 0;

    while(*n > 0){
    int last_digits = *n % 10;
    if(last_digits % 2 != 0){  // count odd number
       count_odd ++;
    }

    if(last_digits % 2 == 0){  // count even number 
        count_even ++;
    }
       *n /= 10;
    }
    
    printf("%d \n", count_odd);
    printf("%d ", count_even);
}

int main(){
    int n = 3450;
    Count(&n);
    return 0;
}

/*
Best Case:

* The best case scenario is when all digits in the input number are odd. 
In this case, the function `Count` will not have to make any recursive calls, since it will reach the base 
case where `n == 0`. Therefore, the time complexity of the best case is O(1).
* Similarly, in the worst case scenario, all digits in the input number are even, 
and the function `Count` will also not have to make any recursive calls. Therefore, the time 
complexity of the best case is O(1).

Average Case:

* The average case scenario is when the number of odd digits in the input number is approximately equal to the number of even digits. 
In this case, the function `Count` will have to make approximately the same number of recursive calls as the function `Count`, 
since it will also have to count the number of odd digits. Therefore, the time complexity of the 
average case is O(log n), where n is the input number.
* The time complexity of the average case for `Count` is also O(log n), since it will also have to count the number of even digits in the input number.

Worst Case:

* In the worst case scenario, all digits in the input number are odd, and the function `Count` will make a recursive call 
for each digit in the input number. Therefore, the time complexity of the worst case is O(n), 
where n is the number of digits in the input number.
* Similarly, in the worst case scenario, all digits in the input number are even, and the function `Count` will also make a recursive call 
for each digit in the input number. Therefore, the time complexity of the worst case is O(n), 
where n is the number of digits in the input number.

In conclusion, the best case, average case, and worst case time complexities of the given program are all O(1) because the function `Count` does not make any recursive calls when 
the input number is 0 or when it has only one digit. The average case time complexity is O(log n), where n is the input number, and the worst case time complexity is O(n), where n 
is the number of digits in the input number.

It's worth noting that using pass-by-reference can be more efficient in certain scenarios, as it eliminates the need for copying the entire input number to a new variable, which 
can reduce the amount of memory allocated and copied during the program's execution. However, in this case, using pass-by-value is still more appropriate because the function 
`Count` only needs to read the input number, and not modify it.
*/