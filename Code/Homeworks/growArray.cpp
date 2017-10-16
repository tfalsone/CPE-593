// Simplified version of vector

class GrowArray {
private:
    int* data;
    int used;
    int capacity;

    void grow() {
        // Double each time
        if (capacity == 0) {
            capacity = 1;
        } else {
            capacity *= 2;
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
        checkGrow();

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