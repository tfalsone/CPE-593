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


// Miller Rabin --> Reigning king at finding out if a number if prime