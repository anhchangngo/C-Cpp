#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

// Static Array-Based Stacks check palindromic or not 

struct Stack {
    int data[CAPACITY];
    int top;
};
typedef struct Stack Stack;

// isFull(): Check if the stack is full
int isFull(Stack st) {
    return (st.top == CAPACITY - 1);
}

// init(): Initialize an empty stack
void init(Stack *st) {
    st->top = -1;
}

// isEmpty(): Check if the stack is empty
int isEmpty(Stack st) {
    return (st.top == -1);
}

// size(): Return the size of the stack
int size(Stack st) {
    return st.top + 1;
}

// push(): Add a new item to the stack
void push(Stack *s, int val) {
    if (isFull(*s))
        printf("Stack is full!\n");
    else {
        s->top++;
        s->data[s->top] = val;
    }
}

// pop(): Remove the top item from the stack
void pop(Stack *s) {
    if (isEmpty(*s))
        printf("Stack is empty!\n");
    else {
        s->top--;
    }
}

// top(): Retrieve the top item of the stack
int top(Stack s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1; // You might want to choose a different value for an empty stack
    } else {
        return s.data[s.top];
    }
}

int isPalindrome(char str[]) {
    struct Stack stack;
    stack.size = MAX;
    stack.top = -1;

    for (int i = 0; str[i] != '\0'; ++i) {
        push(&stack, str[i]);
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

// display(): Display the content of the stack
void display(Stack s) {
    if (isEmpty(s))
        printf("Stack is empty!\n");
    else {
        printf("Stack: ");
        for (int i = 0; i <= s.top; i++) {
            printf("%d ", s.data[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack myStack;
    init(&myStack);

    int a[n];
    scanf("%d", &n);

    int* token = inttok(int, " ");
    while (token != NULL) {
        push(&myStack, token);
        token = strtok(NULL, " ");
    }

    while (!isEmpty(&myStack)) {
        printf("%s ", top(&myStack));
        pop(&myStack);
    }

    return 0;
}