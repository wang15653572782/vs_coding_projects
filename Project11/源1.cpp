#include<stdio.h>#include<string.h>#include <stdlib.h>typedef struct wd {	char s;	struct wd* next;	struct wd* pre;}wd;wd* head;int M;void CreatList(wd*& p, char s){	wd* body = (wd*)malloc(sizeof(wd));	body->pre = NULL;	body->next = NULL;	body->s = s;	if (p == head) {		/*ֱ��ǰ������nextָ��ָ���½��*/		p->next = body;		/*�½��ָ��ֱ��ǰ�����*/		body->pre = p;		/*��bodyָ���list����*/		p = p->next;	}	else {		body->pre = p;		body->next = p->next;		p->next->pre = body;		p->next = body;	}}void k(wd*& p) {//������k��ʱ��ʹ��ǰ����������һ���ַ�λ�ã����������ĵ�ͷ�����ƣ�	if (p->pre == NULL)return;	else {		/*if (p->next == NULL) {			p->next = p->pre->pre->next;			p->pre->pre->next = p;			p->pre->pre = p;			p->pre->next = NULL;			p->pre = p->pre->pre;		}		else {		}*/		wd* temp;		temp = p->pre;		p->pre = p;		p = temp;	}}void z(wd*& p) {//������z��ʱ��ʹ��ǰ����������һ���ַ�λ�ã����������ĵ�β�����ƣ�	if (p->next == NULL)return;	else {		wd* temp;		temp = p->next;		p->next = p;		p = temp;	}}void w(wd*& p) {//������w��ʱ��ʹ��ǰ�����������ĵ���ʼλ�ã�	while (p->pre != NULL)
	{
		p = p->pre;
	}}void s(wd*& p) {//������s��ʱ��ʹ��ǰ�����������ĵ�β	while (p->next != NULL)
	{
		p = p->next;
	}}void q(wd*& p) {//������q��ʱ��ɾ����ǰ������ǰ��һ���ַ�	if (p->next == NULL)
	{
		p->pre->next = NULL;
		free(p);	}	else {		p->pre->next = p->next;
		p->next->pre = p->pre;
		free(p);	}}int m(wd*& p, int& M) {//������m��ʱ��ʹ�������ڲ���͸�д�����ǣ�״̬�л�����ʼ�ǲ���״̬��	if (M == 1) {//����		M = 0;	}	else {//��д		p->next->next->pre = p;		p->next = p->next->next;		free(p->next);		M = 1;	}}int main() {	M = 1;	head = (wd*)malloc(sizeof(wd));	head->pre = NULL;	head->next = NULL;	head->s = NULL;	wd* p = head;	char str[50000];	int i = 0;	gets_s(str);	while (str[i] != '\0') {		if (str[i] == 'k')  k(p);		if (str[i] == 'z')  z(p);		if (str[i] == 'w') w(p);		if (str[i] == 's') s(p);		if (str[i] == 'q') q(p);		if (str[i] == 'm') M = m(p, M);		else {			CreatList(p, str[i]);		}		i++;	}	while (p->pre != NULL)
	{
		p = p->pre;
	}	while (p->next != NULL)
	{

		printf("%c", p->s);
		p = p->next;
	}	return 0;}