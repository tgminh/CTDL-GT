#include<iostream>
using namespace std;
#define Max 100 
struct Stack 
{
    int Top;  
    int Data[Max];
};
void Init(Stack* S) 
{
    S->Top = -1;

int Isempty(Stack S) 
{
    return (S.Top == -1);
}
int Isfull(Stack S) 
{
    return (S.Top == Max - 1);
}

void Push(Stack& S, int x)
{
    if (Isfull(S))
        cout << "\nNgan xep day!" << endl;
    else {
        S.Top++;
        S.Data[S.Top] = x;
    }
}
int Pop(Stack& S) 
{
    if (Isempty(S)) 
    {
        cout << "\nNgan xep rong!" << endl;
        return -1;  // Gia tri tra ve khi rong
    } else {
        int x = S.Data[S.Top];
        S.Top--;
        return x;
    }
}

void Input(Stack& S) 
{
    cout << "\nNhap gia tri (0 de ket thuc nhap): " << endl;
    int x;
    do {
        cin >> x;
        if (x != 0)
            Push(S, x);
    } while (x != 0);
}
void Output(Stack S) 
{
    while (!Isempty(S))
        cout << "  " << Pop(S);
}
void PrintStack(Stack S) 
{
    cout << "Trang thai cua Stack: ";
    for (int i = 0; i <= S.Top; i++) {
        cout << S.Data[i] << " ";
    }
    cout << endl;
}

int main() 
{
    Stack s;
    Init(&s);  // Khoi tao ngan xep

    int A[10] = {73, 89, 96, 99, 60, 55, 52, 66, 67, 79};
    for (int i = 0; i < 10; i++) {
        if (A[i] < A[0] && A[i] % 2 == 0) {
            if (!Isempty(s)) Pop(s);
        } else {
            if (!Isfull(s)) Push(s, A[i]);
        }
    }

    PrintStack(s);  // Goi ham in noi dung stack
    return 0;
}

