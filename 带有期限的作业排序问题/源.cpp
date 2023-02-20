#include<iostream>
#include<algorithm>
using namespace std;
const int max = 201;
int FIND(int* parent, int i)
{//���Һ���Ԫ��i��������ʹ��ѹ������ȥѹ����i����j�����н��
	int j, k, t;
	j = i;
	while (parent[j] > 0) j = parent[j];//�Ҹ�
	k = i;
	while (k != j) {//ѹ����i����j�Ľ��
		t = parent[k];
		parent[k] = j;
		k = t;
	}
	return j;
}

void UNION(int* parent, int i, int j)
{//ʹ�ü�Ȩ����ϲ���Ϊi��j����������
	int x;
	x = parent[i] + parent[j];
	if (parent[i] > parent[j]) {//i�Ľ����
		parent[i] = j;
		parent[j] = x;
	}
	else {//j�Ľ����
		parent[j] = i;
		parent[i] = x;
	}
}
int k = 0;
void FJS(int  D[], int n, int b, int J[],int Q[]) {
	int F[max], P[max];
	int b;
	for (int i = 0; i <= b; ++i) {
		F[i] = i; P[i] = -1;
	}
	
	for (int i = 1; i <= n; ++i) {
		int j = FIND(P,min(n, D[i]));
		if (F[j] != 0) {
			k++; J[k] = i;
			Q[F[j]] = i;
			int l = FIND(P,F[j] - 1); UNION(P,l, j);
			F[j] = F[l];
		}
	}
}
void SORT(int P[], int D[], int start, int end)//��Ч���С����
{
	for (int i = start + 1; i <= end; i++)
	{
		int item = P[i];
		int item_d = D[i];
		int j = i - 1;
		while (j >= start && item > P[j])
		{
			P[j + 1] = P[j];
			D[j + 1] = D[j];
			j--;
		}
		P[j + 1] = item;
		D[j + 1] = item_d;
	}
}
int main() {
	int n;
	cin >> n;
	int P[max], D[max],J[max],Q[max];
	for (int i = 1; i <= n; ++i) {
		cin >> D[i] >> P[i];
	}
	SORT(P, D, 1, n);
	int m = 0;
	for (int i = 1; i <= n; ++i) {
		if (D[i] > m)m = D[i];
	}
	int b = min(n, m);
	for (i = 1; i <= b; i++)
		Q[i] = -1;
	 FJS(D, n, b, J, Q);
	 int sum = 0;
	 for (int i = 1; i <= b; i++)
	 {
		 if (Q[i] != -1) {
			 sum += P[Q[i]];
		 }
	 }
	 cout << sum << endl;
	 for (int i = 1; i <= b; ++i) {
		 if (Q[i] != -1)cout << Q[i] << " ";
	 }
	 return 0;
 }