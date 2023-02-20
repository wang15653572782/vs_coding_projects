#include<iostream>
#include<cmath>
#include<cstdio>
#define N 200

using namespace std;
//�뾶	Բ�ĺ�����	���Բ����
double radius[N], centerX[N], bestOrder[N];
//���Բ���г���
double minlength = 0xffffff;
int Copy[10];
//�õ�ÿ��Բ��Բ��λ��
double getCenterX(int k, int num) {
	double tmp = 0;
	//������̱ض�����һ��Բ���Բ���У��ҵ�һ����֮���е�Բ���ɵõ���Բ����
	for (int i = 0; i < k; i++) {
		//����ԲԲ�ĺ��������
		double value = centerX[i] + 2.0 * sqrt(radius[k] * radius[i]);
		if (value > tmp) {
			tmp = value;
		}
	}
	return tmp;
}

//�õ���ǰԲ���г���
void getLength(int num) {
	double left = 0xffff, right = -0xffff;
	for (int i = 0; i < num; i++) {
		//�ڶ�Բ����ʼλ������ľ��Ǹ����е���߽�
		if (centerX[i] - radius[i] < left) {
			left = centerX[i] - radius[i];
		}
		//�ڶ�Բ��ĩβλ�����ҵľ��Ǹ����е��ұ߽�
		if (centerX[i] + radius[i] > right) {
			right = centerX[i] + radius[i];
		}
	}

	//�жϸ������Ƿ�Ϊ�Ѽ��������г�����С�ģ����������С���г���
	if (right - left < minlength) {
		minlength = right - left;
		//��������СԲ����˳��
		for (int i = 0; i < num; i++) {
			bestOrder[i] = Copy[i];
		}
	}
}

void traceBack(int k, int num) {
	//ȫ��Բ���Ѳ������У���������г���
	if (k == num) {
		getLength(num);
	}
	else {
		for (int j = k; j < num; ++j)
		{
			swap(radius[k], radius[j]);
			swap(Copy[k], Copy[j]);
			double nowX = getCenterX(k, num);
			//��֦����
			if (nowX + radius[k] + radius[0] < minlength)
			{
				centerX[k] = nowX;
				traceBack(k + 1, num);
			}
			//����
			swap(radius[k], radius[j]);
			swap(Copy[k], Copy[j]);
		}

	}
}

int main() {

	int n;
	
		minlength = 0xffffff;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> radius[i]; Copy[i] = i+1;
		}
		traceBack(0, n);
		printf_s("%.2lf\n", minlength);
		for (int i = 0; i < n; ++i)
			cout << bestOrder[i] << ' ';
		
	

	return 0;
}
