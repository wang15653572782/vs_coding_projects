#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	char a[15000];
	int n = 0;
	cin >> a;
	int len = strlen(a);
	int s = 0;
	int b[5000];
	for (int i = 0; i < len; ++i) {
		if (a[i] >= '0' && a[i] <= '9')b[s++] = a[i]-48;
	}
	int tmp, num = 0;
	for (int i = 0; i < s; ++i) {
		if (num == 0) {
			tmp = b[i]; num++;
		}
		else if (tmp == b[i])num++;
		else num--;
	}
	int times=0;
	for (int i = 0; i < s; ++i) {
		if (b[i] == tmp)times++;
	}
	if (times > s / 2)cout << tmp;
	else cout << "NA";
	return 0;
}