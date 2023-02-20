#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int MinS[22][22][22];   //MinS[i][j][k]表示将i*j的蛋糕分为k+1块（切k刀）最大的那块蛋糕的面积下限
int main()
{
    int w, h, m;
    while (cin >> w >> h >> m && (w || h || m)) {
        memset(MinS, INF, sizeof MinS);
        for (int i = 1; i <= w; i++) {//枚举宽度
            for (int j = 1; j <= h; j++) { //枚举高度
                for (int k = 0; k <= m - 1; k++) {//枚举需切得刀数
                    if (k == 0)//当一块蛋糕不分时,自己即最大
                        MinS[i][j][k] = i * j;
                    else if (k > i * j - 1)//分不了,因为求最小,那么失败设为无穷大
                        MinS[i][j][k] = INF;
                    else {
                        for (int r = 1; r <= i - 1; r++)//枚举第一刀横着切得位置：此时j全程不变
                            for (int kk = 0; kk <= k - 1; kk++)//还剩k-1刀切
                                MinS[i][j][k] = min(MinS[i][j][k], max(MinS[r][j][kk], MinS[i - r][j][k - kk - 1]));
                        for (int c = 1; c <= j - 1; c++)//枚举第一刀竖着切得位置：此时i全程不变
                            for (int kk = 0; kk <= k - 1; kk++)//还剩k-1刀切
                                MinS[i][j][k] = min(MinS[i][j][k], max(MinS[i][c][kk], MinS[i][j - c][k - kk - 1]));
                    }
                }
            }
        }
        cout << MinS[w][h][m - 1] << endl;
    }
    return 0;
}