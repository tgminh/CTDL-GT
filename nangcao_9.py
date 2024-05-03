#include <string>
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};
struct List{
    Node* head;
};
void Insert(List &list, int data){
    Node* temp = new Node;
    temp->data = data;
    if (list.head == NULL){ 
        list.head = temp;
        temp->next = list.head;
        temp->prev = list.head;
    }
    else{
        Node* temp2 = list.head;
        while(temp2->next != list.head){
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->next = list.head;
        temp->prev = temp2;
        list.head->prev = temp;
    }
}
void Print(List list){
    Node* temp = list.head;
    cout << temp->data << " ";
    while (temp->next != list.head){
        temp = temp->next;
        cout << temp->data << " ";
    }
}
void altPrint(List list){
    Node* temp = list.head;
    Node* temp2 = temp->prev;
    cout << temp2->data << " "; 
    while (temp2 != list.head){
        temp2 = temp2->prev;
        cout << temp2->data << " ";
    }
    cout << endl;
}
void Delete(Node* node, List &list){
    if (node == list.head){
        list.head = node->next;
        list.head->prev = node->prev;
        node->prev->next = list.head;
        delete node;
    }
    else{
        Node* temp = node;
        node->prev->next = temp->next;
        node->next->prev = temp->prev;
        delete temp;
    }
}
int JosephusProblem(int N, int M){
    List List;
    List.head = NULL;
    for (int i = 1; i <= N; i++){
        Insert(List,i);
    }
    Node* temp = List.head;
    while (List.head != List.head->next) { 
        for (int i = 1; i <= M; i++) { 
            temp = temp->next;
        }
        Node* nextPerson = temp->next; 
        Delete(temp, List); 
        temp = nextPerson; 
    }
    return List.head->data; 
}

int main(){
    cout << JosephusProblem(41,1);
}
