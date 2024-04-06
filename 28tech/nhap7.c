#include <stdio.h>
#define MAX 100

struct Stack {
    int size;
    int top;
    char arr[MAX];
};

void push(struct Stack* stack, char item) {
    if (stack->top == stack->size - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return;
    }
    return stack->arr[stack->top--];
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

int main() {
    char str[] = "12421";
    printf("%s is %s palindrome\n", str, (isPalindrome(str) ? "" : "not "));
    return 0;
}