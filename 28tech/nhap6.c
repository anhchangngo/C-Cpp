#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LENGTH 100

typedef struct Node {
    char data[MAX_LENGTH];
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void init(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// size(): Return the size of the stack
int size(Stack st) {
    return st.top + 1;
}

void push(Stack* stack, const char* data) {   
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    strncpy(newNode->data, data, MAX_LENGTH - 1);
    newNode->data[MAX_LENGTH - 1] = '\0';  // Ensure null-termination
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

const char* top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return NULL;
    }
    return stack->top->data;
}

int isPalindrome(char str[]) {
    struct Stack stack;
    size(stack) = MAX;
    top(&stack) = -1;

    for (int i = 0; str[i] != '\0'; ++i) {
        push(&stack, &str[i]);
    }

    int len = sizeof(str);
    int flag = 1;

    for (int i = 0; i < len / 2; ++i) {
        if (pop(&stack) != str[len - i - 1]) {
            flag = 0;
            break;
        }
    }

    return flag;
}

int main() {
    char str[] = "12421";
    printf("%s is %s palindrome\n", str, (isPalindrome(str) ? "" : "not "));
    return 0;
}
