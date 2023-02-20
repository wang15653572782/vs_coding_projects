#include<iostream>
#include<algorithm>
using namespace std;
void AllRange(int* ptr, int k, int m) {   //k表示当前选到第几个数，m表示总共几个数 
	if (k >= m) {
		for (int i = 0; i < m; i++) {   //找完一组直接输出 
			
			if (i == m - 1)cout << *(ptr + i) << endl;
			else {
         cout << *(ptr + i)<<' ';
		 
			}
		}
		
	}
	else {
		for (int i = k; i < m; i++) {
			swap(*(ptr + k), *(ptr + i));
			AllRange(ptr, k + 1, m);
			swap(*(ptr + k), *(ptr + i));  //回溯 
		}
	}
}
int main() {
	int a[10];
	for (int i = 0; i < 10; i++)a[i] = i + 1;
	int n;
	while (1) {
		cin >> n;
		if (n == 0)break;

AllRange(a, 0, n);
	}
	
}
