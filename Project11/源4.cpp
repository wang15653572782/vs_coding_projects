#include<stdio.h>
#include <stdlib.h>
typedef struct stack {
	char a[100];
	int top;
 }S;
typedef struct stack {
	int b[100];
	int top;
}Q;
void Push(S &s, char p) {
	
	s.a[s.top] = p;
	s.top++;
}
void QPush(Q& s, int temp) {

	s.b[s.top] = temp;
	s.top++;
}
int QPop(Q& s) {
	int item = s.b[s.top];
	s.top--;
	return item;
}
char Pop(S &s) {
	char item = s.a[s.top];
	s.top--;
	return item;
}
int S_isempty(S& s) {
	if (s.top < 0)return 1;
	else return 0;
}
int ope(int d1, char t, int d2) {
	switch (t)
	{
	case '+': return  (d1+ d2); break;
	case '-': return  (d1 - d2); break;
	case '*': return  (d1 * d2); break;
	case '/': return  (d1 / d2); break;
	}
}
void T(S& s, Q& q) {
	char str[100],t;
	int m1,m2,m3;
	int j=0;
	scanf_s("%s", str);
	int i = 0;
	while (str[i]!= '#') {
		
		if (str[i] >= '0' && str[i] <= '9') {
			do {
				j = 10 * j +( str[i] - '0');
				i++;
			} while (str[i] >= '0' && str[i] <= '9');
			QPush(q, j);
		}
		else if (str[i]== '(')Push(s, str[i]);
		else if (str[i] == ')') {
			t = Pop(s);
			while (t != '(') {
				m1 = QPop(q);
				m1 = QPop(q);
				m3 = ope(m1, t, m2);
				QPush(q, m3);
				t = Pop(s);
			}
		}
	}
}
int main() {
	S s,q;
	
	s.top = 0;
	q.top = 0;
	
	return 0;
}