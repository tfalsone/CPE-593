/*
  Thomas Falsone
  11/20/17
  CPE 593
*/

#include <iostream>
#include <vector>
//#include <stdint.h>

using namespace std;

class hashLinearProbing {
private:
    int capacity;
    int used;
    vector<uint32_t> collisions;
    uint32_t* hashMap;

    void grow() {
        if (capacity == 0) {
            capacity = 1;
            hashMap = new uint32_t[capacity];
        } else {
            capacity *= 2;
            uint32_t* temp = new uint32_t[capacity];
            for (int i = 0; i < used; i++) {
                temp[i] = hashMap[i];
            }
            delete [] hashMap;
            hashMap = temp;
        }
        //cout << "HashMap grown to size " << capacity << endl;
    }

    uint32_t hash(uint32_t a) {
      return a % capacity;
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

    void add(uint32_t m) {
        // Check size of current map
        //cout << "Currently used spaces: " << used << endl;
        //cout << "Current capacity: " << capacity << endl;
        if ((2*used) >= capacity) {
          //cout << "Growing array" << endl;
            grow();
        }

        // Implement hashing function
        uint32_t pos = hash(m);
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
        uint32_t* hist = new uint32_t[51];
        uint32_t j;
        //cout << collisions.size();
        for (uint32_t i = 0; i < collisions.size(); i++) {
          j = collisions[i];
          if (j > 50) {
            hist[51]++;
          } else {
            hist[j]++;
            //cout << j << '\t' << hist[j] << endl;
          }
        }

        for (uint32_t i = 0; i < 51; i++) {
          cout << i << '\t' << hist[i] << endl;
        }
        cout << ">50" << '\t' << hist[51] << endl;
        delete [] hist;
    }
};


int main() {
    hashLinearProbing h;
    uint32_t r;
    cin >> r;
    for (uint32_t i = 1; i <= r; i++) {
      h.add(i);
    }
    h.getCollisions();
    cout << endl;
    h.displayHistogram();
}
