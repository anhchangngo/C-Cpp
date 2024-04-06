#include <iostream>
#include <math.h>
using namespace std;

int nt(int n){
    for(int i = 2; i <= sqrt(n); i ++){
        if(n % i == 0 || n < 2){
        return false;
    }
    }
    return n > 1;
}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++){
        if(nt(a[i])){ 
            cout << a[i] << " ";
        }
    }
    return 0;
}
