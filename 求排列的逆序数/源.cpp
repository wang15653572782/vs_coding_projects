#include <iostream>
using namespace std;
void Merge(int a[], int s, int mid, int e, int tmp[])
{
    int p1 = s, p2 = mid + 1, p3 = 0;
    while (p1 <= mid && p2 <= e)
    {
        if (a[p1] >= a[p2])
            tmp[p3++] = a[p1++];
        else
            tmp[p3++] = a[p2++];
    }
    while (p1 <= mid)
        tmp[p3++] = a[p1++];
    while (p2 <= e)
        tmp[p3++] = a[p2++];
    int cnt = 0;
    for (int i = s; i <= e; i++)
        a[i] = tmp[cnt++];
}

int MergeSortCount(int a[], int s, int e, int tmp[])
{
    int result = 0;
    if (s < e)
    {
        int mid = s + (e - s) / 2;
        result += MergeSortCount(a, s, mid, tmp);
        result += MergeSortCount(a, mid + 1, e, tmp);
        int i = s, j = mid + 1;
        while (i <= mid && j <= e)
        {
            if (a[i] <= a[j])
                j++;
            else
            {
                result += e - j + 1;
                i++;
            }
        }
        Merge(a, s, mid, e, tmp);
    }
    return result;
}

int main()
{
    int n;
    int a[100];
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    int tmp[100]; //¸¨ÖúÊı×é
    cout << MergeSortCount(a, 0, n - 1, tmp) << endl;

   

    return 0;
}