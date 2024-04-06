#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

double equation(double x) {
    return pow(x, 3) - cos(x) + 1; 
}

int main(){
    double a = -1.1;
    double b = 1.0;
    double xapxi = 1e-6;
    if(equation(a) * equation(b) > 0){
        cout << "F(x) no change sign" << endl;
    }

    for(int i = 1; i < 100; i++){
        double c = 0.5 * (a + b);
        double fc = equation(c);
        if (abs(fc) < xapxi){
            cout << c << endl;
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