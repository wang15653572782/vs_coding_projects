#include <iostream>
#include <cmath>
using namespace std;
int N;
int queenPos[100];
//���������õĻʺ�λ�á������Ͻ���(0,0)
void NQueen(int k);
int main()
{
	cin >> N;
	NQueen(0); //�ӵ�0�п�ʼ�ڻʺ�
	return 0;
}
void NQueen(int k) {
	int i;
	if (k == N) {//N���ʺ��Ѿ��ں�
		for (i = 0; i < N; i++)
			cout << queenPos[i] + 1 << " ";
		cout << endl;
		return;
	}
	for (i = 0; i < N; i++) {//���Ե�k���ʺ��λ��
		int j;
		for (j = 0; j < k; j++) {
			//���Ѿ��ںõģ���ʺ��λ�ñȽϣ����Ƿ��ͻ
			if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j))
				break;
		}
if (j == k) {//��ǰѡ��λ��i����ͻ
	queenPos[k] = i;//����k���ʺ����λ��i
	NQueen(k + 1);
	}
	

	}
}