#include <iostream>
#include <vector>

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
                temp[i] = data[i];
            }
            delete [] data;
            data = temp;
        }
    }

    int hash(int m) {
        return m % capacity;
    }

public:
    hashLinearProbing() {
        hashMap = nullptr;
        capacity = used = 0;
    }

    ~hashLinearProbing() {
        delete [] data;
    }

    void add(int m) {
        // Check size of current map
        if ((2*used) > capacity)
            grow();
        
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
        used ++;
        hashMap[pos] = m;
        collisions.push_back(collide);
    }

    void displayHistogram() {
        vector<int> histogram;
        int col_ind = 0;
        for (int i = 0; i < 50; i++) {
            
        }

        
    }
}


int main() {

}