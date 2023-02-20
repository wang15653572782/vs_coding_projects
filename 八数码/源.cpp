#include <iostream>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
int goalStatus = 123456780; //Ŀ��״̬
const int MAXS = 400000;
char result[MAXS]; //Ҫ������ƶ�����
struct Node {
	int status; //״̬
	int father; //���ڵ�ָ�룬��myQueue���±�
	char move; //���ڵ㵽���ڵ���ƶ���ʽ u/d/r/l 
	Node(int s, int f, char m) :status(s), father(f), move(m) { }
	Node() { }
};
Node myQueue[MAXS]; //״̬���У�״̬����362880
int qHead = 0; //��ͷָ��
int qTail = 1; //��βָ��
char moves[] = "udrl"; //�����ƶ�
int NewStatus(int status, char move) {
	//���status���� move �ƶ���õ�����״̬�����ƶ��������򷵻�-1 
	char tmp[20];
	int zeroPos; //�ַ�'0'��λ��
	sprintf(tmp, "%09d", status); //��Ҫ����ǰ��0 
	for (int i = 0; i < 9; ++i)
		if (tmp[i] == '0') {
			zeroPos = i;
			break;
		} //���ؿո��λ��
	switch (move) {
	case 'u':
		if (zeroPos - 3 < 0)
			return -1; //�ո��ڵ�һ��
		else {
			tmp[zeroPos] = tmp[zeroPos - 3];
			tmp[zeroPos - 3] = '0';
		}
		break;
	case 'd':
		if (zeroPos + 3 > 8)
			return -1; //�ո��ڵ�����
		else {
			tmp[zeroPos] = tmp[zeroPos + 3];
			tmp[zeroPos + 3] = '0';
		}
		break;
	case 'l':
		if (zeroPos % 3 == 0)
			return -1; //�ո��ڵ�һ��
		else {
			tmp[zeroPos] = tmp[zeroPos - 1];
			tmp[zeroPos - 1] = '0';
		}
		break;
	case 'r':
		if (zeroPos % 3 == 2)
			return -1; //�ո��ڵ�����
		else {
			tmp[zeroPos] = tmp[zeroPos + 1];
			tmp[zeroPos + 1] = '0';
		}
		break;
	}
	return atoi(tmp);
}
bool Bfs(int status) {
	//Ѱ�Ҵӳ�ʼ״̬status��Ŀ���·�����Ҳ����򷵻�false 
	int newStatus;
	set<int> expanded;
	myQueue[qHead] = Node(status, -1, 0);
	expanded.insert(status);
	while (qHead != qTail) { //���в�Ϊ��
		status = myQueue[qHead].status;
		if (status == goalStatus) //�ҵ�Ŀ��״̬
			return true;
		for (int i = 0; i < 4; i++) { //����4���ƶ�
			newStatus = NewStatus(status, moves[i]);
			if (newStatus == -1)
				continue; //�����ƣ�����һ��
			if (expanded.find(newStatus) != expanded.end())
				continue; //����չ��������һ��
			expanded.insert(newStatus);
				myQueue[qTail++] =Node(newStatus, qHead, moves[i]);
			//�½ڵ������
		}
		qHead++;
	}
	return false;
}
int main() {
	char line1[50]; char line2[20];
	while (cin.getline(line1, 48)) {
		int i, j;
		//�������ԭʼ�ַ�����Ϊ�����ַ���
		for (i = 0, j = 0; line1[i]; i++) {
			if (line1[i] != ' ') {
				if (line1[i] == 'x')
					line2[j++] = '0';
				else
					line2[j++] = line1[i];
			}
		}
		line2[j] = 0; //�ַ�����ʽ�ĳ�ʼ״̬
			if (Bfs(atoi(line2))) {
				int moves = 0;
				int pos = qHead;
				do { //ͨ��father�ҵ��ɹ���״̬���У������Ӧ����
					result[moves++] = myQueue[pos].move;
					pos = myQueue[pos].father;
				} while (pos); //pos = 0 ˵���Ѿ����˵���ʼ״̬��
				for (int i = moves - 1; i >= 0; i--)
					cout << result[i];
			}
			else
				cout << "unsolvable" << endl;
	}
}
