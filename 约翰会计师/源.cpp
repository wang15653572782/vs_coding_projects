//农夫约翰是一个精明的会计师。他意识到自己可能没有足够的钱来维持农场的运转了。
//他计算出并记录下了接下来 N(1 ≤ N ≤ 100, 000) 天里每天需要的开销。
//约翰打算为连续的M(1 ≤ M ≤ N) 个财政周期创建预算案，他把一个财政周期命名为fajo月。
//每个fajo月包含一天或连续的多天，每天被恰好包含在一个fajo月里。
//约翰的目标是合理安排每个fajo月包含的天数，使得开销最多的fajo月的开销尽可能少。
//输入
//第一行包含两个整数N, M，用单个空格隔开。
//接下来N行，每行包含一个1到10000之间的整数，按顺序给出接下来N天里每天的开销。
//输出
//一个整数，即最大月度开销的最小值。
//样例输入
//7 5
//100
//400
//300
//100
//500
//101
//400
#include<iostream>
#include<algorithm>
using namespace std;
#define max 100000
bool judge(int n, int m, int mid, int a[]) {
	int t = 0; int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + a[i] > mid) {
			sum = a[i];
			t++;
		}
		else {
			sum += a[i];
		}
	}
	if (t >= m)return true;
	else return false;
}
int main() {
	int n, m;
	cin >> n >> m;
	int a[max]; int sum = 0; int M=0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		if (a[i] > M)M = a[i];
	}
	int l = M, r = sum;
	int mid;
	while (l <= r) {
		 mid = l + (r - l) / 2;
		if (judge(n, m, mid, a))l = mid + 1;
		else r = mid - 1;
	}
	cout << mid << endl;
	return 0;
}