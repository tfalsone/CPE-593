#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

bool isPrime(long int n) {
    for (int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}


int computePrimes(long int a, long int b) {
    long int range = b - a + 1;

    bool primes[range];
    memset(primes, true, sizeof(primes));
    long int count = 0;

    if (a % 2 == 0) { // Even
        if (a == 2) {
            for (int i = 2; i < range; i += 2) {
                primes[i] = false;
                //cout << primes[i] << '\t';
            }
        } else {
            for (int i = 0; i < range; i += 2) {
                primes[i] = false;
            }
        }
    } else {
        if (a == 1) {
            primes[0] = false;
            for (int i = 3; i < range; i += 2) {
                primes[i] = false;
                //cout << primes[i] << '\t';
            }
        } else {
            for (int i = 1; i < range; i += 2) {
                primes[i] = false;
            }
        }
    }

    for (long int i = 3; i <= sqrt(b); i += 2) {
        if (isPrime(i)) {
            long int rem = a % i;
            long int diff = i - rem;
            for (int j = diff; j <= range; j += i) {
                if (primes[j] && j+rem != i) {
                    primes[j] = false;
                }
            }            
        }
    }
    
    for (int i = 0; i < range; i++) {
        if (primes[i] == true){
           count++;
           //cout << a+i << '\t';
        }
    }
    cout << endl;
    return count;
}


int main() {
    long int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << computePrimes(a, b) << endl;
}