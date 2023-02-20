//����4��С��10���������������ʹ�üӼ��˳�4�������Լ���
//�Ű���4�������������õ�һ�����ʽ�����ڵ������ǣ��Ƿ��
//��һ�ַ�ʽʹ�õõ��ı��ʽ�Ľ������24��
//����Ӽ��˳��Լ����ŵ�����������������ȼ�������ƽ��
//�Ķ���һ�£�����ĳ���������ʵ����������
//���磬����5��5��5��1������֪��5* (5 �C 1 / 5) = 24�����
//���Եõ�24���ֱ��磬����1��1��4��2��������ô�����ܵõ�
//24��
//���⣺��24
//����
//�������ݰ������У�ÿ�и���һ��������ݣ�����4��С��10������
//�������һ����������а���4��0����ʾ����Ľ������������ݲ���
//����
//���
//����ÿһ��������ݣ����һ�У�������Եõ�24�������YES����
//���������NO����
//��������
//5 5 5 1
//1 1 4 2
//0 0 0 0
//�������
//YES
//NO
#include<iostream>
#include<cmath>
using namespace std;
double a[5];
#define EPS 1e-6
bool isZero(double x) {
	return fabs(x) <= EPS;
}
bool count24(double a[], int n) {
	//������a��� n����������24
	if (n == 1) {
		if (isZero(a[0] - 24))return true;
		else return false;
	}
	double b[5];
	for(int i=0;i<n-1;i++)
		for (int j = i + 1; j < n; j++) {//ö�������������
			int m = 0; //��ʣ��m����, m = n - 2
			for (int k = 0; k < n; k++)
				if (k != i && k != j)b[m++] = a[k];
			b[m] = a[i] + a[j];
			if (count24(b, m + 1))return true;
			b[m] = a[i] - a[j];
			if (count24(b, m + 1))return true;
			b[m] = a[i] * a[j];
			if (count24(b, m + 1))return true;
			if (!isZero(a[j])) {
				b[m] = a[i] / a[j];
				if (count24(b, m + 1))return true;
			}
			if (!isZero(a[j])) {
				b[m] = a[j] / a[i];
				if (count24(b, m + 1))return true;
			}
		}
	return false;
}
int main() {
	while (true) {
		for (int i = 0; i < 4; i++)
			cin >> a[i];
		if (isZero(a[0]))break;
		if (count24(a, 4))cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
