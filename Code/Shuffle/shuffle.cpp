#include <iostream>
using namespace std;




void fischerYatesShuffle(int a[], int n) {
    for (int i = n - 1; i > 0; i--) {
        uniform_int_distribution<int> dist(0,i);
        swap(x[i], x[dist(generator)]);
    }
}

