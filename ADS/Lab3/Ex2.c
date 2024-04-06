#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Web {
    char url[100];
    char title[50];
    struct Web* next;
};
typedef struct Web web;

struct Stack {
    int size;
    struct Web* pTop;
};
typedef struct Stack stack;

void init(stack* st) {
    st->pTop = NULL;
    st->size = 0;
}

// Check if stack is empty
bool empty(stack* st) {
    return st->pTop == NULL;
}

// make a new web
web* makeWeb(char x[], char y[]) {
    web* tmp = (web*)malloc(sizeof(web));
    strcpy(tmp->url, x);
    strcpy(tmp->title, y);
    tmp->next = NULL;
    return tmp;
}

// Add new web to the top of the stack.
void push(stack* st, char x[], char y[]) {
    web* p = makeWeb(x, y);
    if (p == NULL) {
        return;
    }
    p->next = st->pTop;
    st->pTop = p;
    st->size++;
}

// Removes the first web from the stack
web* pop(stack* st) {
    if (empty(st)) {
        return NULL;
    }
    web* p = st->pTop;
    st->pTop = st->pTop->next; // jump to next web
    st->size--;   // Reduce the size of the stack by 1
    return p;
}

// displays the current web in the stack
void display_cur_web(stack* st) {
    if (empty(st)) {
        printf("No website visited yet.\n");
    } else {
        printf("Current Website: %s %s\n", st->pTop->url, st->pTop->title);
    }
}

// displays all webs in the stack
void display_stack(stack* st, const char* st_name) {
    if (empty(st)) {
        printf("%s is empty.\n", st_name);
        return;
    }
    printf("%s:\n", st_name);
    web* cur_web = st->pTop;  // pointer to the top of the stack passed to st
    while (cur_web != NULL) {
        printf("%s %s\n", cur_web->url, cur_web->title);
        cur_web = cur_web->next;
    }
}

struct System {
    stack backward; // stores previously visited web pages
    stack forward;  // stores the next visited web pages
};
typedef struct System System;

void init_system(System* path) {
    init(&(path->backward));
    init(&(path->forward));
}

void display_all(System* path) {
    display_stack(&(path->backward), "Backward Stack");
    display_cur_web(&(path->backward));
    display_stack(&(path->forward), "Forward Stack");
    printf("\n");
}

void update_website(System* path, char* u, char* t) {
    push(&(path->backward), u, t);
    // Clear the forward stack when a new website is visited
    init(&(path->forward));
}

// return to the previous website
void back(System* path) {
    web* tmp = pop(&(path->backward));
    if (tmp != NULL) {
        push(&(path->forward), tmp->url, tmp->title);
    }
}

 // forward to the next website
void forward(System* path) {
    web* tmp = pop(&(path->forward));
    if (tmp != NULL) {
        push(&(path->backward), tmp->url, tmp->title);
    }
}

int main() {
    System path;
    init_system(&path);
    
    // Add website 
    update_website(&path, "https://www.hackthebox.com/", "HackTheBox");
    update_website(&path, "https://www.hackerrank.com/", "HackerRank");
    update_website(&path, "https://www.youtube.com/", "YouTube");

    display_all(&path);
    
    // return to the previous website
    back(&path);
    display_all(&path);

    // forward to the next website
    forward(&path);
    display_all(&path);

    return 0;
}