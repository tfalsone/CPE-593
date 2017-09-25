#include<iostream>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++){
        if (isPrime(i))
            count++;
    }
    return count;
}

void eratosthenes(int n) {
    // O(nlog log n)
    bool primes[n] = true;
    for (int i = 2; i <= n; i++) {
        if (primes(i)) {
            for (int j = 2*i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
}

void modifiedEratosthenes(int n) {
    bool primes[n] = true;
    for (int k = 2*2; k <= n; k += 2) {
        primes[k] = false;
    }
    for (int i = 2; i <= n; i++) {
        if (primes(i)) {
            for (int j = i*i; i <= n; i += 2*i) {
                primes[j] = false;
            }
        }
    }
}