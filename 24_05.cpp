#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void truoc(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        truoc(root->left);
        truoc(root->right);
    }
}

void giua(Node* root) {
    if (root != NULL) {
        giua(root->left);
        cout << root->data << " ";
        giua(root->right);
    }
}

void sau(Node* root) {
    if (root != NULL) {
        sau(root->left);
        sau(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = new Node(100);
    root->left = new Node(5);
    root->right = new Node(31);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
	root->left->right->left = new Node(1);
	root->left->right->right = new Node(3);
	root->left->right->left->left = new Node(14);
	root->left->right->left->right = new Node(16);
    root->right->right = new Node(34);
    root->right->right->right = new Node(301);

    cout << "Thu tu truoc: ";
    truoc(root);
    cout << endl;

    cout << "Thu tu giua: ";
    giua(root);
    cout << endl;

    cout << "Thu tu sau: ";
    sau(root);
    cout << endl;

    return 0;
}
