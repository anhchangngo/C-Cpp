#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *node;

node makeNode(int x){
    node tmp = (node)malloc(sizeof(struct Node));
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

// Kiem tra rong
bool empty(node a){
    return a = NULL;
}

int Size(node a){
    int cnt = 0;
    while(a != NULL){
        ++cnt;
        a = a->next;
    }
    return cnt;
}

void insertFirst(node *a, int x){
    node tmp = makeNode(x);
    if(*a == NULL){
        *a = tmp;
    }
    else{
        tmp->next = *a;
        *a = tmp;
    }
}

int countOdd(node *a){
    node p = *a;
    int count = 0;
    if(*a == NULL){
        return 0;
    }
    if(p->data % 2 != 0){
        count ++;
    }
        return count + countOdd(&p->next);
}

int countEven(node *a){
    node p = *a;
    int count = 0;
    if(*a == NULL){
        return 0;
    }
    if(p->data % 2 == 0){
        count ++;
    }
        return count + countEven(&p->next);
}

void in(node a){
    while(a != NULL){
        printf("%d", a->data);
        a = a->next;
    }
}

int main(){
    node a = NULL;
    insertFirst(&a, 0);
    insertFirst(&a, 5);
    insertFirst(&a, 4);
    insertFirst(&a, 3);

    in(a);

    printf("\n");

    int oddCount = countOdd(&a);
    printf("Number of odd digits: %d\n", oddCount);

    int evenCount = countEven(&a);
    printf("Number of even digits: %d\n", evenCount);
}