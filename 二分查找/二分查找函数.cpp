//写一个函数BinarySeach，在包含size个元素的、从小到大排序的int数组a里查找元素
//p, 如果找到，则返回元素下标，如果找不到，则返回 - 1。要求复杂度O(log(n))
//int BinarySearch(int a[], int size, int p)
//{
//	int L = 0; //查找区间的左端点
//	int R = size - 1; //查找区间的右端点
//	while (L <= R) { //如果查找区间不为空就继续查找
//		int mid = L + (R - L) / 2; //取查找区间正中元素的下标
//		if (p == a[mid])
//			return mid;
//		else if (p > a[mid])
//			L = mid + 1; //设置新的查找区间的左端点
//		else
//			R = mid - 1; //设置新的查找区间的右端点
//	}
//	return -1;
//} //复杂度O(log(n))