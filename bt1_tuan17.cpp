#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    string type;          
    int index;           
    string name;          
    int page;             

    TreeNode* child;     
    TreeNode* sibling;   

    TreeNode(string t, int i, string n, int p) {
        type = t;
        index = i;
        name = n;
        page = p;
        child = NULL;
        sibling = NULL;
    }
};

TreeNode* findNode(TreeNode* root, string targetType, int targetIndex) {
    if (root == NULL) return NULL;
    if (root->type == targetType && root->index == targetIndex) {
        return root;
    }

    TreeNode* foundNode = findNode(root->child, targetType, targetIndex);
    if (foundNode != NULL) return foundNode;

    // T?m trong các sibling
    return findNode(root->sibling, targetType, targetIndex);
}

void deleteNode(TreeNode* root, string targetType, int targetIndex) {
    if (root == NULL) return;

    if (root->child != NULL && root->child->type == targetType && root->child->index == targetIndex) {
        TreeNode* temp = root->child;
        root->child = temp->sibling;
        delete temp;
        return;
    }

    TreeNode* current = root->child;
    TreeNode* prev = NULL;
    while (current != NULL && !(current->type == targetType && current->index == targetIndex)) {
        prev = current;
        current = current->sibling;
    }

    if (current != NULL) {
        prev->sibling = current->sibling;
        delete current;
    }

    deleteNode(root->child, targetType, targetIndex);
    deleteNode(root->sibling, targetType, targetIndex);
}

void printChapterContents(TreeNode* chapter) {
    if (chapter == NULL) return;
    
    TreeNode* current = chapter->child;
    while (current != NULL) {
        cout << current->name << endl;
        current = current->sibling;
    }
}

int countChapters(TreeNode* root) {
    if (root == NULL) return 0;

    int count = 0;
    TreeNode* current = root->child;
    while (current != NULL) {
        if (current->type == "chapter") {
            count++;
        }
        current = current->sibling;
    }
    return count;
}

TreeNode* findLongestChapter(TreeNode* root) {
    if (root == NULL) return NULL;

    TreeNode* longestChapter = NULL;
    int maxLength = 0;

    TreeNode* current = root->child;
    while (current != NULL) {
        if (current->type == "chapter" && current->page > maxLength) {
            maxLength = current->page;
            longestChapter = current;
        }
        current = current->sibling;
    }
    return longestChapter;
}

int main() {
    TreeNode* book = new TreeNode("book", 0, "Book Title", 0);
    
    TreeNode* chapter1 = new TreeNode("chapter", 1, "Chapter 1", 10);
    TreeNode* section1_1 = new TreeNode("section", 1, "Section 1.1", 15);
    TreeNode* section1_2 = new TreeNode("section", 2, "Section 1.2", 20);
    chapter1->child = section1_1;
    section1_1->sibling = section1_2;

    TreeNode* chapter2 = new TreeNode("chapter", 2, "Chapter 2", 18);
    TreeNode* section2_1 = new TreeNode("section", 1, "Section 2.1", 22);
    chapter2->child = section2_1;

    book->child = chapter1;
    chapter1->sibling = chapter2;

    cout << "Number of chapters: " << countChapters(book) << endl;

    TreeNode* longestChapter = findLongestChapter(book);
    if (longestChapter != NULL) {
        cout << "Longest chapter: " << longestChapter->name << " (pages: " << longestChapter->page << ")" << endl;
    }

    deleteNode(book, "section", 2);

    printChapterContents(chapter1);

    delete book;

    return 0;
}

