#include<iostream>
using namespace std;
class Person {
public:
	Person() {
		cout << "Person���޲ι��캯���ĵ���" << endl;

	}
	Person(int age,int height) {
		m_Age = age;
		cout << "Person���вι��캯���ĵ���" << endl;
		m_Height = new int(height);
	}
	Person(const Person& p) {
		cout << "Person�Ŀ������캯���ĵ���" <<  endl;
		m_Age = p.m_Age;
		m_Height = new int(*p.m_Height);
	}
	~Person() {
		cout << "Person�����������ĵ���" << endl;
	}
	int m_Age;
	int* m_Height;
};
void test() {
	Person p1(18, 190);
	Person p2(p1);
	cout << "p1����Ϊ" << p1.m_Age << " p1�����Ϊ" << *p1.m_Height << endl;
	cout << "p2����Ϊ" << p2.m_Age << " p2�����Ϊ" << *p2.m_Height << endl;


}
int main() {
	test();
	system("pause");
	return 0;
}
