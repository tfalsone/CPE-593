


class BinaryTree {
private:
    class Node {
    private:
        int val;
        Node* left, right;
    public:
        Node(int v, Node* L, Node* R) : val(v), left(L), right(R) {};
    } *root;

    void inorder() {
        if (left != nullptr)
            left.inorder;
        if (right != nullptr)
            right.inorder;
    }

public:
    BinaryTree() {
        root = nullptr;
    }



    void add(int v) {
        if (root == nullptr) {
            root = new Node(v, nullptr, nullptr);
            return;
        }
        Node* p = root;
        if (p->val > v) {

        } else {

        }
    }
};