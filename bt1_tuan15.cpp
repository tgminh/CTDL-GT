#include <iostream>
#include <string>

using namespace std;

struct Node {
    int sbd;
    string hoTen;
    Node* left;
    Node* right;

    Node(int s, string h, Node* l = NULL, Node* r = NULL) {
        sbd = s;
        hoTen = h;
        left = l;
        right = r;
    }
};

class BSTree {
public:
    BSTree() : root(NULL) {}
    ~BSTree() { makeEmpty(); }

    bool isEmpty() { return root == NULL; }
    void makeEmpty() { makeEmpty(root); }

    void insert(int sbd, string hoTen) { insert(sbd, hoTen, root); }
    Node* search(int sbd) { return search(sbd, root); }

    void PREORDER_travl(Node* t) {
        if (t != NULL) {
            cout << t->sbd << " " << t->hoTen << endl;
            PREORDER_travl(t->left);
            PREORDER_travl(t->right);
        }
    }

    void INORDER_travl(Node* t) {
        if (t != NULL) {
            INORDER_travl(t->left);
            cout << t->sbd << " " << t->hoTen << endl;
            INORDER_travl(t->right);
        }
    }

    void POSTORDER_travl(Node* t) {
        if (t != NULL) {
            POSTORDER_travl(t->left);
            POSTORDER_travl(t->right);
            cout << t->sbd << " " << t->hoTen << endl;
        }
    }

    void heapify(Node** arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left]->sbd < arr[largest]->sbd)
            largest = left;

        if (right < n && arr[right]->sbd < arr[largest]->sbd)
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapsort(Node** arr, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

private:
    Node* root;

    void makeEmpty(Node*& t) {
        if (t != NULL) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = NULL;
    }

    void insert(int sbd, string hoTen, Node*& t) {
        if (t == NULL)
            t = new Node(sbd, hoTen);
        else if (sbd < t->sbd)
            insert(sbd, hoTen, t->left);
        else if (sbd > t->sbd)
            insert(sbd, hoTen, t->right);
    }

    Node* search(int sbd, Node* t) {
        if (t == NULL || t->sbd == sbd)
            return t;
        else if (sbd < t->sbd)
            return search(sbd, t->left);
        else
            return search(sbd, t->right);
    }
};

int main() {
    BSTree bst;

    bst.insert(9, "Tuan");
    bst.insert(6, "Lan");
    bst.insert(3, "Cong");
    bst.insert(8, "Huong");
    bst.insert(7, "Binh");
    bst.insert(4, "Hai");
    bst.insert(2, "Son");

    Node* n1 = bst.search(4);
    Node* n2 = bst.search(9);

    if (n1 != NULL)
        cout << "Sinh vien voi SBD=4 la " << n1->hoTen << endl;
    if (n2 == NULL)
        cout << "Khong tim thay sinh vien voi SBD=9" << endl;
        
	//lam rong cay
    bst.makeEmpty();

    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;

    return 0;
}
