
#include<iostream>
using namespace std;
//��ָ����ʳ�Ա����
class Person {
public:

	void ShowClassName() {
		cout << "����Person��!" << endl;
	}

	void ShowPerson() {
		if (this == NULL) {
			return;
		}
		cout <<this-> mAge << endl;
	}

public:
	int mAge;
};

void test()
{
	Person* p = NULL;
	p->ShowClassName(); //��ָ�룬���Ե��ó�Ա����
	p->ShowPerson();  //���������Ա�������õ���thisָ�룬�Ͳ�������
}
//C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��
//����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��
int main() {

	test();

	system("pause");

	return 0;
}
