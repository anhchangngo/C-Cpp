#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node *node;

// Cap phat dong 1 node moi voi du lieu la so nguyen x
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

// Them 1 phan tu vao dau danh sach
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

void Count(node *a){
    int count_odd = 0;
    int count_even = 0;

    for(node p = *a; p != NULL; p = p->next){
    if(p->data % 2 != 0){  // count odd number
       count_odd ++;
    }

    if(p->data % 2 == 0){  // count even number 
        count_even ++;
    }
    }
    
    printf("The number of odd digits : %d \n", count_odd);
    printf("The number of even digits : %d \n", count_even);
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
    Count(&a);
    
}