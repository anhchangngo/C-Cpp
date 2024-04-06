#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* top;
    int size;
};

// Initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Push a number onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// Pop a number from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1; // Assuming -1 is not a valid data element in the stack
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

// Check if a number is prime
bool isPrime(int number) {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

// Step 1: Find and push prime numbers onto the stack
void findAndPushPrimes(struct Stack* stack, int num) {
    int currentNum = 2;
    while (num > 0) {
        if (isPrime(currentNum)) {
            push(stack, currentNum);
            num--;
        }
        currentNum++;
    }
}

// Step 2: Calculate the product of numbers in the stack
int calculateSphenicProduct(struct Stack* stack) {
    int product = 1;
    while (!isEmpty(stack)) {
        product *= pop(stack);
    }
    return product;
}

// Step 3: Display the result
void displayResult(struct Stack* stack) {
    int result = calculateSphenicProduct(stack);
    printf("Result: %d\n", result);
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    // Step 1: Find and push prime numbers
    findAndPushPrimes(&stack, 3);

    // Step 2: Calculate the product of the prime numbers
    displayResult(&stack);

    // Step 3: Display the result in the stack
    printf("Stack after processing: ");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }

    return 0;
}
