// Simplified version of vector

class GrowArray {
private:
    int* data; // int[]
    int used;
    int capacity;

    void grow() {
        // Double each time
        if (capacity == 0) {
            capacity = 1;
            data = new int[capacity];
        } else {
            capacity *= 2;
            int* temp = new int[capacity];
            for (int i = 0; i < (used); i++) {
                temp[i] = data[i];
            }
            delete [] data;
            data = temp;
        }
    }
    void checkGrow() {
        if (used == capacity)
            grow();
    }

    void addAtPosition (int val, int pos) {
        int *temp = data;
        for (int i = 0; i < pos; i++) {
            temp = temp -> next;
        }
    }

public:
    GrowArray() {
        data = nullptr;
        capacity = used = 0;
    }

    ~GrowArray() {
        delete [] data;
    }

    void addBack(int start, int step, int end) { // O(1)    
        for (int i = start; i <= end; start += step) {
            checkGrow();
            data[used] = i;
            used++;
        }
    }

    void addFront(int start, int step, int end) { // O(n)
        checkGrow();
    }

    void removeFront(int num) { // O(n)

    }

    void removeBack(int num) {

    }

    void output() {

    }

};
