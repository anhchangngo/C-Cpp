#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;

double equation(double x) {
    return cos(x) - x * pow(2.718281828, x);
}

int main(){
    double a = 0.0;
    double b = 1.0;
    cout << "Iteration 0: x = " << 0.5*(a + b) << endl;
    for(int i = 1; i <= 20; i++){
        double c = 0.5 * (a + b);
        double fc = equation(c);
        cout << "Iteration " << i << ": x = " << c << endl;
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