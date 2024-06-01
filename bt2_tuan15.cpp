#include <iostream>
using namespace std;

template <typename T>
class BinaryTree {
public:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node* parent;
        Node(T val) : data(val), left(NULL), right(NULL), parent(NULL) {}
    };

    Node* root;
    int size;

    void deleteSubtree(Node* node) {
        if (node) {
            deleteSubtree(node->left);
            deleteSubtree(node->right);
            delete node;
        }
    }

    Node* findNode(Node* node, T x) {
        if (!node) return NULL;
        if (node->data == x) return node;
        Node* foundNode = findNode(node->left, x);
        if (foundNode) return foundNode;
        return findNode(node->right, x);
    }

    typedef Node* PNode;

    BinaryTree() : root(NULL), size(0) {}

    ~BinaryTree() {
        deleteSubtree(root);
    }

    void InitBTree() {
        deleteSubtree(root);
        root = NULL;
        size = 0;
    }

    void InsertParent(T x, PNode P) {
        PNode newNode = new Node(x);
        if (P == root) {
            newNode->left = root;
            root->parent = newNode;
            root = newNode;
        } else {
            newNode->left = P;
            newNode->parent = P->parent;
            if (P->parent->left == P) {
                P->parent->left = newNode;
            } else {
                P->parent->right = newNode;
            }
            P->parent = newNode;
        }
        size++;
    }

    void InsertLeftChild(T x, PNode P) {
        if (!P) return;
        PNode newNode = new Node(x);
        newNode->parent = P;
        P->left = newNode;
        size++;
    }

    void InsertRightChild(T x, PNode P) {
        if (!P) return;
        PNode newNode = new Node(x);
        newNode->parent = P;
        P->right = newNode;
        size++;
    }

    PNode FindNode(T x) {
        return findNode(root, x);
    }

    void DeleteCurrentNode(PNode P) {
        if (!P) return;
        if (P->left || P->right) return; // Only delete leaf nodes
        if (P->parent) {
            if (P->parent->left == P) {
                P->parent->left = NULL;
            } else {
                P->parent->right = NULL;
            }
        } else {
            root = NULL;
        }
        delete P;
        size--;
    }

    void DeleteLeftChild(PNode P) {
        if (!P || !P->left) return;
        deleteSubtree(P->left);
        P->left = NULL;
        size--;
    }

    void DeleteRightChild(PNode P) {
        if (!P || !P->right) return;
        deleteSubtree(P->right);
        P->right = NULL;
        size--;
    }

    int GetSize() const {
        return size;
    }
};

int main() {
    BinaryTree<int> tree;
    tree.InitBTree();

    BinaryTree<int>::Node* root = new BinaryTree<int>::Node(1);
    tree.InsertLeftChild(2, root);
    tree.InsertRightChild(3, root);

    BinaryTree<int>::Node* node2 = tree.FindNode(2);
    tree.InsertLeftChild(4, node2);
    tree.InsertRightChild(5, node2);

    cout << "Kich thuoc cay: " << tree.GetSize() << endl;

    tree.DeleteLeftChild(node2);
    cout << "Kich thuoc cay khi xoa node con trai cua node 2: " << tree.GetSize() << endl;

    return 0;
}
