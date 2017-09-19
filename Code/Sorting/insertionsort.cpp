#include <iostream>
using namespace std;

// Probably not perfect code (should double check)
void insertionsort(int arr[], int n) {
  int key, j;
  for (int i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j -= 1;
    }
    arr[j+1] = key;
  }
}

int main(){
  int arr[] = {12, 11, 6, 17, 9};
  int n = sizeof(arr)/sizeof(arr[0]);

  insertionsort(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << '\t';
  cout << endl;

  return 0;
}
