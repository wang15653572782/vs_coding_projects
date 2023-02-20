#include<iostream>
using namespace std;
#include<string>
class Person {
public:
	Person(string name, int age) {
		m_Name = name;
		m_Age = age;
	}
	bool operator>(Person& p) {
		if (m_Age > p.m_Age)return true;
		else return false;
	}



	string m_Name;
	int m_Age;
};
void test() {
	Person p1("Jack", 19);
	Person p2("Miro", 20);
	if (p1 > p2)cout << p1.m_Name << "的年龄大" << endl;
	else 
		cout << p2.m_Name << "的年龄大" << endl;
}
int main() {
	test();
	return 0;
}