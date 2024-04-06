/*

Static array-based stack: arrays can be simply used to manipulate collections of items.
Dynamic array-based stack: malloc() is capable of representing a stack.
Linked stack: A very flexible mechanism for dynamic memory management is provided by pointers

Mảng động là mảng được cấp phát bộ nhớ khi chạy chương trình, còn mảng tĩnh là mảng được cấp phát bộ nhớ khi lập trình.

Trong ngăn xếp dựa trên mảng tĩnh, dung lượng tối đa của ngăn xếp được xác định tại thời điểm biên dịch 
và nó không thay đổi trong quá trình thực thi chương trình. Mảng data bên trong cấu trúc Stack được cấp phát trước
với kích thước cố định (được xác định bởi CAPACITY). Điều này trái ngược với ngăn xếp dựa trên mảng động, 
trong đó bộ nhớ có thể được phân bổ và giải phóng động trong thời gian chạy.

                            push()      pop()       top() 
Array-based Stacks          O(1)         O(1)        O(1) 
Stacks with Linked List     O(1)         O(1)        O(1)

*/

#include <stdio.h>
#include <stdlib.h>

// Static Array-Based Stacks
/*
Simple to understand and implement.
Stack is asserted at the top without changing other elements.
Stack size has to be manipulated.


#define CAPACITY 10 // You can change this value as needed

// Static Array-Based Stacks
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

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    display(myStack);

    printf("Top element: %d\n", top(myStack));

    pop(&myStack);
    display(myStack);

    return 0;
}
*/

// --------------------------------------------------------------------------------------------------------

// Dynamic Array-Based Stacks

// Replace <DataType> with the desired data type (e.g., int, double, char, etc.)
/*
typedef int DataType;

struct Stack {
    int top;
    int capacity;
    DataType *array;
};

typedef struct Stack Stack;

// init(): this function allows creating an empty stack.
void init(Stack *s, int N) {
    s->top = 0;
    s->capacity = N;
    s->array = (DataType *)malloc(sizeof(DataType) * s->capacity);
}

// isEmpty(): Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == 0;
}

// size(): Return the size of the stack
int size(Stack *s) {
    return s->top;
}

// isFull(): Check if the stack is full
int isFull(Stack *s) {
    return s->top == s->capacity;
}

// push(): Add a new item to the stack
void push(Stack *s, DataType item) {
    if (isFull(s)) {
        printf("Stack overflow: Cannot push %d, stack is full.\n", item);
        return;
    }
    s->array[s->top++] = item;
}

// pop(): Remove the top item from the stack
void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow: Cannot pop from an empty stack.\n");
        return;
    }
    s->top--;
}

// top(): Retrieve the top item of the stack
DataType top(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return s->array[s->top - 1];
}

// display(): Display the content of the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i < s->top; ++i) {
        printf("%d ", s->array[i]);
    }
    printf("\n");
}

int main() {
    Stack myStack;
    init(&myStack, 5); // Creating a stack with a capacity of 5

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    display(&myStack);

    printf("Top element: %d\n", top(&myStack));

    pop(&myStack);

    display(&myStack);

    printf("Stack size: %d\n", size(&myStack));

    return 0;
}
*/

//----------------------------------------------------------------------------------------------------

// Stack Implementation with Linked Lists
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

struct Stack {
    Node *top;
    size_t size;
};

typedef struct Stack Stack;

// Initialize the stack
void init(Stack *st) {
    st->top = NULL;
    st->size = 0;
}

// Check if the stack is empty
int isEmpty(Stack *st) {
    return st->top == NULL;
}

// Push operation
int push(int newData, Stack *st) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL) {
        return 0; // Memory allocation failure
    }

    p->data = newData;
    p->next = st->top;
    st->top = p;
    st->size++;

    return 1; // Successful push
}

// Pop operation
int pop(Stack *st) {
    if (isEmpty(st)) {
        return 0; // Fail to pop from an empty stack
    }

    Node *p = st->top;
    st->top = st->top->next;
    st->size--;

    free(p);

    return 1; // Successful pop
}

// Retrieve the top item of the stack
int top(Stack *st) {
    if (isEmpty(st)) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return st->top->data;
}

// Return the size of the stack
size_t size(Stack *st) {
    return st->size;
}

// Check if the stack is full (not applicable for linked lists)
int isFull(Stack *st) {
    return 0;
}

// Display the content of the stack
void display(Stack *st) {
    if (isEmpty(st)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    Node *current = st->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack myStack;
    init(&myStack);

    push(10, &myStack);
    push(20, &myStack);
    push(30, &myStack);

    display(&myStack);

    printf("Top element: %d\n", top(&myStack));
    printf("Stack size: %zu\n", size(&myStack));

    pop(&myStack);

    display(&myStack);

    return 0;
}