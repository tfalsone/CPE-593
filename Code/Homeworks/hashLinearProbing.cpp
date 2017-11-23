#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class hashLinearProbing {
private:
    int capacity;
    int used;
    vector<int> collisions;
    int* hashMap;

    void grow() {
        if (capacity == 0) {
            capacity = 1;
            hashMap = new int[capacity];
        } else {
            capacity *= 2;
            int* temp = new int[capacity];
            for (int i = 0; i < used; i++) {
                temp[i] = hashMap[i];
            }
            delete [] hashMap;
            hashMap = temp;
        }
        //cout << "HashMap grown to size " << capacity << endl;
    }

    int hash(int m) {
        return m % capacity;
    }

public:
    hashLinearProbing() {
        hashMap = nullptr;
        capacity = used = 0;
        //cout << "Creating HashMap" << endl;
    }

    ~hashLinearProbing() {
        delete [] hashMap;
    }

    void add(int m) {
        // Check size of current map
        //cout << "Currently used spaces: " << used << endl;
        //cout << "Current capacity: " << capacity << endl;
        if ((2*used) >= capacity) {
          //cout << "Growing array" << endl;
            grow();
        }

        // Implement hashing function
        int pos = hash(m);
        int collide = 0;
        while(hashMap[pos] != 0 && hashMap[pos] != m) {
            collide ++;
            pos ++;
            if (pos > capacity-1) {
                pos == 0;
            }
        }
        // TODO - Only incrememnt used if it is a new number
        if (hashMap[pos] != m) {
          used++;
        }
        hashMap[pos] = m;
        collisions.push_back(collide);
        //cout << "Added " << m << " with " << collide << " collisions" << endl;
    }

    void getCollisions() {
      for (int i = 0; i < collisions.size(); i++) {
        cout << collisions[i] << '\t';
      }
      cout << endl;
    }

    void displayHistogram() {
        int* hist = new int[51];
        int j;
        //cout << collisions.size();
        for (int i = 0; i < collisions.size(); i++) {
          j = collisions[i];
          if (j > 50) {
            hist[51]++;
          } else {
            hist[j]++;
            //cout << j << '\t' << hist[j] << endl;
          }
        }

        for (int i = 0; i < 51; i++) {
          cout << i << '\t' << hist[i] << endl;
        }
        cout << ">50" << '\t' << hist[51] << endl;
        delete [] hist;
    }
};


int main() {
    hashLinearProbing h;
    int r;
    cin >> r;
    for (int i = 1; i < r; i++) {
      h.add(i);
    }
    h.getCollisions();
    cout << endl;
    h.displayHistogram();
}
