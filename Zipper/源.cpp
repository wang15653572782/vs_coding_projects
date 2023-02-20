#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define max 201
bool dp[max][max];//dp[i][j]表示s1的前i个字符和s2的前j个字符构成了s3的i+j个字符
char s1[max], s2[max], s3[max * 2];
int main() {
	int n;
	cin >> n;
	int m = 1;
	while (m <= n) {
		cin >> s1 + 1 >> s2 + 1 >> s3 + 1;
		dp[0][0] = true;
		int L1 = strlen(s1 + 1);
		int L2 = strlen(s2 + 1);
		for (int i = 1; i <= L1; ++i) {
			if (dp[i - 1][0] && s1[i] == s3[i])dp[i][0] = true;
			else dp[i][0] = false;
		}
		for (int i = 1; i <= L2; ++i) {
			if (dp[0][i - 1] && s2[i] == s3[i])dp[0][i] = true;
			else dp[0][i] = false;
	 }
for(int i=1;i<=L1;++i)
for (int j = 1; j <= L2; ++j) {
	if ((dp[i - 1][j] && s1[i] == s3[i + j]) || (dp[i][j - 1] && s2[j] == s3[i + j]))
		dp[i][j] = true;
	else dp[i][j] = false;
}
cout << "Data set " << m++ << ":" << (dp[L1][L2] ? "yes" : "no") << endl;
	}
	return 0;
}