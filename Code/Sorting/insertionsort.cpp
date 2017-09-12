#include <iostream>
using namespace std;

// Probably not perfect code (should double check)
void insertionsort(int x[], int n) {
  for(int i = 1; i < n; i++){
    int temp = x[i];
    for(int j = i-1; i >= 0; i--){
      if(x[j] > temp){
        x[j+1] = x[j];
      } else {
        x[j+1] = temp;
        break;
      }
    }
  }
}

int main(){
  
  return 0;
}
