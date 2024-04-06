#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;

double equation(double x) {
    return pow(2.718281828, - x) * (pow(x, 2) + 5*x + 2) + 1;
}

int main(){
    double a = -1.0;
    double b = 0.0;
    cout << "Iteration 0: x = " << 0.5*(a + b) << endl;
    
    for(int i = 1; i <= 6; i++){
        double c = 0.5 * (a + b);
        double fc = equation(c);
        cout << "The relative error" << 
                if (fc == 0){
            cout << "There are at least 1 root" << endl;
            break;
                }
            else if (fc < 0){
                a = c;
            }
            else 
            b = c;
        }
    return 0;
}