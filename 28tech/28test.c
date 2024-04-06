//          ollama run codellama

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Website{
    char url[100];
    char title[100];
    struct Website* next;
} Website;

typedef struct Stack{
    int size;
    struct Website* pTop;
} Stack;

void init(Stack* stack){
    stack->size = 0;
    stack->pTop = NULL;
}

int isEmpty(Stack* stack){
    return (stack->pTop == NULL);
}

Website* newWebsite(char newurl[], char newtitle[]){
    Website* newWebsite = (Website*)malloc(sizeof(Website));
    strcpy(newWebsite->url,newurl);
    strcpy(newWebsite->title, newtitle);
    newWebsite->next =  NULL;
    return newWebsite;
}

void push(Stack* stack,Website* website){
   website->next = stack->pTop;
   stack->pTop = website;
   stack->size++;
}
    

Website* pop(Stack* stack){
    if(isEmpty(stack)){
       printf("Error! There are no website to pop.\n");
    }
        Website* current = stack->pTop;
        stack->pTop = stack->pTop->next;
        stack->size--;
        return current;
    
}

void display(Stack* stack){
    if(isEmpty(stack)){
        printf("Error! Stack are empty.\n");
    } else{
        Website* current = stack->pTop;
        while(current != NULL){
        printf("Your website information is:URL:%s - Title:%s\n",current->url,current->title);
        current = current->next;
        }
    }
}

int main(){
    Stack Backward, Forward;

    init(&Backward);
    init(&Forward); 

    Website* web1 = newWebsite("http://www.Moodle.usth.edu.vn","USTH moodle");
    push(&Backward,web1);
    Website* web2 = newWebsite("http://www.Youtube.com"," Youtube");
    push(&Backward,web2);
    Website* web3 = newWebsite("http://www.Codeacademy","Codeacademy");
    push(&Backward,web3);
    Website* web4 = newWebsite("http://www.Facebook.com","Facebook");
    push(&Backward,web4);

    printf("Before returning to the previuos website:\n");
    display(&Backward);
    display(&Forward);
    
    Website* prevWeb = pop(&Backward);
    push(&Forward,prevWeb);
    printf("After returning:\n");
    display(&Backward);
    display(&Forward);

    Website* nextWeb = pop(&Forward);
    push(&Forward,nextWeb);
    printf("After forward to the next website:\n");
    display(&Backward);
    display(&Forward);

    return 0;
}