#include<iostream>
#include<algorithm>
using namespace std;
#define Lmax 300
int W[Lmax] = { 0 }; int X[Lmax] = { 0 };
int n, M;
int flag = 0; 
void Sort(int* W, int* copy, int n) {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < n; ++j) {
			if (W[j] > W[j + 1]) {
				int temp1, temp2;
				temp1 = W[j];
				temp2 = copy[j];
				W[j] = W[j + 1];
				copy[j] = copy[j + 1];
				W[j + 1] = temp1;
				copy[j + 1] = temp2;
			}
		}
}
void prit(int* X) {
	int k = 1; int F[Lmax];
	for (int i = 1; i <= n; ++i) {
		if (X[i] == 1)F[k++] = i;
	}
	for (int i = 1; i < k; ++i) {
		if (i == k - 1) {
			cout << F[i]<<"\n"; break;
		}
		else {
			cout << F[i] << " ";
		}
	}
}
void FIFO(int s, int k, int r) {
	if (k > n)return;
	if (s + W[k] == M) {
		X[k] = 1;
		flag = 1;
		prit(X);
		X[k] = 0;
		return;
	}
	if (s + r >= M && s + W[k] <= M) {
		X[k] = 1;
		FIFO(s + W[k], k + 1, r - W[k]);
		X[k] = 0;
	}
	if (r + s - W[k] >= M) {
		X[k] = 0;
		FIFO(s, k + 1, r - W[k]);
	}
}

int main() {
	int r = 0;
	cin >> n >> M;

	for (int i = 1; i <= n; ++i) {
		cin >> W[i]; r += W[i]; X[i] = i;
	}
	Sort(W, X, n);
	//for (int i = 1; i <= n; ++i)cout << W[i]<<" "<<copy[i]<<" ";
	FIFO(0, 1, r);
	if (flag == 0)cout << "no solution!" << endl;
	return 0;
}