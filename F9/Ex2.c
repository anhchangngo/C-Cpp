#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Node {
    int data; // store element value
    struct _Node *next; // the pointer point to the next element
} Node;

typedef struct _Node Node;
typedef struct _Stack {
    int size;
    Node *pTop;
} Stack;

// basic operation are re-written to adapt to the new use of stack implementation
void init(Stack *s) {
    s->size = 0;
    s->pTop = NULL;
}

int isEmpty(Stack st) {
    return st.size == 0;
}

// Push operation is adapted to the new declaration
int push(int newData, Stack *st) {
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        return 0;
    }
    p->data = newData;
    p->next = st->pTop;
    st->pTop = p;
    st->size++;
    return 1; // successful operation - push successfully
}

// Pop operation is adapted to the new declaration
int pop(Stack *st) {
    Node *p = NULL;
    if (isEmpty(*st)) {
        return 0; // fail to pop
    }
    p = st->pTop;
    int data = p->data;
    st->pTop = st->pTop->next;
    st->size--;
    free(p); // free the memory allocated for the popped node
    return data;
}

void pushPrime(int x, Stack *st, Stack *sphenic) {
    int temp = x;
    for (int i = 2; i <= sqrt(temp); i++) {
        int num_each_fact = 0;
        while (temp % i == 0) {
            num_each_fact++;
            temp /= i;
        }
        if (num_each_fact == 1){
            push(i, st);
        }
    }
    if (temp != 1) {
        push(temp, st);
    }
    int product = 1;
    for (int i = 0; i<3; i++) {
        int poppedElement = pop(st);
        product *= poppedElement;
    }
    if(product == x){
        push(x, sphenic);
    }
}


void display(Stack *st) {
    printf("Stack of sphenic number: ");
    Node *top = st->pTop;
    while (top != NULL) {
        printf("%d  ", top->data);
        top = top->next;
    }
}

void checkAll(int x, Stack *st, Stack *sphenic, int i){
    if (i>x){
        return;
    }
    else{
        pushPrime(i, st, sphenic);
    }
    return checkAll(x, st, sphenic, i+1);
}

int main() {
    int x = 100;
    Stack *sPrime = (Stack*)malloc(sizeof(Stack));
    Stack *sphenic = (Stack*)malloc(sizeof(Stack));
    init(sPrime);
    init(sphenic);
    checkAll(x, sPrime, sphenic, 1);
    display(sphenic);

    // Read the value of x from the user
    // printf("Enter a number: ");
    // scanf("%d", &x);

    // Free the memory allocated for the stack
    while (!isEmpty(*sPrime)) {
        pop(sPrime);
    }
    free(sPrime);

    return 0;
}
// The correct time complexity expression for the prime factorization part of your code is 
// O(sqrt(x)*log(logx))
// n is incorrect in this context; it should be 
// x since you're dealing with the input number.