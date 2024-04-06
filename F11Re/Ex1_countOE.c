// function countAndPrintOddEvenDigits(N, oddCount, evenCount)
//     oddCount = 0
//     evenCount = 0

//     originalNumber = N  // Store the original value

//     print "Odd digits: "
//     while N > 0
//         digit = N % 10
//         if digit % 2 == 1
//             print digit, " "
//             oddCount++
//         N = N / 10

//     print "\nCount of odd digits: ", oddCount

//     N = originalNumber  // Restore the original value

//     print "Even digits: "
//     while N > 0
//         digit = N % 10
//         if digit % 2 == 0
//             print digit, " "
//             evenCount++
//         N = N / 10

//     print "\nCount of even digits: ", evenCount
// end function

// // Example usage:
// number = 123456789
// countAndPrintOddEvenDigits(number, oddCount, evenCount)


#include <stdio.h>

void countAndPrintOddEvenDigits(int N, int *oddCount, int *evenCount) {
    *oddCount = 0;
    *evenCount = 0;

    int originalNumber = N; // Store the original value

    printf("Odd digits: ");
    while (N > 0) {
        int digit = N % 10;
        if (digit % 2 == 1) {
            printf("%d ", digit);
            (*oddCount)++;
        }
        N /= 10;
    }
    printf("\nCount of odd digits: %d\n", *oddCount);

    N = originalNumber; // Restore the original value

    printf("Even digits: ");
    while (N > 0) {
        int digit = N % 10;
        if (digit % 2 == 0) {
            printf("%d ", digit);
            (*evenCount)++;
        }
        N /= 10;
    }
    printf("\nCount of even digits: %d\n", *evenCount);
}

int main() {
    int number = 123456789;

    int oddCount, evenCount;

    countAndPrintOddEvenDigits(number, &oddCount, &evenCount);

    return 0;
}

