#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the array-based list

struct List {
    int data[MAX_SIZE];  // Array to store the digits in the list
    int size; // current size of the list
};

typedef struct List list;

// Create a new list with sign
void makeList(list *a, int sign) {
    a->size = 1;
    a->data[0] = sign;
}

// Empty Check
bool empty(list a) {
    return a.size <= 1;
}

// Size of list
int Capacity(list a) {
    return a.size - 1;
}

// Add a digit at the first list
void insertFirst(list *a, int x) {
    if (a->size == MAX_SIZE) {
        printf("The list is full!\n");
        return;
    }
    for (int i = a->size; i > 1; i--) {
        a->data[i] = a->data[i - 1];
    }
    a->data[1] = x;
    a->size++;
}

// Add a digit at the last list
void insertLast(list *a, int x) {
    if (a->size == MAX_SIZE) {
        printf("The list is full!\n");
        return;
    }
    
    a->data[a->size] = x;
    a->size++;
}

// Add a new digit at any place in the list
void insertAny(list *a, int x, int pos) {
    if (a->size == MAX_SIZE) {
        printf("The list is full!\n");
        return;
    }
    if (pos < 1 || pos > a->size) {
        printf("The position is INVALID!\n");
        return;
    }
    for (int i = a->size; i > pos; i--) {
        a->data[i] = a->data[i - 1];
    }

    a->data[pos] = x;
    a->size++;
}

// Remove a digit at the first list
void removeFirst(list *a) {
    if (a->size <= 1) {
        printf("The list is empty!\n");
        return;
    }
    for (int i = 1; i < a->size - 1; i++) {
        a->data[i] = a->data[i + 1];
    }
    a->size--;
}

// Remove a digit at the last list
void removeLast(list *a) {
    if (a->size <= 1) {
        printf("The list is empty!\n");
        return;
    }
    a->size--;
}

// Remove a digit at a specific position in the list
void removeSpecific(list *a, int pos) {
    if (a->size == 0) {
        printf("The list is empty!\n");
        return;
    }
    if (pos < 1 || pos > a->size) {
        printf("The position is INVALID!\n");
        return;
    }
    for (int i = pos; i < a->size - 1; i++) {
        a->data[i] = a->data[i + 1];
    }

    a->size--;
}

// Calculate the sum of all digits in the list
void sumDigit(list *a) {
    int sum = 0;
    for (int i = 1; i < a->size; i++) {
        sum += a->data[i];
    }
    printf("Sum of digits: %d\n", sum);
}

// Print out the values in the list
void in(list a) {
    for (int i = 1; i < a.size; i++) {
        printf("%d", a.data[i]);
    }
}

// Main
int main() {
    list head;
    makeList(&head, 1); // Positive sign, change to -1 for negative sign
    int a[5] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]); // count the number of elements in array a

    // Create the initial list
    for (int i = n - 1; i >= 0; i--) {
        insertFirst(&head, a[i]);
    }
    printf("Unbounded integers: ");
    in(head);  // Print out array a
    printf("\n");

    // Add a new digit at position 4
    int newDigit = 6;
    int pos = 4;
    insertAny(&head, newDigit,pos);  // add new digits at any place in an integer
    printf("Add number 6 at list's position 4: ");
    in(head);
    printf("\n");

    // Remove a digit at position 5
    int pos1 = 5;
    removeSpecific(&head, pos1);   // remove a digit at a specific position in an integer
    printf("Remove a digit at list's position 5: ");
    in(head);
    printf("\n");

    // calculate the sum of all digits from an unbounded integer
    sumDigit(&head);

    return 0;
}