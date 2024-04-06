#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 10000

typedef struct _List {
    int size;
    int data[CAPACITY];
} List;

void init_list(List *l){
    l->size = 0;
}

void display(List *l){
    if (l->size==0){
        printf("List is empty!\n");
        return;
    }
    for (int i=0;i<l->size;i++){
        printf("%d ",l->data[i]);
    }
}

void add(List *l, int index, int val){
    if (l->size == CAPACITY){
        printf("Cannot add more values!\n");
        return;
    }
    if ((index<0) || (index>l->size+1)){
        printf("invalid index!\n");
        return;
    } 
    else {
        if (l->size==0){
            l->data[0]=val;
            l->size++;
            return;
        } else{
        for (int i=l->size;i>index-1;i--){
            l->data[i] = l->data[i-1];
        }
        l->data[index-1] = val;
        l->size++;
        }
    }
}

void remove_list(List *l, int index){
    if (l->size==0){
        printf("List is empty!\n");
        return;
    }
    if ((index<0) || (index>l->size)){
        printf("invalid index!\n");
        return;
    }
    else {
        for (int i= index-1;i<l->size;i++){
            l->data[i] = l->data[i+1];
        }
        l->size--;
    }
}

int main(){
    List *list = (List *)malloc(sizeof(List));
    init_list(list);
    add(list,1,1);add(list,2,2);add(list,3,3);add(list,4,4);add(list,5,5);add(list,6,6); remove_list(list,1);
    display(list);

    return 0;
}