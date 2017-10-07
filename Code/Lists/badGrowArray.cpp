#include<iostream>
using namespace std;

class BadGrowArray {
private:
    uint32_t capacity;
    int* data;

public:
    BadGrowArray() {
        data = nullptr;
        capacity = 0;
    }
    // Destructor
    ~BadGrowArray() {
        delete [] data;
    }
    // Copy constructor
    // Need to create a new int so that both arrays dont point to the same data
    BadGrowArray(const BadGrowArray &orig) : 
        data(new int[orig.capacity]), capacity(orig.capacity) {
            for (int i = 0; i < capacity; i++)
                data[i] = orig.data[i];
        }
    
    BadGrowArray operator =(const BadGrowArray &orig) {
        // make a copy
        BadGrowArray copy(orig);
        swap(data, copy.data);
        capacity = copy.capacity;
        /* Same as
        delete [] data;
        data = new int[orig.capacity];
        for (itn i = 0; i < capacity; i++)
            data[i] = orig.data[i];
        */
    }

    void addEnd(int v) { // O(n)
        int* temp = data;
        data = new int[capacity+1];
        for (int i = 0; i < capacity; i++)
            data[i] = temp[i];
        data[capacity] = v;
        delete [] temp;
        capacity++;
    }

    void addStart(int v) {
        int *temp = data;
        data = new int[capacity+1];
        data[0] = v;
        for (int i = 1; i < capacity+1; i++)
            data[i] = temp[i-1];
        delete [] temp;
        capacity++;
    }

    void insert(int i, int v) { //O(n)
        int* temp = data;
        data = new int[capacity+1];
        for (int j = 0; j < i; j++)
            data[j] = temp[j];
        data[i] = v;
        for (int j = i; j < capacity; j++)
            data[j+1] = temp[j];
        delete [] temp;
        capacity++;
    }

    void removeEnd() {
        capacity--;
        // Will waste space but can be done very quickly O(1)
    }
    void removeStart() {
        int* temp = data;
        data = new int[capacity-1];
        for (int i = 1; i < capacity; i++)
            data[i-1] = temp[i];
        delete [] temp;
        capacity--;
    }

    friend ostream& operator <<(ostream& s, const BadGrowArray &a) {
        for (int i = 0; i < a.capacity; i++)
            s << a.data[i] << '\t';
        return s;
    }

};

int main() {
    BadGrowArray L1;
    int val;
    cin >> val;
    L1.addEnd(val);
    cin >> val;
    L1.addStart(val);
    BadGrowArray L2 = L1;
    BadGrowArray L3;
    L2 = L3;
    const int LENGTH = 10;
    for (int i = 0; i < LENGTH; i++) {
        L1.addEnd(i);
    }
    cin >> val;
    L1.insert(2, val); // Delete the 0
    L1.removeEnd(); // 9
    L1.removeStart(); // 3
    cout << L1 << endl;

}