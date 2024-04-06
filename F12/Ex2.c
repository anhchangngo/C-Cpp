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

// Them phan tu vao cuoi
void insertLast(node *a, int x){
    node tmp = makeNode(x);
    if(*a == NULL){
        *a = tmp;
    }
    else {
        node p = *a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
}

int Pythagorean(int a, int b, int c) {
    if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
        return 1;
    } else {
        return 0;
    }
}

void loop(node *head, int day_a, int day_b, int day_c, int n){
    node tmp = *head;
    int a, b, c;

    // di chuyển con trỏ tmp đến vị trí ind_a trong danh sách liên kết
    for(int i = 0; i < day_a; i++){
        tmp = tmp->next;
    }
    a = tmp->data;

    // di chuyển con trỏ tmp đến vị trí ind_b trong danh sách liên kết
    for(int j = 0; j < day_b - day_a; j ++){   // day_b - day_a : khoảng từ day_a -> day_b
        tmp = tmp->next;
    }
    b = tmp->data;

    // di chuyển con trỏ tmp đến vị trí ind_c trong danh sách liên kết
    for(int k = 0; k < day_c - day_b; k ++){
        tmp = tmp->next;
    }
    c = tmp->data;

    if(Pythagorean(a, b, c) == 1 || Pythagorean(b, c, a) == 1 || Pythagorean(c, a, b) == 1){
        printf("\n %d^2 + %d^2 = %d^2 \n", a, b, c);
    }
    if(day_c < n - 1){
        loop(head, day_a, day_b, day_c + 1, n);
    }
    else if(day_b < n - 2){
        loop(head, day_a, day_b + 1, day_b + 2, n);
    }
    else if(day_a < n - 3){
        loop(head, day_a + 1, day_a + 2, day_a + 3, n);
    }  
}

void in(node a){
    while(a != NULL){
        printf("%d ", a->data);
        a = a->next;
    }
}

// 4, 15, 28, 45, 40, 9, 53, 41, 8, 17, 3, 5.
int main(){
    node a = NULL;
    insertLast(&a, 4);
    insertLast(&a, 15);
    insertLast(&a, 28);
    insertLast(&a, 45);
    insertLast(&a, 40);
    insertLast(&a, 9);
    insertLast(&a, 53);
    insertLast(&a, 41);
    insertLast(&a, 8);
    insertLast(&a, 17);
    insertLast(&a, 3);
    insertLast(&a, 5);

    in(a);

    loop(&a, 0, 1, 2, 12);
}