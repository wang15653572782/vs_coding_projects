#include<iostream>
using namespace std;
class F {
public:
	F() {
		cout << "���๹�캯���ĵ���" << endl;
		
	}
	~F() {
		cout << "�������������ĵ���" << endl;

	}
};
class son :public F 
{
public:
	son() {
		cout << "���๹�캯���ĵ���" << endl;
	}
	~son() {
		cout << "�������������ĵ���" << endl;
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