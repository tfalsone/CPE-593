#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

void printArray(int arr[], int size)
{
  for(int i = 0; i < size; i++)
    cout << arr[i] << ' ';
  cout << endl;
}

void quicksort(int arr[], int left, int right)
{
  int piv_val = arr[(left+right)/2];

  int i = left, j = right;
  int temp;

  while ( i <= j) {
    while (arr[i] < piv_val)
      i++;
    while (arr[j] > piv_val)
      j--;
    if (i <= j){
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }

  if (left < j)
    quicksort(arr, left, j);
  if (i < right)
    quicksort(arr, i, right);
}

int main()
{
  int arr[] = {0, 4, 1, 5, 5, 1, 9};
  int size = sizeof(arr)/sizeof(arr[0]);
  cout << "The current array is: " << endl;
  printArray(arr, size);
  quicksort(arr, 0, size-1);
  cout << "The array after sorting is: " << endl;
  printArray(arr, size);
}
