//��M��ͬ����ƻ������N��ͬ��������������е����ӿ��Ų��ţ�
//�ʹ��ж����ֲ�ͬ�ķַ���5��1��1��1��5��1 ��ͬһ�ַַ���
//����
//��һ���ǲ������ݵ���Ŀt��0 <= t <= 20��������ÿ�о�����������
//��M��N���Կո�ֿ���1 <= M��N <= 10��
//���
//�������ÿ������M��N����һ�������Ӧ��K��
//��������
//1
//7 3
//�������
//8
#include<iostream>
using namespace std;
int f(int m, int n) {
	if (n > m)return f(m, m);
	if (m == 0)return 1;
	if (n == 0)return 0;
	return f(m, n - 1) + f(m - n, n);
}
int main() {
	int t, m, n;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		cout << f(m, n) << endl;

	}
	return 0;
}