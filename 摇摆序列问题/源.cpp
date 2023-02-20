#include<iostream>
#include<algorithm>
using namespace std;
int a[1000]; int maxLen[1000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i]; maxLen[i] = 1;
	}
	int flag = 0;
	if (a[0] > a[1])flag = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (j == 0 && a[j] != a[i]) {
				maxLen[i] = max(maxLen[i], maxLen[j] + 1);
			}
			if (j>=1&&(a[i]-a[j])*(a[j]-a[j-1])<0) {
				maxLen[i] = max(maxLen[i], maxLen[j] + 1);
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; ++i) {
		if (maxLen[i] > max)max = maxLen[i];
	}
	cout << max;
	return 0;


}