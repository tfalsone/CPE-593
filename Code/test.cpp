#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
  int arr[] = {0, 1, 4, 2, 9, 7};
  int size = sizeof(arr)/sizeof(arr[0]);
  cout << size;

  srand((unsigned)time(0));
  int pivot_index = rand() % size;   // Generates random pivot point within bounds of array
  int piv_val = arr[pivot_index];
  cout << pivot_index << '\t' << piv_val << endl;
}
