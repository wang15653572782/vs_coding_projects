#include<iostream>
using namespace std;
class Person {
public:
	friend ostream& operator<<(ostream& cout, Person p);
	Person() {
		num = 0;
	}
	/*Person& operator++() {
		num++;
		return *this;
	}*/
	Person operator++() {
		Person temp = *this;
		num++;
		return temp;

	}
private:
	int num;
};
ostream& operator<<(ostream& cout, Person p) {
	cout << p.num << endl;
	return cout;
}
void test() {
	Person p1;
	/*cout << p1++ << endl;*/
	cout << ++p1 << endl;
}
int main() {
	test();
	return 0;
}
