#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int dist(char* S, char* P) {
	int m = strlen(S);
	int n = strlen(P);
	char s[17], p[17];
	for (int i = 1; i < m + 1; ++i)s[i] = S[i - 1];
	for (int i = 1; i < n + 1; ++i)p[i] = P[i - 1];
	int Dist[16][16] = { 0 };
	for (int i = 0; i <= m; ++i)Dist[i][0] = i; 	
	for (int j = 0; j <= n; ++j)Dist[0][j] = j;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j) {
			if (s[i] == p[j])Dist[i][j] = Dist[i - 1][j - 1];
			else {
				int a = min(Dist[i - 1][j - 1], Dist[i][j - 1]);
				int b = min(a, Dist[i - 1][j]);
				Dist[i][j] = b + 1;
			}
		}
	return Dist[m][n];
}
int main() {
	char s[16], p[16];
	cin >> s>> p;
	
	cout << dist(s, p) << endl;
	return 0;
}