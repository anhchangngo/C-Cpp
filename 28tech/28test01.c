#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 99999

typedef struct Unbounded_int {
    int size;
    int val[CAPACITY];
} ubint;

int length(int num){
    int count=0;
    if (num==0){
        return 1;
    } else {
        while (num!=0){
            num = num/10;
            count++;
        }
        return count;
    }
}

ubint int2list(int n,ubint *l)
{
    l->size = length(n);
    if (n<0){
        l->val[0]= -1;
        n=-n;
    } else{
        l->val[0]= 1;
    }
    for (int i=l->size;i>=1;i--){
        l->val[i]=n%10;
        n = n/10;
    }
    return *l;
}
void add_digit(ubint *l,int pos, int data){
    if (pos<1||pos>l->size+1){
        printf("invalid position!");
    }
    for (int i=l->size;i>=pos;i--){
        l->val[i+1] = l->val[i];
    }
    l->val[pos]=data;
    l->size++;
}
void remove_digit(ubint *l, int pos){
    if (pos>l->size || pos<1){
        printf("invalid position");
    } else{
        for (int i=pos;i<=l->size;i++){
            l->val[i] = l->val[i+1];
        }
        l->size--;
    }
}
int sum_digit(ubint *l){
    int sum = 0;
    for (int i=1;i<=l->size;i++){
        sum = sum + l->val[i];
    }
    return sum;
}
void display_list(ubint *l){
    printf("[ ");
    for (int i=0;i<=l->size;i++){
        printf("%d ",l->val[i]);
    }
    printf("]");
}

void display_int(ubint *l){
    
}

int main(){
    ubint l1;
    int n = 11908706;
    printf("Initial integer:\n%d\n",n);
    int2list(n,&l1);
    
    // display list of created integer
    printf("The initial integer created:\n");display_list(&l1);
    printf("\n");
    
    // add digit
    add_digit(&l1,2,9);
    printf("The integer after add 9 as the 2nd digit:\n"); display_list(&l1);
    printf("\n");
    
    // remove digit
    remove_digit(&l1,3);
    printf("The integer after remove the 3rd digit:\n"); display_list(&l1);
    printf("\n");
    
    // sum all digits
    printf("Sum of all digits: %d\n",sum_digit(&l1));

    return 0;
}