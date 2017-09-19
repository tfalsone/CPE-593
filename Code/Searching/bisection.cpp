#include <iostream>
#include <math.h>
using namespace std;

typedef double (*FuncOneVar)(double);

double bisection(FuncOneVar f, double a, double b, double eps) {
    double y1 = f(a);
    double y2 = f(b);

    if(y1 * y2 > 0) {
        cout << "f(a) and f(b) are not opposite sign\n";
        
    }
}

int main()
{
    
}