#include <stdio.h>
#include <stdlib.h> //for dynamic memory allocation
#include <stdbool.h>

typedef struct Ub_int{
    int first_sign;
    int cap; //array capacity
    int numDigit; //number of digits
    int *digit;
}Ub_int;

void init (Ub_int *P, int first_e, int n) {
    P-> first_sign = first_e;
    P-> cap = 100;
    P-> numDigit = n; 
    P-> digit = (int *)malloc(P->cap * sizeof(int));
}

//print value -1 for negative, 1 for positive 
void printvalue(Ub_int *P) {
    printf("%d", P->first_sign);
    for (int i = 0; i<P->numDigit; i++) {
        printf("%d", P->digit[i]);
    } 
}

void insert(Ub_int *P, int digit, int index) {
    if (index<0 || index > P->numDigit){
        printf("\nInvalid");
        return;
    }

    if (P->numDigit == P->cap) {
        printf("\nExceed capacity");
        return;
    }

    else {
        for (int i=P->numDigit; i>index; i--)
        P->digit[i] = P->digit[i-1];
        P->digit[index] = digit;
        P->numDigit++;
        printf("\nThe unbounded integer after inserting: ");
        printvalue(P); //print the value that the pointer point to
    }
}

bool isEmpty(Ub_int *P){
    return P->numDigit==0;
}

void delete(Ub_int *P, int index){
    if (isEmpty(P) == 1) {
        printf("\nNo value to remove");
        return;
    }
    if ((index<0) || (index > P->numDigit)){
        printf("\nInvalid");
        return;
    }
    else {
        for (int i = index - 1; i<P->numDigit; i++)
        P->digit[i] = P->digit[i+1];
        P->numDigit--;
        printf("\nThe unbounded integer after deleting: ");
        printvalue(P);
    }
}

void sumDigit(Ub_int *P) {
    int sum = 0;
    for (int i = 0; i<P->numDigit; i++){
        sum = sum + P->digit[i];
    }
    printf("\nSum of all digits: %d", sum);

}

int main() {
    printf("The number to be represented is: -6707\n");
    //Set up a original unbounded integer 
    Ub_int original;
    init(&original, -1, 4);
    original.digit[0] = 6;
    original.digit[1] = 7;
    original.digit[2] = 0;
    original.digit[3] = 7;
    printf("Original unbounded integer is: ");
    printvalue(&original);

    //Add 4 to position 3
    insert(&original, 4, 3);

    //Removing the position 5 
    delete(&original, 5);
    
    //Sum of all digits
    sumDigit(&original);
    return 0;
}