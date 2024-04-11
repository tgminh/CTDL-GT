#include<iostream>
#include<string>
using namespace std;
// ma hoa cac mau 
enum Color{DO = 0, TRANG = 1, XANH = 2};

void swap(Color& a, Color& b){
	Color temp = a;
	a = b;
	b = temp;
}
// sap xep
void bubbleSortColor(Color* color, int n){
	for (int i =0; i< n; i++){
		for (int j=0; j < n - 1 - i; j++){
			if(color[j] > color[j+1]){
				swap(color[j],color[j+1]);
			}
		}
	}
}
// ham chuyen doi so qua mau tuong ung
string numberToColor(Color color){
	switch(color){
		case 0:
			return "do_" ;
		case 1:
			return "trang";
		case 2:
			return "xanh";
		default:
			return "khong hop le";
}
}
int main() {
	Color color[] = {xanh,do_,xanh,do_,do_,trang,do_,xanh,trang};
	int n = sizeof(color) / sizeof(color[0]);
	bubbleSortColor (color, n);
	for(int i = 0; i <n; i++){
		cout << numberToColor(color[i]) << " ";
	}
	cout << endl;
	return 0;
}
