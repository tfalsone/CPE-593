#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;


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

    for (int i = 3; i <= sqrt(b); i += 2) {
        int rem = a % i;
        //cout << "rem: " << rem << endl;
        int diff = i - rem;
        //cout << "diff: " << diff << endl;
        for (int j = a + diff; j < range; j += diff) {
            //cout << "j: " << j << '\t' << "i: " << (i) << endl;
            if (primes[j] && (j) != i) {
                primes[j] = false;
                cout << a + j << '\t';
            }
        }
    }

    cout << endl;

    
    for (int i = 0; i < range; i++) {
        if (primes[i] == true){
           count++;
           cout << a+i << '\t';
        }
    }
    cout << endl;
    return count;
}


int main() {
    cout << computePrimes(1, 100) << endl;
}