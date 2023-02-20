#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string.h>
const int N = 1003;
const int M = 20004;
const int INF = 0x3f3f3f;
using namespace std;
struct Time {
    int x1, x2, h;
}a[N];
int dp[N][2]; //0表示第i的木板左边到底最短的时间  1表示右边的时间
int max_h, n;
int cmp(Time c, Time b)
{
    return c.h > b.h;//从大到小排列
}
void left(int i)//左
{
    int k = i + 1;
    while (k < n + 1 && a[i].h - a[k].h <= max_h)
    {
        if (a[i].x1 >= a[k].x1 && a[i].x1 <= a[k].x2)
        {
            dp[i][0] = a[i].h - a[k].h + min(dp[k][0] + a[i].x1 - a[k].x1, dp[k][1] + a[k].x2 - a[i].x1);
            return;
        }
        k++;
    }
    if (a[i].h - a[k].h > max_h)//不能到达下一平台
        dp[i][0] = INF;
    else
        dp[i][0] = a[i].h;//直接落地
    return;
}
void right(int i)//右
{
    int k = i + 1;
    while (k < n + 1 && a[i].h - a[k].h <= max_h)
    {
        if (a[i].x2 >= a[k].x1 && a[i].x2 <= a[k].x2)
        {
            dp[i][1] = a[i].h - a[k].h + min(dp[k][0] + a[i].x2 - a[k].x1, dp[k][1] + a[k].x2 - a[i].x2);
            return;
        }
        k++;
    }
    if (a[i].h - a[k].h > max_h)//不能到达下一平台
        dp[i][1] = INF;
    else//直接落地
        dp[i][1] = a[i].h;
    return;
}
int main()
{
    int t, x, y, i;
    scanf_s("%d", &t);
    while (t--)
    {
        scanf_s("%d%d%d%d", &n, &x, &y, &max_h);
        a[0].x1 = -20000;
        a[0].x2 = 20000;
        a[0].h = 0;
        a[1].x1 = a[1].x2 = x;
        a[1].h = y;
        for (i = 2; i <= n + 1; i++)
            scanf_s("%d%d%d", &a[i].x1, &a[i].x2, &a[i].h);
        sort(a, a + n + 2, cmp);
        memset(dp, 0, sizeof(dp));
        for (i = n; i >= 0; i--)
        {
            left(i);//进行左
            right(i);//进行右
        }
        int time = min(dp[0][0], dp[0][1]);
        printf("%d\n", time);
    }
    return 0;
}