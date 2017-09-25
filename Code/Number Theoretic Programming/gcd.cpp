#include<iostream>
using namespace std;

int gcd (int a, int b) {
    // O(log n)
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm (int a, int b) {
    
}

int main()
{
    int a, b;
    cout << "Choose two numbers'\n";
    cin >> a;
    cin >> b;

    cout << "The GCD of those numbers is " << gcd(a,b) << endl;
}