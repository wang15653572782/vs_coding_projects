#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int K, N, R;
struct Road {
	int d, L, t;
};
#define max 0x3f3f3f3f;
vector<vector<Road>>cityMap(110);//�ڽӱ�cityMap[i]�Ǵӵ�i��·�����ĳ��м���
int minLen = 1 << 30;//��ǰ�ҵ�������·���ĳ���
int totalLen;//�����ߵ�·���ĳ���
int totalCost;//�����ߵ�·���Ļ���
int visit[110];//�����Ƿ��Ѿ��߹��ı��
int minL[110][10100] ;//minL[i][j]��ʾ��i��j���,����Ϊj�����·�ĳ���
void Dfs(int s) {//��s��ʼ��N����
	if (s == N) {
		minLen = min(minLen, totalLen);
		return;
	}
	for (int i = 0; i < cityMap[s].size(); ++i) {
		int d = cityMap[s][i].d;//s��·����d
		if (!visit[d]) {
			int cost = totalCost + cityMap[s][i].t;
			if (cost > K)continue;
			if (totalLen + cityMap[s][i].L >= minLen || totalLen + cityMap[s][i].L >= minL[d][cost])
				continue;
			totalLen += cityMap[s][i].L;
			totalCost += cityMap[s][i].t;
			minL[d][cost] = totalLen;
			visit[d] = 1;
			Dfs(d);
			visit[d] = 0;
			totalCost -= cityMap[s][i].t;
			totalLen -= cityMap[s][i].L;
		}
	}

}
int main() {
	cin >> K >> N >> R;
	for (int i = 0; i < R; ++i) {
		int s;
		Road r;
		cin >> s >> r.d >> r.L >> r.t;
		if (s != r.d)cityMap[s].push_back(r);
	}
	for (int i = 0; i < 110; ++i)
		for (int j = 0; j < 10010; ++j)minL[i][j] = max;
	memset(visit, 0, sizeof(visit));
	totalLen = 0;
	totalCost = 0;
	visit[1] = 1;
	minLen = 1 << 30;
	Dfs(1);
	if (minLen < (1 << 30))cout << minLen << endl;
	else cout << "-1" << endl;
	return 0;
}
