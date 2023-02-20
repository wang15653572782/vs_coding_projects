#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct Node
{
    int r, c;   //����λ�� 
    int t;     //�����ʣ��
    int level; //���ڲ�����·������ 
};
char map[210][210];          //��ͼ
int visit[210][210][15] = { 0 };    //��������
int M, N, T;                  //��ͼ��С����������� 
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };   //��������  
int main()
{
    //�ֱ�������˺�������λ�� 
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
    //��ʼ״̬���
    Node node;
    node.r = r1; node.c = c1; node.level = 0; node.t = T;
    q.push(node);

    while (!q.empty())
    {
        Node temp = q.front();
        q.pop();

        //�ҵ��� 
        if (temp.r == r2 && temp.c == c2)
        {
            printf("%d\n", temp.level);
            return 0;
        }

        //û�ҵ� ������й����ڵ�
        for (int i = 0; i < 4; i++)
        {
            Node temp2;
            temp2.r = temp.r + dir[i][0];
            temp2.c = temp.c + dir[i][1];
            if (temp2.r >= 0 && temp2.r < M && temp2.c >= 0 && temp2.c < N)
            {
                //��Խ��

                //��Ϊ# ���Ҳ������ ����û���ʹ� �ɷ��� 
                if (map[temp2.r][temp2.c] == '#' && temp.t >= 1 && visit[temp2.r][temp2.c][temp.t - 1] == 0)
                {
                    temp2.t = temp.t - 1;
                    temp2.level = temp.level + 1;
                    q.push(temp2);
                    visit[temp2.r][temp2.c][temp2.t] = 1;
                }

                //����# ����δ���ʹ� 
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

    //�Ҳ��� 
    cout << -1 << endl;

    return 0;
}