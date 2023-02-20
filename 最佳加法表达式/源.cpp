#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define max 0x3f3f3f3f
int a[100]; int num[100][100]; int V[100][100];
int main() {
	int n,m;
	
	cin >> n>>m;
	
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) {
		num[i][i] = a[i];
for (int j = i + 1; j <= n; j++) {
	num[i][j] = num[i][j - 1] * 10 + a[j];
	
		}
	}
	memset(V, 0x3f, sizeof(V));

	for (int i = 1; i <= n; i++)V[0][i] = num[1][i];
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= n; j++)
			for (int k = i; k <= j; k++)
				V[i][j] = min(V[i][j], V[i - 1][k] + num[k + 1][j]);
	cout << V[m][n] << endl;
	return 0;
}