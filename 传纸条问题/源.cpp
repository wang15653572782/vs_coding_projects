#include <iostream> 
#include <algorithm>
using namespace std;
#define MAX 101 
int D[MAX][MAX];
int dp[MAX][MAX][MAX][MAX];
int main() {
	int i, j;
	int m, n;
	cin >>m>> n;
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			cin >> D[i][j];
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=m;++k)
				for (int l = 1; l <= n; ++l) {
					dp[i][j][k][l] = max(max(dp[i - 1][j][k - 1][l], dp[i - 1][j][k][l - 1]), max(dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l- 1])) + D[i][j] + D[k][l];
					if (i == k && j == l)dp[i][j][k][l] -= D[i][j];
				}
	cout << dp[m][n][m][n];
}
