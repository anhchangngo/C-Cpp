
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define CAPACITY 10

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


/*
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

    printf("Size: %d\n", size(myStack));

    if(isEmpty(myStack)){
        printf("Empty \n");
    }
    else{
        printf("Not Empty \n");
    }
    return 0;
}
*/

/* Chuyển đổi số nhị phân 
int main(){
    Stack myStack;
    init(&myStack);

    int n;
    printf("Input the value of n : ");
    scanf("%d", &n);
    while(n != 0){
        push(&myStack, n % 2);
        n /= 2;
    }
    while(!isEmpty(myStack)){
        printf("%d ", top(myStack));
        pop(&myStack);
    }
    return 0;
}
*/

/* số lớn hơn tiếp theo của phần tử trong mảng
int main() {
    int n;
    scanf("%d", &n);
    int a[n], b[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    Stack myStack;
    init(&myStack);

    for (int i = 0; i < n; i++) {
        if (isEmpty(myStack)) {
            push(&myStack, i);
        } else {
            while (!isEmpty(myStack) && a[top(myStack)] < a[i]) {
                b[top(myStack)] = a[i];
                pop(&myStack);
            }
            push(&myStack, i);
        }
    }

    while (!isEmpty(myStack)) {
        b[top(myStack)] = -1;
        pop(&myStack);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }

    return 0;
}
*/

// diện tích lớn nhất
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];

    for(int k = 0; k < n; k++){
        scanf("%d", &a[k]);
    }

    Stack myStack;
    init(&myStack);
    
    int res = INT_MIN;  // dien tich hinh chu nhat
    int i = 0;
    while(i < n){
        if(isEmpty(myStack) || a[i] >= a[top(myStack)]){
            push(&myStack, i);
            ++i;
        }
        else {
            int idx = top(myStack); // chi so o cot dinh stack
            pop(&myStack);
            // tinh toan hcn tao boi cot hien tai, trong do cot hien tai
            // duoc coi la ngan nhat cua hcn do
            if(isEmpty(myStack)){
                res = max(res, i * a[idx]);
            }
            else {
                res = max(res, a[idx] * (i - top(myStack) - 1));
            }
        }
    }
    while(!isEmpty(myStack)){
        int idx = top(myStack); // chi so o cot dinh stack
            pop(&myStack);
            // tinh toan hcn tao boi cot hien tai, trong do cot hien tai
            // duoc coi la ngan nhat cua hcn do
            if(isEmpty(myStack)){
                res = max(res, i * a[idx]);
            }
            else {
                res = max(res, a[idx] * (i - top(myStack) - 1));
            }

    }
    printf("%d \n", res);

    return 0;
}


//-------------------------------------------------------------------------------------------------

/* Stack theo tu

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
*/

/* in cac chu nguoc lai vs nhau
int main() {
    Stack myStack;
    init(&myStack);

    char s[100] = "python java php c++ js";
    char* token = strtok(s, " ");
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
*/

/* kiem tra tinh hop le cua dau ngoac
void solve() {
    Stack myStack;
    init(&myStack);

    char s[MAX_LENGTH];
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            push(&myStack, &s[i]);
        } else {
            if (isEmpty(&myStack)) {
                printf("INVALID\n");
                return;
            } else {
                pop(&myStack);
            }
        }
    }

    if (isEmpty(&myStack)) {
        printf("VALID\n");
    } else {
        printf("INVALID\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
*/