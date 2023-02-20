#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int MinS[22][22][22];   //MinS[i][j][k]��ʾ��i*j�ĵ����Ϊk+1�飨��k���������ǿ鵰����������
int main()
{
    int w, h, m;
    while (cin >> w >> h >> m && (w || h || m)) {
        memset(MinS, INF, sizeof MinS);
        for (int i = 1; i <= w; i++) {//ö�ٿ��
            for (int j = 1; j <= h; j++) { //ö�ٸ߶�
                for (int k = 0; k <= m - 1; k++) {//ö�����еõ���
                    if (k == 0)//��һ�鵰�ⲻ��ʱ,�Լ������
                        MinS[i][j][k] = i * j;
                    else if (k > i * j - 1)//�ֲ���,��Ϊ����С,��ôʧ����Ϊ�����
                        MinS[i][j][k] = INF;
                    else {
                        for (int r = 1; r <= i - 1; r++)//ö�ٵ�һ�������е�λ�ã���ʱjȫ�̲���
                            for (int kk = 0; kk <= k - 1; kk++)//��ʣk-1����
                                MinS[i][j][k] = min(MinS[i][j][k], max(MinS[r][j][kk], MinS[i - r][j][k - kk - 1]));
                        for (int c = 1; c <= j - 1; c++)//ö�ٵ�һ�������е�λ�ã���ʱiȫ�̲���
                            for (int kk = 0; kk <= k - 1; kk++)//��ʣk-1����
                                MinS[i][j][k] = min(MinS[i][j][k], max(MinS[i][c][kk], MinS[i][j - c][k - kk - 1]));
                    }
                }
            }
        }
        cout << MinS[w][h][m - 1] << endl;
    }
    return 0;
}