#include<iostream>
using namespace std;
int climb(int n) {
	if (n == 0)return 1;
	if (n == 1)return 1;
	else if (n >= 2)return climb(n - 1) + climb(n - 2);

}
int main() {
	cout << "你要走的台阶数" << endl;
	int n;
	cin >> n;
	cout<<"你要走的台阶数有"<<climb(n)<<"种走法"<<endl;
	return 0;
}