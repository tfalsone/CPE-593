#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class LL2 {
private:
    class Node {
    public:
        Node* next;
        Node* last;
        int val;
        Node(int val, Node *next, Node *last) : val(val), next(next), last(last) {};
    } *head, *tail;

public:
    LL2() {
        head = tail = nullptr;
    }

    ~LL2() {
        delete [] head; // TODO - need brackets?
    }

    void addAtHead(int v) {
        if(head == nullptr) {
            head = new Node(v, nullptr, nullptr);
            tail = head;
        } else {
            Node* temp = new Node(v, head, nullptr);
            head->last = temp;
            head = temp;
        }
    }

    void addAtTail(int v) {
        if(tail == nullptr) {
            //cout << "add first element" << endl;
            head = new Node(v, nullptr, nullptr);
            tail = head;
        } else {
            //cout << "add at tail" << endl;
            Node* temp = new Node(v, nullptr, tail);
            tail->next = temp;
            tail = temp;
        }
    }

    void deleteAtHead() {
        if(head == nullptr) {
            cout << "This list is empty, you can not delete from it" << endl;
            exit(1);
        } else {
            Node* temp = head;
            if (head->next != nullptr) {
                head = head->next;
                delete temp;
            } else {
                head = tail = nullptr;
                delete temp;
            }
        }
    }

    void deleteAtTail() {
        if(tail == nullptr) {
            cout << "This list is empty, you can not delete from it" << endl;
            exit(1);
        } else {
            Node* temp;
            if(head->next != nullptr) { // Only one element in list
                //cout << "deleting element" << endl;
                temp = tail;
                tail = tail->last;
                tail->next = nullptr;
                delete temp;
            } else {                
                temp = head;
                head = tail = nullptr;
                delete temp;
            }
        }
    }

    void addFront(int start, int step, int end) {
        if(step == 0) { return; }

        for(int i = start; i <= end; i += step) {
            addAtHead(i);
        }
    }

    void addBack(int start, int step, int end) {
        //cout << "start add" << endl;
        if(step == 0) { return; }

        for(int i = start; i <= end; i += step) {
            addAtTail(i);
        }
    }

    void removeFront(int n) {
        for (int i = 0; i < n; i++) {
            deleteAtHead();
        }
    }

    void removeBack(int n) {
        for (int i = 0; i < n; i++) {
            deleteAtTail();
        }
    }

    void output() {
        if(head == nullptr) { return; }
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->val << ",";
            temp = temp->next;
        }
        cout << '\n';
    }
};

int main() {
    LL2 arr;

    ifstream infile("HW4b.txt");
    string line;

    while (getline(infile, line))
    {
        stringstream iss(line);
        string inst, data;
        iss >> inst >> data;

        if (inst == "ADD_FRONT")
        {
            stringstream ss(data);
            vector<int> vect;
            int i;
            while (ss >> i)
            {
                vect.push_back(i);

                if (ss.peek() == ':')
                    ss.ignore();
            }
            arr.addFront(vect[0], vect[1], vect[2]);
        }
        else if (inst == "ADD_BACK")
        {
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
        }
        else if (inst == "OUTPUT")
        {
            arr.output();
        }
        else if (inst == "REMOVE_FRONT")
        {
            int n = stoi(data);
            arr.removeFront(n);
        }
        else if (inst == "REMOVE_BACK")
        {
            int n = stoi(data);
            arr.removeBack(n);
        }
        else
        {
            cout << "Error reading instruction" << endl;
        }
    }
}