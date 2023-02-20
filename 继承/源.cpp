#include<iostream>
using namespace std;
class F {
public:
	F() {
		cout << "父类构造函数的调用" << endl;
		
	}
	~F() {
		cout << "父类析构函数的调用" << endl;

	}
};
class son :public F 
{
public:
	son() {
		cout << "子类构造函数的调用" << endl;
	}
	~son() {
		cout << "子类析构函数的调用" << endl;
	}

};
void test() {
	
	
	son p1;
	p1;

}
int main() {
	test();
	return 0;
}