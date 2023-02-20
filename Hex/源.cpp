#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include<algorithm>
using namespace std;
int new_x, new_y;
int flag = 1;//�ж��ҷ����ӵ�����1-�����ߣ�0-�����ߣ�2-�ߵ�ͷ��
const int SIZE = 11;
int board[SIZE][SIZE] = { 0 };//����1���Է�-1���հ�0
//�����ҷ�Ϊ��
int dx = 1, dy = 2;// ��ǰһ���µĵط�
bool vaild(int x, int y) {//�жϵ��Ƿ����
	if (x >= 0 && x <= 10 && y >= 0 && y <= 10)return true;
	else return false;
}
int turn() {//�жϵ�ǰ������ҷ�������
	for (int z = 0; z <= 10; ++z) {
		if (board[10][z] == 1)return 2;
	}
	while (dx <= 10 && dy <= 10) {
		while (dx <= 10 && dy <= 10 && board[dx][dy] == 1) {
			dx++; dy++;
		}
		//if (board[dx][dy] == 0)return 1;
		dx--; dy--;
		if (dx + 2 <= 10 && dy + 1 <= 10) {
			if (board[dx + 2][dy - 1] == -1 && board[dx + 1][dy + 1] == 0) return 1;
			if (board[dx + 2][dy - 1] == 0 && board[dx + 1][dy + 1] == 0) return 1;
			if (board[dx + 2][dy - 1] == 0 && board[dx + 1][dy + 1] == -1) return 0;
		}
		if (dx == 9)return 0;
		while (dx <= 10 && dy <= 10 && board[dx][dy] == 1) {
			dx += 2; dy--;
		}
		dx -= 2; dy++;
		if (dx + 2 <= 10 && dy + 1 <= 10) {
			if (board[dx + 1][dy + 1] == 0 && board[dx + 2][dy - 1] == 0)return 0;
			if (board[dx + 1][dy + 1] == -1 && board[dx + 2][dy - 1] == 0)return 0;
			if (board[dx + 1][dy + 1] == 0 && board[dx + 2][dy - 1] == -1)return 1;
		}
	}
	/*if (board[i - 1][j - 1] == 1&&i+1<=10&&j+1<=10&&board[i+1][j+1]==0)return 1;
	if (board[i - 1][j - 1] == 1 && i + 1 <= 10 && j + 1 <= 10 && board[i + 1][j + 1] == -1)return 0;
	if (board[i - 2][j + 1] == 1&& i + 2 <= 10 && board[i+2][j-1]==0)return 0;
	if (board[i - 2][j + 1] == 1 &&i+2<=10&& board[i + 2][j - 1] == -1)return 1;*/
}
void FindBest(int flag_turn) {
	if (board[0][2] == -1 && board[0][3] == 0) {
		new_x = 0; new_y = 3; return;
	}
	if (board[0][2] == 0 && board[0][3] == -1) {
		new_x = 0; new_y = 2; return;
	}

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 1 && vaild(i - 1, j - 1) && board[i - 1][j - 1] == 1) {
				if (vaild(i + 1, j + 1) && board[i + 1][j + 1] != 1 && board[i + 2][j - 1] == 1) {
					if (board[i + 1][j - 1] == 1 || board[i + 1][j] == 1)break;
					if (board[i + 1][j - 1] == -1 && board[i + 1][j] == 0) {
						new_x = i + 1; new_y = j; return;
					}
					if (board[i + 1][j - 1] == 0 && board[i + 1][j] == -1) {
						new_x = i + 1; new_y = j - 1; return;
					}
				}
				if (board[i - 1][j] == -1 && board[i][j - 1] == 0 && board[i - 1][j - 1] == 1) {
					new_x = i; new_y = j - 1; return;
				}
				if (board[i - 1][j] == 0 && board[i][j - 1] == -1 && board[i - 1][j - 1] == 1) {
					new_x = i - 1; new_y = j; return;
				}
				if (board[i + 1][j] == -1 && board[i][j + 1] == 0 && board[i + 1][j + 1] == 1) {
					new_x = i; new_y = j + 1; return;
				}
				if (board[i + 1][j] == 0 && board[i][j + 1] == -1 && board[i + 1][j + 1] == 1) {
					new_x = i + 1; new_y = j; return;
				}
			}
			if (board[i][j] == 1 && vaild(i - 2, j + 1) && board[i - 2][j + 1] == 1) {
				if (vaild(i + 2, j - 1) && board[i + 1][j + 1] == 1 && board[i + 2][j - 1] != 1) {
					if (board[i + 1][j] == 1 || board[i][j + 1] == 1)break;
					if (board[i + 1][j] == -1 && board[i][j + 1] == 0) {
						new_x = i; new_y = j + 1; return;
					}
					if (board[i + 1][j] == 0 && board[i][j + 1] == -1) {
						new_x = i + 1; new_y = j; return;
					}
				}
				if (board[i - 1][j] == -1 && board[i - 1][j + 1] == 0 && board[i - 2][j + 1] == 1) {
					new_x = i - 1; new_y = j + 1; return;
				}
				if (board[i - 1][j] == 0 && board[i - 1][j + 1] == -1 && board[i - 2][j + 1] == 1) {
					new_x = i - 1; new_y = j; return;
				}
				if (board[i + 1][j - 1] == -1 && board[i + 1][j] == 0 && board[i + 2][j - 1] == 1) {
					new_x = i + 1; new_y = j; return;
				}
				if (board[i + 1][j - 1] == 0 && board[i + 1][j] == -1 && board[i + 2][j - 1] == 1) {
					new_x = i + 1; new_y = j - 1; return;
				}
			}

			//˫��ѭ��������з���������
		}
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 1 && flag_turn == 2) {
				if (board[0][2] == 0 && board[0][3] == 0) {
					new_x = 0; new_y = 3; return;
				}
				if (vaild(i - 1, j - 1) && board[i - 1][j - 1] == 1) {
					if (board[i][j - 1] == 0 && board[i - 1][j] == 0) {
						new_x = i; new_y = j - 1; return;
					}

				}
				if (vaild(i - 2, j + 1) && board[i - 2][j + 1] == 1 && board[i - 1][j] == 0) {
					if (board[i - 1][j + 1] == 0) {
						new_x = i - 1; new_y = j + 1; return;
					}
				}
			}
		}
	int xi = dx, yi = dy;
	if (flag_turn == 1) {//������
		if (board[3][4] == 1 && board[5][3] == 0 && board[7][2] == 0 && board[9][1] == 0) {
			new_x = 5; new_y = 3; return;
		}
		if (board[4][5] == 1 && board[6][4] == 0 && board[8][3] == 0 && board[10][2] == 0) {
			new_x = 6; new_y = 4; return;
		}
		if (board[5][6] == 1 && board[7][5] == 0 && board[9][4] == 0) {
			new_x = 7; new_y = 5; return;
		}
		if (board[6][7] == 1 && board[8][6] == 0 && board[10][5] == 0) {
			new_x = 8; new_y = 6; return;
		}
		if (board[7][8] == 1 && board[9][7] == 0) {
			new_x = 9; new_y = 7; return;
		}
		if (xi + 1 == 9 && yi + 1 == 10) {//�����
			new_x = 9; new_y = 10; return;
		}
		if (vaild(xi + 1, yi + 1) && board[xi + 1][yi + 1] == 0) {//û���з�ռ��
			new_x = xi + 1; new_y = yi + 1; return;
		}
		if (vaild(xi + 1, yi + 1) && board[xi + 1][yi + 1] == -1) {//���з�ռ���ˣ�����ת
			new_x = xi + 2; new_y = yi - 1; flag_turn = 0; return;
		}
	}
	if (flag_turn == 0) {//������
		if (xi == 9) {
			new_x = 10;
			if (board[10][yi] == 0) { new_y = yi; return; }
			if (board[10][yi - 1] == 0 && board[10][yi] != 1) { new_y = yi - 1; return; }

		}
		if (yi == 0 && xi < 10) {
			new_x = xi + 1; new_y = yi + 1; return;
		}
		if (vaild(xi + 2, yi - 1) && board[xi + 2][yi - 1] == 0) {//û���з�ռ��
			if (board[xi + 1][yi - 1] == -1 && board[xi + 1][yi] == -1) {
				new_x = xi + 1; new_y = yi + 1; return;
			}
			else {
				new_x = xi + 2; new_y = yi - 1; return;
			}
		}
		if (vaild(xi + 2, yi - 1) && board[xi + 2][yi - 1] == -1) {//���з�ռ���ˣ�����ת
			new_x = xi + 1; new_y = yi + 1;  return;
		}
	}
	if (flag_turn == 2) {//������ͷ��	
		if (board[xi - 1][yi] == -1 && board[xi][yi - 1] == 0) {
			new_x = xi; new_y = yi - 1; return;
		}
		if (board[xi - 1][yi] == 0 && board[xi][yi - 1] == -1) {
			new_x = xi - 1; new_y = yi; return;
		}
		if (board[xi - 1][yi] == 0 && board[xi][yi - 1] == 0) {
			new_x = xi - 1; new_y = yi; return;
		}

	}

}
int x1 = -1, y1 = -1;
int search(int p, int q) {
	if (board[p - 2][q + 1] == 1 && (p - 2) >= 0 && (q + 1) <= 10) {
		if (board[p - 1][q] == -1 && board[p - 1][q + 1] == 0) {
			x1 = p - 1; y1 = q + 1; return 1;
		}
		if (board[p - 1][q] == 0 && board[p - 1][q + 1] == -1) {
			x1 = p - 1; y1 = q; return 1;
		}
	}
	else {
		if (p - 1 < 0 || q + 1 > 10) return 0;
		if (board[p][q + 1] == -1 && board[p - 1][q + 1] == 0) {
			x1 = p - 1; y1 = q + 1; return 1;
		}
		if (board[p][q + 1] == 0 && board[p - 1][q + 1] == -1) {
			x1 = p; y1 = q + 1; return 1;
		}
	}
	return 0;
}
int main()
{
	int  result = 0, X = -1, Y = -1;
	int x, y, n;
	//�ָ�Ŀǰ��������Ϣ
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y; if (x != -1) board[x][y] = -1;	//�Է�
		cin >> x >> y; if (x != -1) board[x][y] = 1;	//�ҷ�
		//if (i == n - 2) {
		//	dx = x; dy = y;//�ҷ�ǰһ���µ�����
		//}
	}
	cin >> x >> y;  if (x != -1) board[x][y] = -1;	//�Է�
	else {
		//dx = x; dy = y;//�ҷ�ǰһ���µ�����
		board[1][2] = 1;
		cout << 1 << ' ' << 2 << endl;
		return 0;
	}

	if (board[1][2] == 1) {
		flag = turn();//�ж�����
		FindBest(flag);
	}
	if (board[1][2] == -1) {

		if (board[10][0] == 0) {
			new_x = 10; new_y = 0;//��ռ��ɫ����λ
		}
		else {
			for (int i = 10; i >= 0; i--) {
				if (result == 1) {
					break;
				}
				for (int j = 0; j <= 10; j++) {
					if (board[i][j] == 1) {
						if (j > Y) {
							X = i; Y = j;//����ʤ����������� 
						}
						result = search(i, j);//���ز�ѯ�������������ĸ��������� Ϊ1 
						if (result == 1) {//����жԷ����ӵ�· 
							new_x = x1;
							new_y = y1;
							break;
						}
					}
				}
			}//�������̿��Ƿ������ӵ�4· 
			if (result == 0) {//û�����ӵ�½��׼���߶Խ��ߣ� 
				if (Y < 9) {
					if ((X - 1 >= 0 && Y + 2 <= 10) || (X - 2 >= 0 && Y + 1 <= 10)) {
						if (board[X - 1][Y + 2] == 0 && X - 1 >= 0 && Y + 2 <= 10) {
							new_x = X - 1; new_y = Y + 2;
						}
						else if (X - 2 >= 0 && Y + 1 <= 10) {
							new_x = X - 2; new_y = Y + 1;
						}
					}
					else {
						new_x = X + 1; new_y = Y + 1;
					}
				}
				else {
					X = 10; Y = 0;
					while (1) {
						if (Y < 9) {
							if (board[X - 1][Y + 2] == 1) {
								if (board[X][Y + 1] == 0 && board[X - 1][Y + 1] == 0) {
									new_x = X; new_y = Y + 1;
									break;
								}
								X = X - 1; Y = Y + 2;
							}
							else if (board[X - 2][Y + 1] == 1) {
								if (board[X - 1][Y] == 0 && board[X - 1][Y + 1] == 0) {
									new_x = X - 1;
									new_y = Y;
									break;
								}
								X = X - 2; Y = Y + 1;
							}
						}
						else if (Y == 9) {
							new_x = X;
							new_y = Y + 1;
							break;
						}

					}

				}
			}
		}
	}
	/***********���Ϸ������Ĵ��룬���߽�������������ӵ�λ�ã�����new_x��new_y��****************/
	/************************************************************************************/

	// ��ƽ̨������߽��
	cout << new_x << ' ' << new_y << endl;
	return 0;
}