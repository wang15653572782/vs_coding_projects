#include<iostream>
using namespace std;
class Person {
public:
	Person() {
		cout << "Person的无参构造函数的调用" << endl;

	}
	Person(int age,int height) {
		m_Age = age;
		cout << "Person的有参构造函数的调用" << endl;
		m_Height = new int(height);
	}
	Person(const Person& p) {
		cout << "Person的拷贝构造函数的调用" <<  endl;
		m_Age = p.m_Age;
		m_Height = new int(*p.m_Height);
	}
	~Person() {
		cout << "Person的析构函数的调用" << endl;
	}
	int m_Age;
	int* m_Height;
};
void test() {
	Person p1(18, 190);
	Person p2(p1);
	cout << "p1年龄为" << p1.m_Age << " p1的身高为" << *p1.m_Height << endl;
	cout << "p2年龄为" << p2.m_Age << " p2的身高为" << *p2.m_Height << endl;


}
int main() {
	test();
	system("pause");
	return 0;
}
