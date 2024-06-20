#include <iostream>
#include <string>
 using namespace std;
 
struct TreeNode {
    int index;
    string title;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int idx, string t) : index(idx), title(t), left(NULL), right(NULL) {}
};

bool areIdentical(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    return (root1->index == root2->index && root1->title == root2->title &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right));
}

int main() {
    TreeNode* root1 = new TreeNode(1, "Chapter 1");
    root1->left = new TreeNode(2, "Section 1.1");
    root1->right = new TreeNode(3, "Section 1.2");

    TreeNode* root2 = new TreeNode(1, "Chapter 1");
    root2->left = new TreeNode(2, "Section 1.1");
    root2->right = new TreeNode(3, "Section 1.2");

    if (areIdentical(root1, root2)) {
        cout << "Hai cuon sach là ban copy cua nhau" << endl;
    } else {
        cout << "Hai cuon sach khong phai la ban copy cua nhau" << endl;
    }

    delete root1->left;
    delete root1->right;
    delete root1;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
