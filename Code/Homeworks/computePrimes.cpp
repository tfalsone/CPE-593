#include <iostream>
#include <string.h>
using namespace std;

const int MAX_PARTITION = 1000000;

int computePrimes(long int a, long int b) {
    bool primes[b+1];
    memset(primes, true, sizeof(primes));
    long int count;
    
    for (int i = 2; i <= b; i++) {
        if (primes[i]) {
            for (int j = i*i; j <= b; j+=i) {
                primes[j] = false;
            }
        }
    }
    
    for (int i = a; i <= b; i++) {
        if (primes[i] == true && i > 1){
           count++; 
           cout << i << endl;
        }
            
    }
    return count;
}

int main() {
    cout << computePrimes(1, 10) << endl;
}