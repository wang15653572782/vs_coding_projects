#include<iostream>
using namespace std;
class Cube {
public:
	int suanS(){
		return 2 * (m_L * m_H + m_L * m_D + m_H * m_D);
	}
	int suanV() {
		return m_L * m_H * m_D;
	}
	int m_L;
	int m_H;
	int m_D;
};
bool ifsame(Cube& C1, Cube& C2) {
	if (C1.m_D == C2.m_D && C1.m_H == C2.m_H && C1.m_L == C2.m_L) {
		return true;
	}
	else return false;
}
void test() {
	Cube p1;
	p1.m_D = 1333;
	p1.m_H = 44444;
	p1.m_L = 115263712;
	Cube p2(p1);
	cout << "立方体的体积为" << p1.suanV ()<< " 立方体的表面积为" << p1.suanS();
	cout << "立方体的体积为" << p2.suanV() << " 立方体的表面积为" << p2.suanS();
	if (ifsame(p1, p2)){
		cout << "两个立方体相等" << endl;
	}
	else cout << "两个立方体不相等" << endl;
}
int main() {
	test();
	system("pause");
	return 0;
}