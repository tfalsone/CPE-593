/*
Name: Thomas Falsone
Homework 2a - Quicksort
*/


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void printVector(vector<int> arr)
{
  for(int i = 0; i < arr.size(); i++)
    cout << arr[i] << ' ';
  cout << endl;
}

void quicksort(vector<int> &arr, int left, int right)
{
  int piv_val = arr[(left+right)/2];

  int i = left, j = right;

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
  ifstream infile("hw2a.dat");
  vector<int> arr;
  string line;

  while(getline(infile, line)) {
    stringstream iss(line);
    int elem;
    vector<int> arr;
    while (iss >> elem) {
      arr.push_back(elem);
    }

    if (arr.size() > 1) {
      // cout << "The unsorted array: " << endl;
      // printVector(arr);
      quicksort(arr, 0, arr.size());
      // cout << "The sorted array: " << endl;
      printVector(arr);
    }
  }


  // getline(infile, line);
  // stringstream iss(line);
  // int testCases, numElements;
  // iss >> testCases;
  // cout << testCases << endl;

  // while(testCases > 0) {
  //   getline(infile, line);
  //   stringstream iss2(line);
  //   int numElements;
  //   iss2 >> numElements;
  //   cout << numElements << endl;
  //   while(numElements > 0) {
  //     int elem;
  //     //getline(infile, line);
  //     stringstream iss(line);
  //     while(iss >> elem) {
  //       arr.push_back(elem);
  //       //cout << elem << '\t';
  //     }
  //     //cout << endl;
  //     numElements--;
  //   }
  //   testCases--;
  // }
}
