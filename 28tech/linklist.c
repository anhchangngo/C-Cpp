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

// Them 1 phan tu vao dau danh sach lien ket
void insertFirst(node *a, int x){
    node tmp = makeNode(x);
    if (*a == NULL){
        *a = tmp;
    }
    else {
    tmp->next = *a;
    *a = tmp;
    }
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

// Them 1 phan tu vao vi tri bat ki
void insertAny(node *a, int x, int pos){
    int n = Size(*a);
    if(pos <= 0 || pos >= n + 1){
        printf("Invalid postion ! \n");
    }
    if(pos == 1){
        insertFirst(a, x); return;
    }
    if(pos == n - 1){
        insertLast(a, x); return;
    }
    node p = *a;
    for(int i = 0; i < pos - 1; i ++){
        p = p->next;
    }
    node tmp = makeNode(x);
    tmp->next = p->next;
    p->next = tmp;
}

// Xoa 1 phan tu o dau
void deleteFirst(node *a){
    if(*a == NULL){
        return;
    }
    *a = (*a)->next;
}

// Xoa phan tu o cuoi
void deleteLast(node *a){
    if(*a == NULL){
        return;
    }
    node truoc = NULL, sau = *a;
    while(sau->next != NULL){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL){
        *a = NULL;
    }
    else{
    truoc->next = NULL;
}
}

// Xoa o giua 
void deleteAny(node *a, int pos){
    int n = Size(*a);
    if(pos <= 0 || pos >= n + 1){
        printf("Invalid positions ! \n");
    }
    node truoc = NULL, sau = *a;
    for(int i = 0; i <= pos - 1; i ++){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL){
        sau = sau->next;
    }
    else{
        truoc->next = sau->next;
    }
}

void sort(node *a){
    if (*a == NULL || (*a)->next == NULL) {
        // List is empty or has only one element, no need to sort
        return;
    }
    for(node p = *a; p != NULL; p = p->next){
        node min = p;
    for(node q = p->next; q != NULL; q = q->next){
        if(q->data < min->data){
            min = q;
        }
    }
    int tmp = p->data;
    p->data = min->data;
    min->data = tmp;
}
}

void in(node a){
    while(a != NULL){
        printf("%d ", a->data);
        a = a->next;
    }
    printf("\n");
}

int main(){
    node a = NULL;
    insertFirst(&a, 2);
    insertFirst(&a, 5);
    insertFirst(&a, 9);
    insertFirst(&a, 7);
    insertLast(&a, 8);
    in(a);

    deleteFirst(&a);
    deleteLast(&a);
    deleteAny(&a, 2);
    in(a);

    sort(&a);
    in(a);

    return 0;
}