#include<iostream>
#include<algorithm>
#define MAX 101
using namespace std;
int D[MAX][MAX];
int n;
int *maxSum;
//int MaxSum(int i, int j) {
//	if (maxSum[i][j] != -1)return maxSum[i][j];
//	if (i == n)maxSum[i][j] = D[i][j];
//	else {
//    int x = MaxSum(i + 1, j);
//	int y = MaxSum(i + 1, j + 1);
//	maxSum[i][j] = max(x, y) + D[i][j];
//	}
//	
//	return maxSum[i][j];
//}
int main() {
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++) {
			cin >> D[i][j]; 
		}
	maxSum = D[n];
	for (int i = n - 1; i >= 1; i--)
		for (int j = 1; j <= i; j++)
			maxSum[j] = max(maxSum[j], maxSum[j + 1]) + D[i][j];
	cout <<maxSum[1]<< endl;
	return 0;
}