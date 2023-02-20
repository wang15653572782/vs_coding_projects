#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int w[3500];
int d[3500];
int f[13300] = { 0 };//用 F[i][j] 表示取前i种物品，使它们总体积不超过j的最优
//取法取得的价值总和。
int main() {
	int n, m;
	cin >> n >> m;
	int i = 1;
	while (i <= n) {
		cin >> w[i] >> d[i];
		++i;
	}
	f[0] = 0;
	for(int i=1;i<=n;++i)
		for (int j = m; j>=w[i]; --j) {
			if (f[j - w[i]] + d[i] > f[j])f[j] = f[j - w[i]] + d[i];
		}
	cout << f[m] <<endl;
	return 0;
}