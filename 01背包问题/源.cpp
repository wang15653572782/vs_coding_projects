#include<iostream>
#include<algorithm>
using namespace std;
int F[10000][10000];
int main() {
	int M,n;

	int W[10000], P[10000];
	cin >> M >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> W[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> P[i];
	}
	//for (int i = 0; i <= M; ++i)F[0][i] = 0;
	int flag[1000]={0}; int m=0;
	for(int i=1;i<=n;++i)
		for (int j = 1; j <= M; ++j) {
			if (j >= W[i]) {
				F[i][j] = max(F[i - 1][j], F[i - 1][j - W[i]] + P[i]);
				
				
			}
			else {

				F[i][j] = F[i - 1][j];
			}
		}
	
	F[0][M] = 0;
	int s = n;
	int e = M;
	while (s >= 0) {
		if (F[s][e]>F[s - 1][e]) {
			flag[s] = 1; m += W[s]; s--; e -= W[s + 1];
		}
		else {
			s--;
		}
		
}
	cout << F[n][M]<<" "<<m<<endl;
	for (int i = 1; i <n; ++i) {
		if (flag[i] == 1)cout << "1 ";
		else cout << "0 ";
	}
	if (flag[n] == 1)cout << 1;
	else cout << 0;
	return 0;
}