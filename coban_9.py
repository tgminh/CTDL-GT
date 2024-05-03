#include <string>
#include <iostream>
using namespace std;

struct Ngay{
    int ngay, thang, nam;
};
struct SinhVien{
    int maSV;
    char hoTen[50];
    char gioiTinh[5];
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};
struct Node{
    SinhVien data;
    Node *link;
};
struct List{
    Node *first = NULL;
};

void Insert(List &list) //Phuong tŕnh nhap phan tu vào linked list
{
    Node* temp = new Node();
    cout << "Nhap thong tin sinh vien moi: \n";

    cout << "   Ho va ten: ";
    cin.getline(temp->data.hoTen,50);

    cout << "   Ma SV: ";
    cin >> temp->data.maSV;
    cin.ignore();

    cout << "   Gioi tinh: ";
    cin.getline(temp->data.gioiTinh,5);

    cout << "   Ngay thang nam sinh: ";
    cin >> temp->data.ngaySinh.ngay >> temp->data.ngaySinh.thang >> temp->data.ngaySinh.nam;
    cin.ignore();

    cout << "   Dia chi: ";
    cin.getline(temp->data.diaChi,100);

    cout << "   Lop: ";
    cin.getline(temp->data.lop,12);

    cout << "   Khoa: ";
    cin.getline(temp->data.khoa,7);

    if (list.first == NULL){
        temp->link = list.first;
        list.first = temp;
    }
    else{
        Node* temp2 = list.first;
        while (temp2->link != NULL){
            temp2 = temp2->link;
        }
        temp2->link = temp;
        temp->link = NULL;
    }

}

int numberOfElement (List List) {
    int i = 1;
    Node* temp = List.first;
    while(temp->link != NULL){
        i++;
        temp = temp->link;
    }
    return i;
}

int studentIDIndexing(List List, int i){
        Node* temp = List.first;
        int a = 0;
        while (a < i)
        {
            temp = temp->link;
            a++;
        }
        return temp->data.maSV;
}

void swapNodesFromPos (List List, int a, int b){
    int i = 0;
    int j = 0;
    Node* temp1 = List.first;
    Node* temp2 = List.first;
    while (i < a)
    {
        temp1 = temp1->link;
        i++;
    }
    while (j < b)
    {
        temp2 = temp2->link;
        j++;
    }
    SinhVien temp = temp1->data;
    temp1->data = temp2->data;
    temp2->data = temp;
}

void Print(List list){
    Node* temp = list.first;
    cout << "\nDanh sach sinh vien: \n";
    while (temp!= NULL)
    {
        cout << "   Ma SV: " << temp->data.maSV << '\n';
        cout << "   Ho va ten: " << temp->data.hoTen << '\n';
        cout << "   Gioi tinh: "<< temp->data.gioiTinh << '\n';
        cout << "   Ngay thang nam sinh: "<< temp->data.ngaySinh.ngay << '\\'  <<temp->data.ngaySinh.thang <<  '\\'  << temp->data.ngaySinh.nam << '\n';
        cout << "   Dia chi: "<< temp->data.diaChi << '\n';
        cout << "   Lop: "<< temp->data.lop << '\n';
        cout << "   Khoa: "<< temp->data.khoa << '\n';
        temp = temp->link;

        cout << "\n";
    }
} 

void selectionSort(List List, int n){
    for (int i = 0; i < n-1; i++){
        int minPos = i;
        for (int j = i+1; j < n; j++){
            if (studentIDIndexing(List, j) < studentIDIndexing(List, minPos)){
                minPos = j;
            }
        }
        if (i != minPos){
            swapNodesFromPos(List, i, minPos);
        }
    }
}

void printAndRemoveDuplicates(List &list){
    Node* temp1 = list.first;
    Node* dup;
    while (temp1->link != NULL){
        cout << "Ngay sinh: " << temp1->data.ngaySinh.ngay << "/" << temp1->data.ngaySinh.thang << "/" << temp1->data.ngaySinh.nam << " ";
        cout << temp1->data.hoTen << " ";
        Node* temp2 = temp1;
        while (temp2->link != NULL){
            if (temp1->data.ngaySinh.ngay == temp2->link->data.ngaySinh.ngay && temp1->data.ngaySinh.thang == temp2->link->data.ngaySinh.thang && temp1->data.ngaySinh.nam == temp2->link->data.ngaySinh.nam)
            {
                cout << temp2->link->data.hoTen << " ";
                dup = temp2->link;
                temp2->link = temp2->link->link;
                delete(dup);
            }
            else temp2 = temp2->link;
        }
        cout << "\n";
        temp1 = temp1->link;
    }
}
int main(){
    List list;
    for (int i = 0; i < 5; i++){
        Insert(list);
    }
    printAndRemoveDuplicates(list);
    Print(list);

}
