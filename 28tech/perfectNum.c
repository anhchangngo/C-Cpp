#include <stdio.h>
#include <math.h>

int is_perfect(int *n) {
  int sum = 1;
  for (int i = 2; i <= *n/2; i++) {
    if (*n % i == 0) {
      sum += i;
    }
  }
  return sum == *n && *n != 1;
}

void findPerfectNumbers(int n) {
    printf("Perfect numbers from 1 to %d:\n", n);
    for (int num = 1; num <= n; num++) {
        if (is_perfect(&num)) {
            printf("%d = 1", num);
            for (int i = 2; i <= num / 2; i++) {
                if (num % i == 0) {
                    printf(" + %d", i);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    printf("Enter a number (n): ");
    scanf("%d", &n);

    findPerfectNumbers(n);

    return 0;
}
