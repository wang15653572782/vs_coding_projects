#include<iostream>
using namespace std;
int i = 0;
void Hanoi(int n, char src, char mid, char dest,int s) {
	if (n == 1) {
		cout <<s<<":"<< src << "->" << dest << endl;
		return;
	}
	Hanoi(n - 1, src, dest, mid,s);
	cout << s+n-1<<":"<<src << "->" << dest << endl;
	Hanoi(n - 1, mid, src, dest,s);
	return;
}
int main() {
	int n;
	cin >> n;
	char a, b, c;
	cin >> a >> b >> c;
	Hanoi(n, a, b,c,1);
	
	return 0;
}