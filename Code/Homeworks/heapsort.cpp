/*
Name - Thomas Falsone
Homework 2b - Heapsort
*/


#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

void printVector(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << ' ';
  cout << endl;
}

// n is size of the array, i is the position of the root
void heapify(vector<int> &arr, int n, int i)
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

void heapsort(vector<int> &arr, int n)
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
  ifstream infile("hw2b.dat");
  vector<int> arr;
  string line;

  while (getline(infile, line))
  {
    stringstream iss(line);
    int elem;
    vector<int> arr;
    while (iss >> elem)
    {
      arr.push_back(elem);
    }

    if (arr.size() > 1)
    {
      // cout << "The unsorted array: " << endl;
      // printVector(arr);
      heapsort(arr, arr.size());
      // cout << "The sorted array: " << endl;
      printVector(arr);
    }
  }

  // vector<int> arr;
  // for (int i = 10; i > 0; i--) {
  //   arr.push_back(i);
  // }
  // int size = arr.size();
  // cout << "The unsorted array: " << endl;
  // printVector(arr);
  // heapsort(arr, size);
  // cout << "The sorted array: " << endl;
  // printVector(arr);
}
