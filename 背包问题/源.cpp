#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int w[3500];
int d[3500];
int f[13300] = { 0 };//�� F[i][j] ��ʾȡǰi����Ʒ��ʹ���������������j������
//ȡ��ȡ�õļ�ֵ�ܺ͡�
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