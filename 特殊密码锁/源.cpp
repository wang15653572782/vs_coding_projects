//有一种特殊的二进制密码锁，由n个相连的按钮组成（n < 30），按钮有凹 / 凸两种状态，用手按按钮会改变其状态。
//
//	然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。
//
//	当前密码锁状态已知，需要解决的问题是，你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。
//
//	输入
//	两行，给出两个由0、1组成的等长字符串，表示当前 / 目标密码锁状态，其中0代表凹，1代表凸。
//	输出
//	至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。
//样例输入
//011
//000
//样例输出
//1
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int oriLock;
int lock;
int destLock;

inline void SetBit(int& n, int i, int v)
{
	if (v)
		n |= (1 << i);    // 把第i位设为1 n_i + 1 或运算
	else
		n &= ~(1 << i);   // 把第i位设为0 n_i * 0 与运算
}
inline void FlipBit(int& n, int i)
{
	n ^= (1 << i);      // 反转第i位 n_i^1 
}
inline int GetBit(int n, int i)
{
	return (n >> i) & 1;    // 用与1移位取出第i位数字
}
int main()
{

	char line[40];
	//oriLock为原始结果，destLock为目标结果,用一个整数表示二进制数
	destLock = lock = oriLock = 0;
	cin >> line;
	int N = strlen(line);
	for (int i = 0; i < N; ++i)
		SetBit(oriLock, i, line[i] - '0');
	cin >> line;
	for (int i = 0; line[i]; ++i)
		SetBit(destLock, i, line[i] - '0');

	int minTimes = 1 << 30;
	// 按第一个位置按和第一个位置不按进行枚举，如1101，第一位按与不按所造成的结果是不同的，会形成多种情况
	for (int p = 0; p < 2; ++p) {

		lock = oriLock;
		int times = 0;
		int curButton = p;
		for (int i = 0; i < N; ++i) {
			if (curButton) {
				++times;//最多按N次
				// 下面这个是一个集成的写法
				// 考虑了左右两个边界
				if (i > 0)
					FlipBit(lock, i - 1);
				// 翻转这个位置
				FlipBit(lock, i);
				if (i < N - 1)
					FlipBit(lock, i + 1);
			}
			// 只要当前位不相同，就翻转
			if (GetBit(lock, i) != GetBit(destLock, i))//当前不同只有通过下一位按钮来改变
				curButton = 1;
			else
				curButton = 0;//第N-1位不同不能再转换（因为它变会影响前一位）
		}
		// 全部翻转完判断是否相同
		if (lock == destLock)
			minTimes = min(minTimes, times);
	}
	if (minTimes == 1 << 30)//全部翻转完后都无法与destLock一致
		cout << "impossible" << endl;
	else
		cout << minTimes << endl;
	return 0;
}
