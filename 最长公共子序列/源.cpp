#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 1000
int MaxLen[MAX][MAX];
int main() {
	char s1[MAX], s2[MAX];
	while (cin >> s1 >> s2) {
int S1 = strlen(s1);
	int S2 = strlen(s2);
	for (int i = 0; i <=S1; i++)MaxLen[i][0] = 0;
	for (int j = 0; j <= S2; j++)MaxLen[0][j] = 0;
	for(int i=1;i<=S1;i++)
		for (int j = 1; j <= S2; j++) {
			if (s1[i - 1] == s2[j - 1])MaxLen[i][j]=MaxLen[i - 1][j - 1] + 1;
			else MaxLen[i][j] = max(MaxLen[i][j - 1], MaxLen[i - 1][j]);

		}
	cout << MaxLen[S1][S2] << endl;
	}
	
	return 0;

}