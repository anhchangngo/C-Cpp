/*
Given an array of 10 elements: 2, 10, 27, 13, 90, 45, 5, 26, 49, 50.
In this problem, we try to find all co-prime numbers. Two integer numbers are co-prime if the
greatest common divisor of these two is 1.
The list of co-prime numbers from the above array is: {(2, 27), (2,13), (2,45), (2,5), (2,49), (10,
27), (10, 13), (10,49), (27,13), (27,5), (27,26), (27,50), (13,90), (13,45), (13,5), (13,49), (13,50),
(90,49), (90,26), (90,49), (45,26), (45,49), (5,26), (5,49), (26,49), (49,50)}
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
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

// Them 1 phan tu vao cuoi danh sach lien ket
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

//-----------------------
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

void co_prime(node a){
    node tmp = a;
    while(tmp != NULL){
        node curr = tmp->next;
        while(curr != NULL){
            if(gcd(tmp->data, curr->data) == 1){
                printf("(%d %d) \n", tmp->data, curr->data);
        }
        curr = curr->next;
    }
    tmp = tmp->next;
} 
}
//-----------------------

void in(node a){
    while(a != NULL){
        printf("%d ", a->data);
        a = a->next;
    } 
    printf("\n");
}

int main(){
    node a = NULL;
    insertLast(&a, 2);
    insertLast(&a, 10);
    insertLast(&a, 27);
    insertLast(&a, 13);
    insertLast(&a, 90);
    insertLast(&a, 45);
    insertLast(&a, 5);
    insertLast(&a, 26);
    insertLast(&a, 49);
    insertLast(&a, 50);

    in(a);

    co_prime(a);

}