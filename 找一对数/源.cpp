#include<iostream>
#include<cstdio>
#include<algorithm>//包含了排序的库函数
using namespace std;
int main() {
	int n;
	int m; 
	int A[100000];
	cin >> n;
	for(int i=0;i<n;i++)cin >> A[i];
	sort(A, A + n);
	cin >> m;
	int i = 0, j = n - 1;
	while (i <=j) {
		if (A[i] + A[j] > m)j--;
		if (A[i] + A[j] < m)i++;
		if (A[i] + A[j] == m) {

			cout << A[i] << " " << A[j] << endl;
			i++; j--;
		}
	}
	return 0;
}