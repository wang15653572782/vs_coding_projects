#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
const int MAX_N = 27;
struct lake
{
	int f, d, id;
};
lake a[MAX_N];
int n, t, h, sum;
int dis[MAX_N], cou[MAX_N], c[MAX_N];
priority_queue<lake> q;
bool operator <(const lake& x, const lake& y)  //优先队列权值，优先级制定 
{
	if (x.f == y.f) return x.id > y.id;            //如果钓到的鱼一样多，ID的小的在前，否则鱼多的在前 
	else return x.f < y.f;
}
int main()
{
	lake node;
	scanf("%d", &n);
	while (n != 0) {
		scanf("%d", &h);
		h *= 12;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i].f);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i].d);
			a[i].id = i;
			dis[i] = 0;
		}
		for (int i = 1; i < n; i++) {
			scanf("%d", &dis[i]);
			dis[i] += dis[i - 1];            //路上花费的时间 
		}
		int max = -1;
		for (int i = 0; i < n; i++) {
			sum = 0;
			while (!q.empty()) q.pop();     //清空队列 
			for (int j = 0; j <= i; j++)
				q.push(a[j]);
			for (int j = 0; j < n; j++)
				cou[j] = 0;
			int hh = h - dis[i];		//剩余的时间 
			while (hh > 0) {
				node = q.top();
				q.pop();
				hh--;
				cou[node.id]++;       //记录在每个湖钓鱼的次数 
				sum += node.f;
				node.f -= node.d;
				if (node.f < 0) node.f = 0;     //证明已经没鱼了，不能为负，因为即使没鱼，也会继续钓，如果为负，已经钓到的鱼的数量就会减少
				q.push(node);
			}
			if (sum > max) {          //找到能钓到鱼最多的情况 
				max = sum;
				for (int j = 0; j < n; j++)
					c[j] = cou[j];
			}
		}
		for (int i = 0; i < n - 1; i++) {
			printf("%d, ", c[i] * 5);
		}
		printf("%d\n", c[n - 1] * 5);
		printf("Number of fish expected: %d\n", max);
		scanf("%d", &n);
		if (n > 0)
			printf("\n");
	}
	return 0;
}
