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
bool operator <(const lake& x, const lake& y)  //���ȶ���Ȩֵ�����ȼ��ƶ� 
{
	if (x.f == y.f) return x.id > y.id;            //�����������һ���࣬ID��С����ǰ������������ǰ 
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
			dis[i] += dis[i - 1];            //·�ϻ��ѵ�ʱ�� 
		}
		int max = -1;
		for (int i = 0; i < n; i++) {
			sum = 0;
			while (!q.empty()) q.pop();     //��ն��� 
			for (int j = 0; j <= i; j++)
				q.push(a[j]);
			for (int j = 0; j < n; j++)
				cou[j] = 0;
			int hh = h - dis[i];		//ʣ���ʱ�� 
			while (hh > 0) {
				node = q.top();
				q.pop();
				hh--;
				cou[node.id]++;       //��¼��ÿ��������Ĵ��� 
				sum += node.f;
				node.f -= node.d;
				if (node.f < 0) node.f = 0;     //֤���Ѿ�û���ˣ�����Ϊ������Ϊ��ʹû�㣬Ҳ������������Ϊ�����Ѿ���������������ͻ����
				q.push(node);
			}
			if (sum > max) {          //�ҵ��ܵ������������ 
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
