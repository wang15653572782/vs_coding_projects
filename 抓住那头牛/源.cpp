#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int N, K;
const int MAXN = 100000;
int visit[MAXN + 10];//���ر��,visit[i]=true��ʾi�Ѿ���չ��
struct step {
	int x;//λ��
	int steps;//����x����Ĳ���
	step(int xx,int s):x(xx),steps(s){}
};
queue<step>q;//���У���Open��
int main() {
	cin >> N >> K;
	memset(visit, 0, sizeof(visit));
	q.push(step(N, 0));
	visit[N] = 1;
	while (!q.empty()) {
		step s = q.front();
		if (s.x == K) {//�ҵ�Ŀ��
			cout << s.steps << endl;
			return 0;

		}
		else {
			if (s.x - 1 >= 0 && !visit[s.x - 1]) {
				q.push(step(s.x - 1, s.steps + 1));
				visit[s.x - 1] = 1;
			}
			if (s.x + 1 <= MAXN && !visit[s.x + 1]) {
				q.push(step(s.x + 1, s.steps + 1));
				visit[s.x + 1] = 1;
			}
			if (s.x * 2 <= MAXN && !visit[s.x * 2]) {
				q.push(step(s.x * 2, s. steps + 1));
				visit[s.x * 2] = 1;
			}
			q.pop();
		}
	}
	return 0;
}