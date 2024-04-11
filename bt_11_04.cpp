#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int isPrime(int n)
{
int count = 0;
for (int i = 2; i <= n; i++)
if (n % i == 0) count++;
if (count == 1) return 1;
else return 0;
}
int isBlum(int n) {
int count = 1;
for (int i = 2; i < sqrt(n); i++)
{
if (isPrime(i) && isPrime(n / i) && (i * (n / i) == n))
{
cout << n << " la so Blum: " << n << " = " << i << "*" << n / i << endl;
count++;
}
}
if (count == 1) cout << n << " khong phai so Blum" << endl;
return count;
}
vector<int> generateBlumNumbers(int N) {
    vector<int> blumNumbers;
    for (int i = 2; i <= N; i++) {
        if (isBlum(i)) blumNumbers.push_back(i);
    }
    return blumNumbers;
}
void printBlumPairs(vector<int> blumNumbers) {
    for (int i = 0; i < blumNumbers.size(); i++) {
        for (int j = i; j < blumNumbers.size(); j++) {
            int sum = blumNumbers[i] + blumNumbers[j];
            if (isBlum(sum)) cout << "(" << blumNumbers[i] << ", " << blumNumbers[j] << ")" << endl;
        }
    }
}
bool checkBlumNumber(vector<int> blumNumbers, int M) {
    for (int i = 0; i < blumNumbers.size(); i++) {
        if (blumNumbers[i] == M) return true;
    }
    return false;
}

int main() {
    int N, M;
    cout << "Nhap so N: ";
    cin >> N;
    vector<int> blumNumbers = generateBlumNumbers(N);
    printBlumPairs(blumNumbers);
    cout << "Nhap so M: ";
    cin >> M;
    if (checkBlumNumber(blumNumbers, M)) cout << M << " la so Blum." << endl;
    else cout << M << " khong phai la so Blum." << endl;
    return 0;
}
