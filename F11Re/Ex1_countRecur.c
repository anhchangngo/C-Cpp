// Function countAndPrintOddDigits(N):
//     if N == 0:
//         return
//     else:
//         currentDigit = N % 10
//         if currentDigit is odd:
//             print currentDigit
//         countAndPrintOddDigits(N / 10)

// Function countAndPrintEvenDigits(N):
//     if N == 0:
//         return
//     else:
//         currentDigit = N % 10
//         if currentDigit is even:
//             print currentDigit
//         countAndPrintEvenDigits(N / 10)

// Function countOddDigits(N):
//     if N == 0:
//         return 0
//     else:
//         currentDigit = N % 10
//         if currentDigit is odd:
//             return 1 + countOddDigits(N / 10)
//         else:
//             return countOddDigits(N / 10)

// Function countEvenDigits(N):
//     if N == 0:
//         return 0
//     else:
//         currentDigit = N % 10
//         if currentDigit is even:
//             return 1 + countEvenDigits(N / 10)
//         else:
//             return countEvenDigits(N / 10)

// Main():
//     number = 123456789  # Example number

//     Print "Odd digits: "
//     countAndPrintOddDigits(number)
//     Print "\nCount of odd digits: ", countOddDigits(number)

//     Print "\nEven digits: "
//     countAndPrintEvenDigits(number)
//     Print "\nCount of even digits: ", countEvenDigits(number)

#include <stdio.h>

// Recursive function to count and print odd digits
void countAndPrintOddDigits(int N) {
    if (N == 0) {
        return;
    } else {
        int currentDigit = N % 10;
        if (currentDigit % 2 != 0) {
            printf("%d ", currentDigit);
        }
        countAndPrintOddDigits(N / 10);
    }
}

// Recursive function to count and print even digits
void countAndPrintEvenDigits(int N) {
    if (N == 0) {
        return;
    } else {
        int currentDigit = N % 10;
        if (currentDigit % 2 == 0) {
            printf("%d ", currentDigit);
        }
        countAndPrintEvenDigits(N / 10);
    }
}

// Recursive function to count odd digits
int countOddDigits(int N) {
    if (N == 0) {
        return 0;
    } else {
        int currentDigit = N % 10;
        if (currentDigit % 2 != 0) {
            return 1 + countOddDigits(N / 10);
        } else {
            return countOddDigits(N / 10);
        }
    }
}

// Recursive function to count even digits
int countEvenDigits(int N) {
    if (N == 0) {
        return 0;
    } else {
        int currentDigit = N % 10;
        if (currentDigit % 2 == 0) {
            return 1 + countEvenDigits(N / 10);
        } else {
            return countEvenDigits(N / 10);
        }
    }
}

int main() {
    int number = 123456789;  // Example number

    // Count and print odd digits
    printf("Odd digits: ");
    countAndPrintOddDigits(number);
    printf("\nCount of odd digits: %d\n", countOddDigits(number));

    // Count and print even digits
    printf("\nEven digits: ");
    countAndPrintEvenDigits(number);
    printf("\nCount of even digits: %d\n", countEvenDigits(number));

    return 0;
}
