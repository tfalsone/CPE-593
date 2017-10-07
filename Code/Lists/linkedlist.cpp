class LL {
private:
    class Node {
    public:
        int val;
        Node* next;
        Node(int v, Node* next) : val(v), next(next) {}
    };

    Node *head;

    Node* tail() {
        Node* p = head;
        if (p == nullptr)
            return nullptr;
        while (p->next != nullptr)
            p = p->next;
    }

public:
    LL() {
        head = nullptr;
    }

    void addStart(int v) {
        head = new Node(v, head);
        tail = head;
    }
    void addEnd(int v) {
        if (head == nullptr) {
            head = new Node(v, nullptr);
            return;
        }
        tail()->next = new Node(v, nullptr)
    }

};


int main()
{

}