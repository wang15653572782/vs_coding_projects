#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int R, C;//行列数
int rooms[60][60];
int color[60][60];//方块是否染色过的标记
int maxRoomArea = 0, roomNum = 0;
int roomArea;//深搜过程中房间的大小
void Dfs(int i, int k) {
	if (color[i][k])return;
	++roomArea;
	color[i][k] = roomNum;
	if ((rooms[i][k] & 1) == 0)Dfs(i, k - 1);//向西走
	if ((rooms[i][k] & 2) == 0)Dfs(i - 1, k);//向北走
	if ((rooms[i][k] & 4) == 0)Dfs(i, k + 1);//向东走
	if ((rooms[i][k] & 8) == 0)Dfs(i + 1, k);//向南走

}
int main() {
	cin >> R >> C;
	for(int i=1;i<=R;++i)
		for (int k = 1; k <= C; ++k) {
			cin >> rooms[i][k];
		}
	memset(color, 0, sizeof(color));
	for(int i=1;i<=R;++i)
		for (int k = 1; k <= C; ++k) {
			if (!color[i][k]) {
				++roomNum; roomArea = 0;
				Dfs(i, k);
				maxRoomArea = max(roomArea, maxRoomArea);
			}
		}
	cout << roomNum << endl;
	cout << maxRoomArea << endl;
	return 0;
}