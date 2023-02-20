#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct Node
{
    int r, c;   //所在位置 
    int t;     //查克拉剩余
    int level; //所在层数，路径长度 
};
char map[210][210];          //地图
int visit[210][210][15] = { 0 };    //判重数组
int M, N, T;                  //地图大小，查克拉数量 
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };   //方向数组  
int main()
{
    //分别代表鸣人和佐助的位置 
    int r1, c1;
    int r2, c2;

    scanf("%d %d %d", &M, &N, &T);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '@')
            {
                r1 = i;
                c1 = j;
            }

            if (map[i][j] == '+')
            {
                r2 = i;
                c2 = j;
            }
        }
    }

    visit[r1][c1][T] = 1;
    queue<struct Node> q;
    //初始状态入队
    Node node;
    node.r = r1; node.c = c1; node.level = 0; node.t = T;
    q.push(node);

    while (!q.empty())
    {
        Node temp = q.front();
        q.pop();

        //找到了 
        if (temp.r == r2 && temp.c == c2)
        {
            printf("%d\n", temp.level);
            return 0;
        }

        //没找到 入队所有关联节点
        for (int i = 0; i < 4; i++)
        {
            Node temp2;
            temp2.r = temp.r + dir[i][0];
            temp2.c = temp.c + dir[i][1];
            if (temp2.r >= 0 && temp2.r < M && temp2.c >= 0 && temp2.c < N)
            {
                //不越界

                //若为# 并且查克拉够 并且没访问过 可访问 
                if (map[temp2.r][temp2.c] == '#' && temp.t >= 1 && visit[temp2.r][temp2.c][temp.t - 1] == 0)
                {
                    temp2.t = temp.t - 1;
                    temp2.level = temp.level + 1;
                    q.push(temp2);
                    visit[temp2.r][temp2.c][temp2.t] = 1;
                }

                //不是# 并且未访问过 
                else if (map[temp2.r][temp2.c] != '#' && visit[temp2.r][temp2.c][temp.t] == 0)
                {
                    temp2.t = temp.t;
                    temp2.level = temp.level + 1;
                    q.push(temp2);
                    visit[temp2.r][temp2.c][temp2.t] = 1;
                }

            }
        }

    }

    //找不到 
    cout << -1 << endl;

    return 0;
}