#include<iostream>
#include<cmath>
#include<cstdio>
#define N 200

using namespace std;
//半径	圆心横坐标	最短圆排列
double radius[N], centerX[N], bestOrder[N];
//最短圆排列长度
double minlength = 0xffffff;
int Copy[10];
//得到每个圆的圆心位置
double getCenterX(int k, int num) {
	double tmp = 0;
	//排列最短必定存在一个圆与该圆相切，找到一个与之相切的圆即可得到该圆坐标
	for (int i = 0; i < k; i++) {
		//相切圆圆心横坐标距求法
		double value = centerX[i] + 2.0 * sqrt(radius[k] * radius[i]);
		if (value > tmp) {
			tmp = value;
		}
	}
	return tmp;
}

//得到当前圆排列长度
void getLength(int num) {
	double left = 0xffff, right = -0xffff;
	for (int i = 0; i < num; i++) {
		//众多圆中起始位置最左的就是该排列的左边界
		if (centerX[i] - radius[i] < left) {
			left = centerX[i] - radius[i];
		}
		//众多圆中末尾位置最右的就是该排列的右边界
		if (centerX[i] + radius[i] > right) {
			right = centerX[i] + radius[i];
		}
	}

	//判断该排列是否为已计算排列中长度最小的，是则更新最小排列长度
	if (right - left < minlength) {
		minlength = right - left;
		//并更新最小圆排列顺序
		for (int i = 0; i < num; i++) {
			bestOrder[i] = Copy[i];
		}
	}
}

void traceBack(int k, int num) {
	//全部圆都已参与排列，计算该排列长度
	if (k == num) {
		getLength(num);
	}
	else {
		for (int j = k; j < num; ++j)
		{
			swap(radius[k], radius[j]);
			swap(Copy[k], Copy[j]);
			double nowX = getCenterX(k, num);
			//剪枝条件
			if (nowX + radius[k] + radius[0] < minlength)
			{
				centerX[k] = nowX;
				traceBack(k + 1, num);
			}
			//回溯
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
