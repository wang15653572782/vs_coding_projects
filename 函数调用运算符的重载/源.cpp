#include<iostream>
using namespace std;
#include<string>
class Myprint {
public:
	void operator()(string test) {
		cout << test << endl;
	}
};
void test01() {
	Myprint p;
	p("WCFNB");
}
class Add {
public:
	int operator()(int p1, int p2) {
		return p1 + p2;
	}
};
void test02() {
	Add L;
	cout<<L(1000, 2345)<<endl;
}
int main() {
	test01();
	test02();
	return 0;
}