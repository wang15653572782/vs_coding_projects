#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const double eps = 1e-6;
struct Candy {
	int v;int w;
	int flag = 0;
	bool operator < (const Candy& c) const
	{
		return double(v) / w - double(c.v) / c.w > eps;
	}
} candies[110];
int Ssearch(struct Candy candies[],struct Candy a,int n) {
	for (int i = 0; i < n; ++i) {
		if (candies[i].v == a.v && candies[i].w == a.w)return i;
	}
	return 0;
};
int main() {
	struct Candy copy[110];
	int n, w;
	scanf_s("%d%d",&w, &n);
	for (int i = 0; i < n; ++i) {
		scanf_s("%d", &candies[i].w);
		copy[i].w = candies[i].w;
	}
	for (int i = 0; i < n; ++i) {
scanf_s("%d", &candies[i].v);
copy[i].v = candies[i].v;
	}	
	sort(candies, candies + n);
	int totalW = 0;
	float s=0;
	double totalV = 0;
	for (int i = 0; i < n; ++i) {
		if (totalW + candies[i].w <= w) {
			candies[i].flag = 1;
			totalW += candies[i].w;
			totalV += candies[i].v;
		}
		else {
			candies[i].flag = 2;
			
			totalV += candies[i].v *double(w - totalW) / candies[i].w;
			 s=double(w - totalW)/candies[i].w;
			break;
		}
	}
	cout<<totalV<<endl;
	int j;
	for (int i = 0; i < n; ++i) {
		j = Ssearch(candies, copy[i], n);
		if (candies[j].flag == 0) cout << "0.00 ";
		if (candies[j].flag == 1)cout << "1.00 ";
		if (candies[j].flag == 2)printf("%.2f ", s);
	}
	return 0;
}