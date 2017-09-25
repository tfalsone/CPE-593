#include<iostream>
using namespace std;

int bruteforcepower(int x, int n) {
    int prod = 1;
    for (int i = 1; i <= n; i++)
        prod = prod * x;
    return prod;
}

int betterPower(int x, int n) {
    int prod = 1;
    while (n > 0) {
        if (x % 2 == 1)
            prod *= x;
        x *= x;
        n *= (1/2);
    }
}

int powermod(int x, int n, int m) {
    int prod = 1;
    while (n > 0) {
        if (N % 2 != 0){
            prod = (prod * x) % m;
        }
        x = (x*x) % m;
        n = n / 2;        
    }
}

bool fermat (int p, int n) {
    for (int k = 1; k < n; k++) {
        a <-- random(2, p-1)
        if (powermod(a, p-1, p) != 1)
            return false;
    }
    return true;
}