#include<algorithm>
#include<iostream>
#include<cstring> 
using namespace std;
#define LL long long
int xiang();
int bds();
int xiang()//������ʽ
{
    int result;
    char op;
    while (op = cin.peek(), op == ' ')//����ո�
        cin.get();
    if (op == '!')//����У�
    {
        int fh = 1;
        while (cin.peek() == '!' || cin.peek() == ' ')//������ܵĶ����
        {
            char pt = cin.get();
            if (pt == '!')
                fh = -fh;
        }
        result = bds();//������
        if (fh == -1)
            result = !result;
    }
    else
        result = bds();
    int more = 1;
    while (more)//�Ƿ�����
    {
        char p;
        while (p = cin.peek(), p == ' ')//����ո�
            cin.get();

        if (p == '&' || p == '|')//���������
        {
            p = cin.get();
            int value;

            char p1;
            while (p1 = cin.peek(), p1 == ' ')
                cin.get();


            if (p1 == '!')//�ظ�������Ĺ���
            {
                int fh = 1;
                while (cin.peek() == '!' || cin.peek() == ' ')
                {
                    char pt = cin.get();
                    if (pt == '!')
                        fh = -fh;
                }
                value = bds();
                if (fh == -1)
                    value = !value;
            }
            else
                value = bds();

            if (p == '&')//��������������һ��
                result &= value;
            else
                result |= value;
        }
        else//���û����more=0����ѭ��
            more = 0;
    }
    return result;
}

int bds()//������
{
    int result;
    char op;
    while (op = cin.peek(), op == ' ')//����ո�
        cin.get();

    if (op == '(')//�����'('��ʾ������(���ʽ)���
    {
        cin.get();//��������(
        result = xiang();//������
        cin.get();//��������)
    }
    else//������ֵF��V���
    {
        char p = cin.get();
        if (p == 'V')
            result = 1;
        else
            result = 0;
    }
    return result;
}

int main()
{
    int i = 1;
    while (cin.peek() != EOF)//��������������ַ�
    {
        int k = xiang();
        char e = cin.peek();
        while (cin.peek() == ' ')//����ÿһ������ĩβ�Ŀո�
            cin.get();

        printf("Expression %d: ", i++);
        if (k == 0)
            cout << "F" << endl;
        else
            cout << "V" << endl;

        cin.get();//����ÿһ��������ɵ�'\n'
    }

    return 0;
}

