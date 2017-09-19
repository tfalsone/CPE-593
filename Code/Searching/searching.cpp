#include <iostream>
#include <math.h>
using namespace std;

int binarySearch(int arr[], int target, int a, int b) {
    if (a == b)
        return -1; // Target not found

    int guess = (a + b)/2;

    if (arr[guess] < target)
        return binarySearch(arr, target, guess + 1, b);
    else if (arr[guess] > target)
        return binarySearch(arr, target, a, guess-1);
    else
        return guess;
}



int main()
{
    int arr[10] = {1, 2, 5, 7, 10, 12, 20, 22, 26, 30};
    
    cout << binarySearch(arr, 10, 0, 9) << endl;
}