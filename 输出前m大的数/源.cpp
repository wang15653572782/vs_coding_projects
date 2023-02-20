#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
void arrangeRight(int k,int a[],int s,int e) {
	int key = a[s];
	int i = s;
	int j = e;
	while (i != j) {
		while (i<j && a[j]>=key)j--;
		swap(a[i], a[j]);
		while (i < j && a[i] <= key)i++;
		swap(a[i], a[j]);
	}
	
	if ((e - i) == k - 1)return;
	if (e - i > k - 1)arrangeRight(k, a, i + 1, e);
	if (e - i < k - 1)arrangeRight(k-e+i-1, a, s, i - 1);

}
int main() {
	int n, m;

	cin >> n;
	int a[100000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	arrangeRight(m, a, 0, n - 1);
	sort(a + n - m , a + n);
	for (int i = n - 1; i > n - m -1; i--)cout << a[i] <<' ';
	return 0;
}