#include<iostream>
#include<algorithm>
using namespace std;
void AllRange(int* ptr, int k, int m) {   //k��ʾ��ǰѡ���ڼ�������m��ʾ�ܹ������� 
	if (k >= m) {
		for (int i = 0; i < m; i++) {   //����һ��ֱ����� 
			
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
			swap(*(ptr + k), *(ptr + i));  //���� 
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
