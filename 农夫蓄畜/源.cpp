#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[100005];
bool PD(int D,long long N,int C) {
	int i = 0; int j = 0; 
int t = a[0]; int count=1;
	while ( i < N-1) {
		i++;
		if (a[i] - t >= D) {
			count++;
			t = a[i];
			if (count >= C)return true;
		}	
   }
	return false;
	
}
int main() {
	int N, C;
	cin >> N >> C;
	
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N);
	//for (int i = 0; i < N; i++)cout << a[i];
	int L = 0;int R = a[N - 1] - a[0];
	
	while (L <=R) {
	int D = L + (R - L) / 2;
		if (PD(D, N, C)) {
			
			L = D + 1;
		}
		else {
			R = D-1 ;
		}
	
	}
	cout << L - 1 << endl;
	return 0;
}