#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<math.h>
using namespace std;
double exp() {
	//����һ���沨�����ʽ����������ֵ
	char s[20];
	cin >> s;
	switch (s[0]) {
	case '+': return exp() + exp();
	case '-': return exp() - exp();
	case '*': return exp() * exp();
	case '/': return exp() / exp();
	default: return atof(s);
		break;
	}
}
int main()
{
	
	printf("%lf", exp());
	return 0;
}