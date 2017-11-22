// Simplified version of vector

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

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
        if (used == capacity) {
            grow();
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
        if (step == 0) { return; }

        for (int i = start; i <= end; i += step) {
            checkGrow();
            data[used] = i;
            used++;
        }
    }

    void addStart(int num) {
        int* temp = new int[capacity];
        temp[0] = num;
        for (int i = 1; i < used + 1; i++) {
            temp[i] = data[i-1];
        }
        used++;
        delete [] data;
        data = temp;
    }

    void addFront(int start, int step, int end) { // O(n)
        if (step == 0) { return; }

        for (int i = start; i <= end; i += step) {
            checkGrow();
            addStart(i);
        }

        // int* temp = new int[used];
        // int count = 0;
        // for (int i = 0; i < used; i++) {
        //     temp[i] = data[i];
        //     count++;
        // }

        // int j = ((end - start)/2); // Gets index of lowest number to be added (will work down to 0)
        // used = j + 1; // Gets amount of numbers being added
        // while (capacity < used) {
        //     grow();
        // }

        // for (int k = start; k <= end; k += step) {
        //     data[j] = k;
        //     cout << "index: " << j << "\t num: " << k << endl;
        //     j--;
        // }

        // for (int i = 0; i < count; i++) {
        //     checkGrow();
        //     data[used] = temp[i];
        //     used++;
        // }

    }

    void removeFront(int n) { // O(n)
        if (capacity == 0 || used == 0) { return; }
        int* temp = new int[capacity];
        for (int i = n; i < used; i++) {
            temp[i-n] = data[i];
        }
        delete [] data;
        data = temp;
        used -= n;
    }

    void removeBack(int n) {
        if (capacity == 0 || used == 0) { return; }

        int* temp = new int[capacity];
        for (int i = 0; i < used-n; i++) {
            temp[i] = data[i];
        }
        delete [] data;
        data = temp;
        used -= n;
    }

    void output() {
        for (int i = 0; i < used; i++) {
            cout << data[i] << ",";
        }
        cout << '\n';
    }

};

int main() {
    GrowArray arr;
    //arr.addBack(2, 5, 100);
    //arr.addFront(1, 2, 100);
    //arr.output();

    ifstream infile("HW4a.txt");
    string line;

    while(getline(infile, line)) {
        stringstream iss(line);
        string inst, data;
        iss >> inst >> data;

        if (inst == "ADD_FRONT") {
            stringstream ss(data);
            vector<int> vect;
            int i;
            while (ss >> i) {
                vect.push_back(i);

                if (ss.peek() == ':')
                    ss.ignore();
            }
            arr.addFront(vect[0], vect[1], vect[2]);
        } else if (inst == "ADD_BACK") {
            stringstream ss(data);
            vector<int> vect;
            int i;
            while (ss >> i)
            {
                vect.push_back(i);

                if (ss.peek() == ':')
                    ss.ignore();
            }
            arr.addBack(vect[0], vect[1], vect[2]);
        } else if (inst == "OUTPUT") {
            arr.output();
        } else if (inst == "REMOVE_FRONT") {
            int n = stoi(data);
            arr.removeFront(n);
        } else if (inst == "REMOVE_BACK") {
            int n = stoi(data);
            arr.removeBack(n);
        } else {
            cout << "Error reading instruction" << endl;
        }
    }
}
