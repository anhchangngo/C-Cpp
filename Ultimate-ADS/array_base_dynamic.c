#include <stdio.h>
#include <stdlib.h>

typedef struct _List {
    int size;
    int CAPACITY;
    int *val;
} List;

void init_list(List *l, int capa){
    l->size=0;
    l->CAPACITY = capa;
    l->val = (int *)malloc(l->CAPACITY);
}

void add_list(List *l, int index, int value){
    if (l->size == l->CAPACITY){
        printf("Cannot add more values!\n");
        return;
    }
    if ((index<0) || (index>l->size+1)){
        printf("invalid index!\n");
        return;
    } 
    else {
        if (l->size==0){
            l->val[0]=value;
            l->size++;
            return;
        } else{
        for (int i=l->size;i>index-1;i--){
            l->val[i] = l->val[i-1];
        }
        l->val[index-1] = value;
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
            l->val[i] = l->val[i+1];
        }
        l->size--;
    }
}

void display_list(List *l){
    if (l->size==0){
        printf("List is empty!\n");
        return;
    }
    for (int i=0;i<l->size;i++){
        printf("%d ",l->val[i]);
    }
}

int main(){
    List *list = (List *)malloc(sizeof(List));
    init_list(list,7);
    add_list(list,1,1);add_list(list,2,2);add_list(list,3,3);add_list(list,4,4);add_list(list,5,5);add_list(list,2,6);remove_list(list,3);
    display_list(list);

    return 0;
}