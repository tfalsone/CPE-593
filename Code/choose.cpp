#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

double ch[53][53] = {0};

double choose(int n, int k){

  if(ch[n][k] != 0)
    return ch[n][k];

  if (n == k || k == 0)
    return ch[n][k] = 1;

  ch[n][k] = choose(n-1,k-1) + choose(n-1,k);

  return ch[n][k];
}

int main()
{
  srand((unsigned)time(0));
  int n, k;
  for(int i = 0; i < 100000000; i++){
    n = 1 + (rand() % 52);
    k = rand() % n;
    choose(n,k);
  }
  cout << n << '\t' << k << '\t' << choose(n,k) << endl;
}
