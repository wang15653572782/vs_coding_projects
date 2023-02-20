#include<iostream>
#include<algorithm>
using namespace std;
int a[26];
int main() {
	int k;
	int maxlen[26];
	cin >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> a[i]; maxlen[i] = 1;
	}
	for(int i=1;i<=k;++i)
		for (int j = i + 1; j <= k; ++j) {
			if (a[j] <= a[i])maxlen[j] = max(maxlen[j], maxlen[i] + 1);

		}
	cout << *max_element(maxlen + 1, maxlen + k + 1) << endl;
	return 0;
}