#include<iostream>
using namespace std;
int climb(int n) {
	if (n == 0)return 1;
	if (n == 1)return 1;
	else if (n >= 2)return climb(n - 1) + climb(n - 2);

}
int main() {
	cout << "��Ҫ�ߵ�̨����" << endl;
	int n;
	cin >> n;
	cout<<"��Ҫ�ߵ�̨������"<<climb(n)<<"���߷�"<<endl;
	return 0;
}