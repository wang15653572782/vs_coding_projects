//ũ��Լ����һ�������Ļ��ʦ������ʶ���Լ�����û���㹻��Ǯ��ά��ũ������ת�ˡ�
//�����������¼���˽����� N(1 �� N �� 100, 000) ����ÿ����Ҫ�Ŀ�����
//Լ������Ϊ������M(1 �� M �� N) ���������ڴ���Ԥ�㰸������һ��������������Ϊfajo�¡�
//ÿ��fajo�°���һ��������Ķ��죬ÿ�챻ǡ�ð�����һ��fajo���
//Լ����Ŀ���Ǻ�����ÿ��fajo�°�����������ʹ�ÿ�������fajo�µĿ����������١�
//����
//��һ�а�����������N, M���õ����ո������
//������N�У�ÿ�а���һ��1��10000֮�����������˳�����������N����ÿ��Ŀ�����
//���
//һ��������������¶ȿ�������Сֵ��
//��������
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