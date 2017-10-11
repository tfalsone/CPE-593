#include<iostream>
using namespace std;

// Returns (x^y) % p
int power(int x, unsigned int y, int p) {
    int res = 1;
    x = x % p;

    while (y > 0) {
        if (y % 2 == 1)
            res = (res*x) % p;
        y /= 2;
        x = (x*x) % p;
    }
    return res;
}

bool millerRabin(int d, int n) {
    // Pick a random number between [2, n-2]
    // n-4 to make sure n > 4
    int a = 2 + rand() % (n-4);
    int x = power(a, d, n);

    if (x == 1 ||  x == n-1)
        return true;

    while (d != n-1) {
        x = (x*x) % n;
        d *= 2;

        if (x == 1) return false;
        if (x == n-1) return true;
    }
    return false;
}

bool isPrime(int n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    int d = n-1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        return millerRabin(d, n);
}

int main() {
    int k = 5;
    cout << "All primes smaller than 100: " << endl;
    int count = 0;
    for (int n = 100; n < 1000; n++)
        if (isPrime(n, k))
            count++;
    cout << count;
}