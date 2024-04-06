#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node *next;
};
typedef struct Node* node;

bool empty(node back){
    return back == NULL; // Fixed comparison operator
}

int getSize(node back){
    int cnt = 0;
    while(back != NULL){
        ++cnt;
        back = back->next;
    }
    return cnt;
}

node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

void push(node &back, int x){ // Changed reference parameter
    node tmp = makeNode(x);
    tmp->next = back;
    back = tmp;
}

void pop(node &back){ // Changed reference parameter
    node truoc = NULL, sau = back; // Changed Node to node
    while(sau->next != NULL){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL){
        back = NULL;
    }
    else{
        truoc->next = NULL;
    }
}

int Front(node back){
    while(back->next != NULL){
        back = back->next;
    }
    return back->data;
}

// 6 8 68 686
int main(){
    node back = NULL;
    push(back, 6);
    push(back, 8);
    vector<int> lp;
    while(1){
        int top = Front(back);
        pop(back);
        string s = to_string(top);
        if(s.size() == 9) {
            break; // Added missing closing curly brace
        }
        lp.push_back(top);
        push(back, top*10 + 6);
        push(back, top*10 + 8);
    }
    for(int x : lp){
        cout << x << " ";
    }
    return 0;
}