#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define max 28

int main() {
	int a[3][3]; int b[10] = { 3 };
	int N;
	int t = max;
	int tmp[10] = { 0 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];
	int i1, i2, i3, i4, i5, i6, i7, i8, i9;
	for (i1 = 0; i1 < 4; i1++)
		for (i2 = 0; i2 < 4; i2++)
			for (i3 = 0; i3 < 4; i3++) {
				b[1] = i1; b[2] = i2; b[3] = i3;
				a[0][0] = (a[0][0] + i1 + i2) % 4;
				a[0][1] = (a[0][1] + i1 + i2 + i3) % 4;
				a[0][2] = (a[0][2] + i2 + i3) % 4;
				a[1][0] = (a[1][0] + i1) % 4;
				a[1][1] = (a[1][1] + i1 + i3) % 4;
				a[1][2] = (a[1][2] + i3) % 4;
				i4 = (4 - a[0][0]) % 4;
				i5 = (4 - a[0][1]) % 4;
				i6 = (4 - a[0][2]) % 4;
				b[4] = i4; b[5] = i5; b[6] = i6;
				a[1][0] = (a[1][0] + i4 + i5) % 4;
				a[1][1] = (a[1][1] + i5) % 4;
				a[1][2] = (a[1][2] + i5 + i6) % 4;
				a[2][0] = (a[2][0] + i4) % 4;
				a[2][1] = (a[2][1] + i5) % 4;
				a[2][2] = (a[2][2] + i6) % 4;
				i7 = (4 - a[1][0]) % 4;
				i9 = (4 - a[1][2]) % 4;
				b[7] = i7; b[9] = i9;

				if ((a[1][1] + i7 + i9) % 4 == 0) {
					a[2][0] = (a[2][0] + i7) % 4;
					a[2][1] = (a[2][1] + i7 + i9) % 4;
					a[2][2] = (a[2][2] + i9) % 4;
					if ((a[2][0] == a[2][1]) && (a[2][1] == a[2][2])) {
						b[8] = (4 - a[2][0]) % 4;

						N = b[1] + b[2] + b[3] + b[4] + b[5] + b[6] + b[7] + b[8] + b[9];
						if (N <t) {
							t = N;
							for (int i = 1; i <= 9; i++)tmp[i] = b[i];
						}
					}



				}
			}
	for (int i = 1; i <= 9; i++) {
		while (tmp[i]--) {
			cout << i << " ";
		}
	}
	return 0;
}