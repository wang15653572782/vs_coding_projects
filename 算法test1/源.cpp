#include<iostream>
using namespace std;
int a[10000]; int b[10000];
int s = 0;
bool knap(int m, int n) {
	if (a[n - 1] == m) {
		b[s++] = a[n - 1]; return true;
	}
	if (a[n - 1] < m) {
		if (n > 0) {
			if (knap(m - a[n - 1], n - 1)) {
				b[s++] = a[n - 1]; return true;
			}
			else return knap(m, n - 1);
		}
		else return false;
	}
	if (a[n - 1] > m) {
		if (n > 0)return knap(m, n - 1);
		else return false;
	}
}
int main() {
	int m, n;

	cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (knap(m, n)==true) {
		
		for (int i = 0; i < s - 1; ++i)cout << b[i] << ' ';
		cout << b[s - 1];
	}
	else cout << 0;
	return 0;
}