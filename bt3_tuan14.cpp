#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Vun dong
void vunDong(int arr[], int n, int i) {
    int max = i; // Khoi tao phan tu lon nhat la goc
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[max])
        max = left;

    if (right < n && arr[right] > arr[max])
        max = right;

    if (max != i) {
        swap(arr[i], arr[max]);
        vunDong(arr, n, max);
    }
}

// Thu tu truoc
void duyetTruoc(int arr[], int n, int i) {
    if (i < n) {
        cout << arr[i] << " ";
        duyetTruoc(arr, n, 2 * i + 1);
        duyetTruoc(arr, n, 2 * i + 2);
    }
}

// Thu tu giua
void duyetGiua(int arr[], int n, int i) {
    if (i < n) {
        duyetGiua(arr, n, 2 * i + 1);
        cout << arr[i] << " ";
        duyetGiua(arr, n, 2 * i + 2);
    }
}

// Thu tu sau
void duyetSau(int arr[], int n, int i) {
    if (i < n) {
        duyetSau(arr, n, 2 * i + 1);
        duyetSau(arr, n, 2 * i + 2);
        cout << arr[i] << " ";
    }
}

// sap xep vun dong theo thu tu truoc
void sapXepVunDong_duyetTruoc(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        vunDong(arr, n, i);

    cout << "Cay sau khi vun dong theo thu tu truoc: ";
    duyetTruoc(arr, n, 0);
    cout << endl;

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        vunDong(arr, i, 0);

        cout << "\tCay o buoc " << n - i << ": ";
        duyetTruoc(arr, i, 0);
        cout << endl;
    }
}

int main() {
	int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    int arr[n];
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Cay ban dau theo thu tu truoc: ";
    duyetTruoc(arr, n, 0);
    cout << endl;

    sapXepVunDong_duyetTruoc(arr, n);

    cout << "Mang da sap xep: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;


    cout << "Cay da sap xep theo thu tu giua: ";
    duyetGiua(arr, n, 0);
    cout << endl;

    cout << "Cay da sap xep theo thu tu sau: ";
    duyetSau(arr, n, 0);
    cout << endl;

    return 0;
}
