#include <stdio.h>

void move(int n, char S, char D, char T) {
    if (n == 1)
        printf("Move #%d from %c to %c\n", n, S, D);
    else {
        move(n - 1, S, T, D);
        printf("Move #%d from %c to %c\n", n, S, D);
        move(n - 1, T, D, S);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    move(n, 'A', 'B', 'C');
    getchar(); // Pause before exiting
    return 0;
}