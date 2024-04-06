#include <stdio.h>
#include <math.h>

int countOdd(int n){
    int last_digits = n % 10;
    int count = 0;
    if(n == 0){
        return 0;
    }
    if(last_digits % 2 != 0){
        count ++;
    }
        return count + countOdd(n / 10);;
}

int countEven(int n){
    int last_digits = n % 10;
    int count = 0;
    if(n == 0){
        return 0;
    }
    if(last_digits % 2 == 0){
        count ++;
    }
        return count + countEven(n / 10);
}

int main(){
    int n = 3450;
    printf("%d ",countOdd(n));
    printf("%d ",countEven(n));
    return 0;
}

/*
Best Case:

* The best case scenario is when all digits in the input number are odd. 
In this case, the function `countOdd` will not have to make any recursive calls, since it will reach the 
base case where `n == 0`. Therefore, the time complexity of the best case is O(1).
* Similarly, in the worst case scenario, all digits in the input number are even, 
and the function `countEven` will also not have to make any recursive calls. Therefore, the time 
complexity of the best case is O(1).

Average Case:

* The average case scenario is when the number of odd digits in the input number 
is approximately equal to the number of even digits. In this case, the function `countOdd` will 
have to make approximately the same number of recursive calls as the function `countEven`, 
since it will also have to count the number of odd digits. Therefore, the time complexity
of the average case is O(log n), where n is the input number.
* The time complexity of the average case for `countEven` is also O(log n), 
since it will also have to count the number of even digits in the input number.

Worst Case:

* In the worst case scenario, all digits in the input number are odd, 
and the function `countOdd` will make a recursive call for each digit in the input number. Therefore, the time
complexity of the worst case is O(n), where n is the number of digits in the input number.
* Similarly, in the worst case scenario, all digits in the input number are even, 
and the function `countEven` will also make a recursive call for each digit in the input number. 
Therefore, the time complexity of the worst case is O(n), where n is the number of digits in the input number.

In conclusion, the best case, average case, and worst case time complexities of the given program are all O(1) because the functions `countOdd` and `countEven` do not make any 
recursive calls when the input number is 0 or when it has only one digit. The average case time complexity is O(log n), where n is the input number, and the worst case time 
complexity is O(n), where n is the number of digits in the input number.
*/