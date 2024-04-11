#include <iostream>
#include <vector>

using namespace std;

void swap(vector<string>& arr, int i, int j) {
    string temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void dutchflag_quicksort(vector<string>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high) {
        if (arr[mid] == "Xanh") {
            swap(arr, low, mid);
            low++;
            mid++;
        } else if (arr[mid] == "Do") {
            mid++;
        } else {
            swap(arr, mid, high);
            high--;
        }
    }
}

void print_array(const vector<string>& arr) {
    for (const string& color : arr) {
        cout << color << " ";
    }
    cout << endl;
}

vector<string> combine(const vector<string>& arr1, const vector<string>& arr2) {
    vector<string> merged;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == "Xanh" || (arr1[i] == "Do" && arr2[j] == "Trang")) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }
    return merged;
}


int main() {
    vector<string> arr1, arr2;
    int n,m;
    cout << "Mang 1:" << endl;
    cout << "   Nhap so phan tu cua mang: ";
    cin >> n;
    for(int i=0; i<n; i++){
        string color;
        cout << "   Nhap phan tu mau thu " << i << ":";
        cin >> color;
        arr1.push_back(color);
    }
    
    cout << "Mang 2:" << endl;
    cout << "   Nhap so phan tu cua mang: ";
    cin >> m;
    for(int i=0; i<m; i++){
        string color;
        cout << "   Nhap phan tu mau thu " << i << ":";
        cin >> color;
        arr2.push_back(color);
    }

    dutchflag_quicksort(arr1);
    cout << "Mang 1 sau khi sap xep: " << endl;
    print_array(arr1);
    
    dutchflag_quicksort(arr2);
    cout << "Mang 2 sau khi sap xep: " << endl;
    print_array(arr2);

    cout << "Tron 2 mang co sap xep:" << endl;
    print_array(combine(arr1,arr2));
    return 0;
}
