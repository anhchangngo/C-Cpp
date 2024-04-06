
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int val;
    struct _Node *pNext;
} Node;

typedef struct _List {
    int size;
    Node *pHead;
} List;

Node *create_node(int n){
    Node *t = (Node *)malloc(sizeof(Node));
    t->val = n;
    t->pNext = NULL;
    return t;
}

List *new_list(){
    List *l = (List *)malloc(sizeof(List));
    l->size=0;
    l->pHead=NULL;
    return l;
}

void add_list(List *l,int value){
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = value;
    p->pNext=NULL;
    
    if (l->pHead==NULL){
        l->pHead = p;
        l->size++;
    }
    else {
        Node *tempt = l->pHead;
        while (tempt->pNext != NULL){
            tempt = tempt->pNext;
        }
        tempt->pNext = p;
        l->size++;
    }
}


void display(List *l){
    if (l->size==0){
        printf("List is empty!\n");
        return;
    }
    else {
        Node *tempt = l->pHead;
        for (int i=0;i<l->size;i++){
            printf("%d ",tempt->val);
            tempt = tempt->pNext;
        }
    }
}

void arr2linked_list(List *l, int arr[], int length){
    if (length<=0) return;
    for (int i=0;i<length;++i){
        add_list(l,arr[i]);
    }
}

int main(){
    int array[] = {15, 19, 36, 48, 55, 12, 1, 84, 96, 21, 17, 3, 40, 14, 2, 66, 4};
    int length = sizeof(array)/sizeof(array[0]);
    List *list = new_list();
    arr2linked_list(list,array,length);
    display(list);

    return 0;
}