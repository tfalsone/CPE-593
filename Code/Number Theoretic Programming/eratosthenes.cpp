/*
 * For quiz next class (10/3):
 * - GCD
 * - Eratosthenes
 * - Find # of primes between two numbers
 */

 #include<iostream>
 using namespace std;

//  void eratosthenes(int n) {
//     // O(nlog log n)
//     bool primes[n] = true;
//     for (int i = 2; i <= n; i++) {
//         if (primes(i)) {
//             for (int j = 2*i; j <= n; j += i) {
//                 primes[j] = false;
//             }
//         }
//     }
// }

 // KNOW THIS
 void modifiedEratosthenes(int n) {
    bool primes[n];
    for (int i = 0; i < n; i++) {
        primes[i] = true;
    }
    for(int i = 4; i < n; i += 2)
        primes[i] = false;
    for(int i = 3; i < n; i++) {
        if(primes[i]) {
            for(int j = i*i; j < n; j += 2*i)
                primes[j] = false;
        }
    }
    for (int i = 2; i < n; i++){
        if (primes[i] == true)
           cout << i << '\t';
    }
    cout << endl;
 }

 void eratosthenes2(int n) {
     bool primes[n+1];
     for (int i = 0; i <= n; i++) {
         primes[i] = true;
     }
     for (int i = 2; i <= n; i++) {
         if (primes[i]) {
             for (int j = i*i; j <= n; j += i){
                 primes[j] = false;
             }
         }
     }
     for (int i = 2; i < n; i++){
         if (primes[i] == true)
            cout << i << '\t';
     }
     cout << endl;
 }

 
//  class Bitvec {
//  private:
//     uint64_t* bits;
//  public:
//     Bitvec(size_t size, bool initial) {
//         const int NUM_WORDS = (size + 63) / 64;
//         uint64_t v = (uint64_t)-1L;
//         bits = new uint64_t[NUM_WORDS];
//         for (int i = 0; i < NUM_WORDS; ++i)
//             bits[i] = v;
//     }

//     void set(uint64_t i) {
//         bits[i/64] |= (1 << (i % 64)); // Dividing by 64 shifts the boolean number by 6, gets position of word
//     }

//     void clear(uint64_t i) {
//         bits[i/64] &= ~(1 << (i % 64));
//     }

//     boot test(uint64_t i) {
//         return (bits[i/64]) & (1 << (i % 64));
//     }

//     void toggle(uint64_t i) {
//         bits[i/64] ^= (1 << (i % 64));
//     }
//  };

 int main() 
 {
    eratosthenes2(100);
    cout << endl;
    modifiedEratosthenes(100);
 }