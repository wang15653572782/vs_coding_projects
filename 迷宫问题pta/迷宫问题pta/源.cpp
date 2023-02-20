#include<stdio.h>
using namespace std;
const int N = 110;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1};
int q[100000];
int front = 0, rear = 0;
int BFS(int map[N][N], int dist[N][N], int vis[N][N], int n, int m, int sx, int sy) {
	front = rear = 0;
	q[rear++] = sx; q[rear++] = sy;
	dist[sx][sy] = 0;
	while (front < rear) {
		int x = q[front++]; int y = q[front++];
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] == 1 || map[nx][ny] == 1)continue;
			if (map[nx][ny] == 4)return dist[x][y] + 1;
			q[rear++] = nx; q[rear++] = ny;
			dist[nx][ny] = dist[x][y] + 1;
			vis[nx][ny] = 1;
		}
	}
	return -1;
}
int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, m, sx, sy;
	while (scanf("%d%d", &n, &m) != EOF) {
		int map[N][N], dist[N][N], vis[N][N] = { 0 };
		for(int i=0;i<n;++i)
			for (int j = 0; j < m; ++j) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 3) {
					sx = i; sy = j;
				}
			}
		int ans = BFS(map, dist, vis, n, m, sx, sy);
		if (ans == -1)printf("unreachable\n");
		else printf("%d\n", ans);
	}
	return 0;
}
