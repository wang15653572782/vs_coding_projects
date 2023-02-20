#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool cmp1(int a, int b) {
	return a < b;
}
int tian[10010], king[10010];
int main() {
	int n;
	while (scanf_s("%d", &n) && n) {
		memset(tian, 0, sizeof(tian));
		memset(king, 0, sizeof(king));
		int i;
		for (i = 0; i < n; i++) scanf_s("%d", &tian[i]);
		for (i = 0; i < n; i++) scanf_s("%d", &king[i]);
		sort(tian, tian + n, cmp1);
		sort(king, king + n, cmp1);
		int ans = 0;
		int max1 = n - 1, max2 = n - 1, min1 = 0, min2 = 0, cnt = 0;
		while ((cnt++) < n) {
			if (tian[max1] > king[max2]) {
				ans = ans + 200;
				max1--;
				max2--;
			}
			else if (tian[max1] < king[max2]) {
				ans = ans - 200;
				max2--;
				min1++;
			}
			else {
				if (tian[min1] > king[min2]) {
					ans = ans + 200;
					min1++;
					min2++;
				}
				else {
					if (tian[min1] < king[max2]) {
						ans = ans - 200;
						min1++;
						max2--;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}