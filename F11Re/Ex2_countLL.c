#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to count and print odd and even digits
void countAndPrintOddEvenDigits(struct Node* head, int* oddCount, int* evenCount) {
    *oddCount = 0;
    *evenCount = 0;

    struct Node* current = head;

    printf("Odd digits: ");
    while (current != NULL) {
        int digit = current->data;
        if (digit % 2 == 1) {
            printf("%d ", digit);
            (*oddCount)++;
        }
        current = current->next;
    }
    printf("\nCount of odd digits: %d\n", *oddCount);

    // Reset the current pointer to the head for the next iteration
    current = head;

    printf("Even digits: ");
    while (current != NULL) {
        int digit = current->data;
        if (digit % 2 == 0) {
            printf("%d ", digit);
            (*evenCount)++;
        }
        current = current->next;
    }
    printf("\nCount of even digits: %d\n", *evenCount);
}

// Function to insert a digit at the end of the linked list
struct Node* insertDigit(struct Node* head, int digit) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = digit;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

// Function to free memory allocated for the linked list
void freeLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    int number = 123456789;  // Example number

    struct Node* linkedList = NULL;

    // Create a linked list from the number
    while (number > 0) {
        int digit = number % 10;
        linkedList = insertDigit(linkedList, digit);
        number = number / 10;
    }

    int oddCount, evenCount;

    // Call the function to count and print odd and even digits
    countAndPrintOddEvenDigits(linkedList, &oddCount, &evenCount);

    // Free the memory allocated for the linked list
    freeLinkedList(linkedList);

    return 0;
}
