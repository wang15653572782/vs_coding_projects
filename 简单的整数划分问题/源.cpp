//n = m1 + m2 + … + mi;
//
//根据n和m的关系，考虑以下几种情况：
//
//(1)当n = 1时，不论m的值为多少（m > 0)，只有一种划分即{ 1 };
//
//(2)当m = 1时，不论n的值为多少，只有一种划分即n个1，{ 1,1,1,…,1 };
//
//(3)当n = m时，根据划分中是否包含n，可以分为两种情况：
//(a)划分中包含n的情况（它本身为一种情况）
//(b)划分中不包含n的情况，这时划分中最大的数字也一定比n小，即n的所有(n - 1)划分。
//
//(4)当n < m时，由于划分中不可能出现负数，因此就相当于f(n, n);
//
//(5)但n > m时，根据划分中是否包含最大值m，可以分为两种情况：（难理解！！！www举个例子比较好懂呜呜呜 ）
//
//(a)划分中包含m的情况，即 {
//	m, { x1,x2,…xi }
//} 其中{ x1,x2,… xi } 的和为n - m
//（（我觉得这样理解比较好：m + x1 + x2 + … + xi））
//
//(b)划分中不包含m的情况，则划分中所有值都比m小，即n的(m - 1)划分，个数为f(n, m - 1);
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int f(int n,int m) {//在最大加数ni不大于m
	if (n == 1)return 1;
	if (m==1)return 1;
	int result = 0;
	if (n == m) return 1 + f(n, n - 1);
	if (n < m)return f(n, n);
	if(n>m)return f(n - m, m) + f(n, m - 1);
}
int main() {
	int n;
	while (scanf_s("%d", &n) != EOF) {
		printf("%d\n", f(n,n));
	}
	return 0;
}