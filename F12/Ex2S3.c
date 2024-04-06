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

int prime(int n){
    if(n <= 1){
        return 0;
    }
    for(int i = 2; i <= sqrt(n); i ++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int twin_primes(int a, int b){
    if(((a == b + 2) || (b == a + 2)) && prime(a) && prime(b)){
        return 1;
    }
    else{
    return 0;
    }
}

void loop(node *head, int day_a, int day_b, int n){
    node tmp = *head;
    int a, b;

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

    if(twin_primes(a, b) == 1 || twin_primes(b, a) == 1){
        printf("(%d %d) \n", a, b);
    }
    if(day_b < n - 1){
        loop(head, day_a, day_b + 1, n);
    }
    else if (day_a < n - 2){
        loop(head, day_a + 1, day_a + 2, n);
    } 
}

void in(node a){
    while(a != NULL){
        printf("%d ", a->data);
        a = a->next;
    }
}

// {3, 101, 96, 47, 41, 7, 65, 9, 13, 5, 79, 45, 30, 11, 43};
int main(){
    node a = NULL;
    insertLast(&a, 3);
    insertLast(&a, 101);
    insertLast(&a, 96);
    insertLast(&a, 47);
    insertLast(&a, 41);
    insertLast(&a, 7);
    insertLast(&a, 65);
    insertLast(&a, 9);
    insertLast(&a, 13);
    insertLast(&a, 5);
    insertLast(&a, 79);
    insertLast(&a, 45);
    insertLast(&a, 30);
    insertLast(&a, 11);
    insertLast(&a, 43);


    in(a);
    printf("\n");
    loop(&a, 0, 1, 15);
}