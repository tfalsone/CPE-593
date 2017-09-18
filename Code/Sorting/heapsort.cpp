#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
  for(int i = 0; i < size; i++)
    cout << arr[i] << ' ';
  cout << endl;
}

void heapify(int arr[], int n, int i)
{
  int largest = i;  // Initial root
  int left = 2*i + 1;  // Left branch of root
  int right = 2*i + 2;  // Right branch of root
    
  // If left child is larger than root
  if (left < n && arr[left] > arr[largest])
    largest = left;
    
  // If right child is larger than root
  if (right < n && arr[right] > arr[largest])
    largest = right;
    
  // If largest is not root
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest); // Sort any branches below the branches you just switched
  }
}

void heapsort(int arr[], int n)
{
  // Build heap (rearrange array)
  for (int i = (n / 2) - 1; i >= 0; i--)
    heapify(arr, n, i);

  // Put largest number in proper position, sort tree without the already sorted number
  for (int i = n-1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main()
{
  int arr[] = {0, 2, 7, 12, 9, 2, 8};
  int size = sizeof(arr)/sizeof(arr[0]);
  cout << "The unsorted array: " << endl;
  printArray(arr, size);
  heapsort(arr, size);
  cout << "The sorted array: " << endl;
  printArray(arr, size);
}
