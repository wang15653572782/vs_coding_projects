//дһ������BinarySeach���ڰ���size��Ԫ�صġ���С���������int����a�����Ԫ��
//p, ����ҵ����򷵻�Ԫ���±꣬����Ҳ������򷵻� - 1��Ҫ���Ӷ�O(log(n))
//int BinarySearch(int a[], int size, int p)
//{
//	int L = 0; //�����������˵�
//	int R = size - 1; //����������Ҷ˵�
//	while (L <= R) { //����������䲻Ϊ�վͼ�������
//		int mid = L + (R - L) / 2; //ȡ������������Ԫ�ص��±�
//		if (p == a[mid])
//			return mid;
//		else if (p > a[mid])
//			L = mid + 1; //�����µĲ����������˵�
//		else
//			R = mid - 1; //�����µĲ���������Ҷ˵�
//	}
//	return -1;
//} //���Ӷ�O(log(n))