//��һ������Ķ���������������n�������İ�ť��ɣ�n < 30������ť�а� / ͹����״̬�����ְ���ť��ı���״̬��
//
//	Ȼ������ͷ�۵��ǣ����㰴һ����ťʱ���������ڵ�������ť״̬Ҳ�ᷴת����Ȼ������㰴��������������ұߵİ�ť���ð�ťֻ��Ӱ�쵽�������ڵ�һ����ť��
//
//	��ǰ������״̬��֪����Ҫ����������ǣ���������Ҫ�����ٴΰ�ť�����ܽ�������ת��Ϊ��������Ŀ��״̬��
//
//	����
//	���У�����������0��1��ɵĵȳ��ַ�������ʾ��ǰ / Ŀ��������״̬������0������1����͹��
//	���
//	������Ҫ���еİ���ť��������������޷�ʵ��ת�䣬�����impossible��
//��������
//011
//000
//�������
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
		n |= (1 << i);    // �ѵ�iλ��Ϊ1 n_i + 1 ������
	else
		n &= ~(1 << i);   // �ѵ�iλ��Ϊ0 n_i * 0 ������
}
inline void FlipBit(int& n, int i)
{
	n ^= (1 << i);      // ��ת��iλ n_i^1 
}
inline int GetBit(int n, int i)
{
	return (n >> i) & 1;    // ����1��λȡ����iλ����
}
int main()
{

	char line[40];
	//oriLockΪԭʼ�����destLockΪĿ����,��һ��������ʾ��������
	destLock = lock = oriLock = 0;
	cin >> line;
	int N = strlen(line);
	for (int i = 0; i < N; ++i)
		SetBit(oriLock, i, line[i] - '0');
	cin >> line;
	for (int i = 0; line[i]; ++i)
		SetBit(destLock, i, line[i] - '0');

	int minTimes = 1 << 30;
	// ����һ��λ�ð��͵�һ��λ�ò�������ö�٣���1101����һλ���벻������ɵĽ���ǲ�ͬ�ģ����γɶ������
	for (int p = 0; p < 2; ++p) {

		lock = oriLock;
		int times = 0;
		int curButton = p;
		for (int i = 0; i < N; ++i) {
			if (curButton) {
				++times;//��ఴN��
				// ���������һ�����ɵ�д��
				// ���������������߽�
				if (i > 0)
					FlipBit(lock, i - 1);
				// ��ת���λ��
				FlipBit(lock, i);
				if (i < N - 1)
					FlipBit(lock, i + 1);
			}
			// ֻҪ��ǰλ����ͬ���ͷ�ת
			if (GetBit(lock, i) != GetBit(destLock, i))//��ǰ��ֻͬ��ͨ����һλ��ť���ı�
				curButton = 1;
			else
				curButton = 0;//��N-1λ��ͬ������ת������Ϊ�����Ӱ��ǰһλ��
		}
		// ȫ����ת���ж��Ƿ���ͬ
		if (lock == destLock)
			minTimes = min(minTimes, times);
	}
	if (minTimes == 1 << 30)//ȫ����ת����޷���destLockһ��
		cout << "impossible" << endl;
	else
		cout << minTimes << endl;
	return 0;
}
