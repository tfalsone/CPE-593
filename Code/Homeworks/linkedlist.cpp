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
        Node* next;
        Node* last;
        int val;
        Node(int v, Node *next, Node *last) : v(val), next(next), last(last);
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
            head = temp;
        }
    }

    void addAtTail(int v) {
        if(tail = nullptr) {
            head = new Node(v, nullptr, nullptr);
            tail = head;
        } else {
            Node* temp = new Node(v, nullptr, tail);
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
                temp = head;
                head = tail = nullptr;
                delete temp;
            }
        }
    }

    void deleteAtTail() {
        
    }
};