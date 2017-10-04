// Simplified version of vector

class GrowArray {
private:
    int* data;
    int used;
    int capacity;

    void grow() {
        // Double each time
    }
    void checkGrow() {
        if (used == capacity)
            grow();
    }

public:
    void addEnd(int v) { // O(1)
        checkGrow();

    }

    void addStart(int v) { // O(n)
        checkGrow();
    }

    void removeStart() { // O(n)

    }

};