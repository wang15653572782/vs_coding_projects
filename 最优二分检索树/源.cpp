#include<iostream>
#include<algorithm>
using namespace std;
#define size  100
int R[size][size];
void OBST(int n, double* P, double* Q) {
	double C[size][size], W[size][size];
	for (int i = 0; i < n; ++i) {
		W[i][i] = Q[i]; R[i][i] = 0; C[i][i] = 0;
		W[i][i + 1] = Q[i] + Q[i + 1] + P[i + 1]; R[i][i + 1] = i + 1; C[i][i + 1] = Q[i] + Q[i + 1] + P[i + 1];
	}
	W[n][n] = Q[n]; R[n][n] = 0; C[n][n] = 0;
	
	for (int m = 2; m <= n; ++m) {
		for (int i = 0; i <= n - m; ++i) {
			int j = i + m; W[i][j] = W[i][j - 1] + P[j] + Q[j];
			int k = R[i][j - 1];
			double tmp = 999999999;
			for (int z = R[i][j - 1]; z <= R[i + 1][j]; ++z) {
				if (C[i][z - 1] + C[z][j] < tmp) {
					tmp = C[i][z - 1] + C[z][j];
					k = z;
				}
			}

			C[i][j] = W[i][j] + C[i][k - 1] + C[k][j];
			R[i][j] = k; 
		}
	}
}
void preorder(int R[size][size], int i, int j) {
	int r = R[i][j];
	if (r <= 0)return;
	cout << r << " ";
	preorder(R, i, r - 1);
	preorder(R, r, j);
}
int main() {
	int n;
	cin >> n;
	
	double P[size], Q[size];
	for (int i = 1; i <= n; ++i)cin >> P[i];
	for (int i = 0; i <= n; ++i)cin >> Q[i];
	OBST(n, P, Q);
	preorder(R, 0, n);
	/*for (int i = 0; i <= n; ++i) {
 for(int j=0;j<=n;++j)
		cout << R[i][j];
 cout << "\n";
	}*/
   
}