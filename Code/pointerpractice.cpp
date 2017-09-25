#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *b = &a;
    int c = *b;

    cout << a << '\t' << b << '\t' << c << endl;
}