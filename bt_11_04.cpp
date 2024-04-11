#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int PrimeCheck(int n) {//kiem tra SNT
    int count = 0;
    for (int i = 2; i <= n; i++)
        if (n % i == 0) count++;
    if (count == 1) return 1;
    else return 0;
}

int BlumCheck(int n) { //Kiem tra so Blum
    int count = 1;
    for (int i = 2; i < sqrt(n); i++) {
    if (PrimeCheck(i) && PrimeCheck(n / i) && (i * (n / i) == n))
    {
        cout << n << " la so Blum: " << n << " = " << i << "*" << n / i << endl;
        count++;
    }
    }
    if (count == 1) cout << n << " khong phai so Blum" << endl;
    return count;
}

vector<int> BlumArray(int N) { //tao ra mang cac so blum nho hon N
    vector<int> blum_array;
    for (int i = 2; i < N; i++) {
        if (BlumCheck(i)) blum_array.push_back(i);
    }
    return blum_array;
}

void BlumPairs(const vector<int> blum_array, int N) { // tim cac cap so blum co tong la so blum nho hon N
    cout << "Tat ca cac cap so Blum co tong cung la mot so Blum nho hon " << N << " la:\n";
    for (int i = 0; i < blum_array.size(); i++) {
        for (int j = i; j < blum_array.size(); j++) {
            int sum = blum_array[i] + blum_array[j];
            if (BlumCheck(sum)) cout << "(" << blum_array[i] << ", " << blum_array[j] << ")" << endl;
        }
    }
}

bool BlumInclude(const vector<int>& blum_array, int M) { //kiem tra so M thuoc day 'blum_array' hay khong
    for (int i = 0; i < blum_array.size(); i++) {
        if (blum_array[i] == M) return true;
    }
    return false;
}

int main() {
    int N, M;
    cout << "Nhap so N: ";
    cin >> N;
    vector<int> blum_array = BlumArray(N);
    BlumPairs(blum_array, N);
    cout << "Nhap so M: ";
    cin >> M;
    if (BlumInclude(blum_array, M)) cout << M << " la so Blum." << endl;
    else cout << M << " khong phai la so Blum." << endl;
    return 0;
}
