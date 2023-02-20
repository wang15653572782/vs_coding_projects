#include<iostream>
#include<algorithm>
using namespace std;
struct movie {
	int s;
	int e;
	bool operator<(const movie& c) {
		return e <= c.e;
	}
}movies[105];
int main() {
	int n;
	while ((cin >> n) && n) {
		for (int i = 0; i < n; ++i)cin >> movies[i].s >> movies[i].e;
		sort(movies, movies + n);
		int count = 1;
		int flag = movies[0].e;
		for (int i = 1; i < n; ++i) {
			if (movies[i].s >= flag) {
				++count;
				flag = movies[i].e;
			}
		}
		cout << count << endl;
	}
	return 0;
}