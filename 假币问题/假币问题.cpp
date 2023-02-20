//有12枚硬币。其中有11枚真币和1枚假币。假币和真
//币重量不同，但不知道假币比真币轻还是重。现在，
//用一架天平称了这些币三次，告诉你称的结果，请你
//找出假币并且确定假币是轻是重（数据保证一定能找
//出来）
//输入
//第一行是测试数据组数。
//每组数据有三行，每行表示一次称量的结果。银币标号为
//A - L。每次称量的结果用三个以空格隔开的字符串表示：
//天平左边放置的硬币 天平右边放置的硬币 平衡状态。其
//中平衡状态用``up'', ``down'', 或 ``even''表示, 分别为右
//端高、右端低和平衡。天平左右的硬币数总是相等的。
// 输出
//输出哪一个标号的银币是假币，并说明它比真币轻还是重。
// 输入样例
//1
//ABCD EFGH even
//ABCI EFJK up
//ABIJ EFGH even
// 输出样例
//K is the counterfeit coin and it is light.
//解题思路
//对于每一枚硬币先假设它是轻的，看这样是否符合称
//量结果。如果符合，问题即解决。如果不符合，就假
//设它是重的，看是否符合称量结果。把所有硬币都试
//一遍，一定能找到特殊硬币
#include<iostream>
#include<cstring>
using namespace std;
char Left[3][7];//天平左边硬币
char Right[3][7];//天平右边硬币
char result[3][7];//结果
bool isfake(char c, bool light);//light为真表示假设假币为轻，
//否则表示假设假币为重
int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 3; i++)
			cin >> Left[i] >> Right[i] >> result[i];
		for (char c = 'A'; c <= 'L'; c++) {
			if (isfake(c, true)) {
				cout << c << " is the counterfeit coin and it is light.\n";
				break;
			}
			else if (isfake(c, false)) {
				cout << c << " is the counterfeit coin and it is heavy\n";
				break;
			}
		}

	}
	return 0;
}
bool isfake(char c, bool light) {
	for (int i = 0; i < 3; i++) {
		char * pleft, * pright;//指向天平两边的字符串
		if (light) {
			pleft = Left[i];
			pright = Right[i];
		}
		else {//如果假设假币是重的，则把称量结果左右对换
			pleft = Right[i];
			pright = Left[i];
		}
		switch (result[i][0]) {//天平右边的情况
		case'u':if (strchr(pright, c) == NULL)return false;
			break;
		case'e':if (strchr(pleft, c) || strchr(pright, c))return false;
			break;
		case'd':if (strchr(pleft, c) == NULL)return false;
			break;

		}

	}
	return true;
}
