int main(){
    int n; scanf("%d", &n);
    int a[n], b[n];
    for(int &x : a) scanf("%d", &x);
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(st.isEmpty(myStack)){
            st.push(&myStack, i);
        }
        else {
            while(!st.isEmpty(myStack) && a[st.top(myStack)] < a[i]){
                b[st.top(myStack)] = a[i];
                st.pop(&myStack);
            }
            st.push(&myStack,i);
        }
    }
    while(!isEmpty(myStack)){
        b[st.pop(&myStack)] = -1;
        st.pop(&myStack);
    }
    for(int x : b){
        printf("%d ", x);
    }
    
}
