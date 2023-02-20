#include<stdio.h>#include<string.h>#include <stdlib.h>typedef struct wd {	char s;	struct wd* next;	struct wd* pre;}wd;wd* head;int M;void CreatList(wd*& p, char s){	wd* body = (wd*)malloc(sizeof(wd));	body->pre = NULL;	body->next = NULL;	body->s = s;	if (p == head) {		/*直接前趋结点的next指针指向新结点*/		p->next = body;		/*新结点指向直接前趋结点*/		body->pre = p;		/*把body指针给list返回*/		p = p->next;	}	else {		body->pre = p;		body->next = p->next;		p->next->pre = body;		p->next = body;	}}void k(wd*& p) {//当按下k键时会使当前输入光标左移一个字符位置（如果光标在文档头则不左移）	if (p->pre == NULL)return;	else {		/*if (p->next == NULL) {			p->next = p->pre->pre->next;			p->pre->pre->next = p;			p->pre->pre = p;			p->pre->next = NULL;			p->pre = p->pre->pre;		}		else {		}*/		wd* temp;		temp = p->pre;		p->pre = p;		p = temp;	}}void z(wd*& p) {//当按下z键时会使当前输入光标右移一个字符位置（如果光标在文档尾则不右移）	if (p->next == NULL)return;	else {		wd* temp;		temp = p->next;		p->next = p;		p = temp;	}}void w(wd*& p) {//当按下w键时会使当前输入光标移至文档开始位置，	while (p->pre != NULL)
	{
		p = p->pre;
	}}void s(wd*& p) {//当按下s键时会使当前输入光标移至文档尾	while (p->next != NULL)
	{
		p = p->next;
	}}void q(wd*& p) {//当按下q键时会删除当前输入光标前的一个字符	if (p->next == NULL)
	{
		p->pre->next = NULL;
		free(p);	}	else {		p->pre->next = p->next;
		p->next->pre = p->pre;
		free(p);	}}int m(wd*& p, int& M) {//当按下m键时会使输入光标在插入和改写（覆盖）状态切换（初始是插入状态）	if (M == 1) {//插入		M = 0;	}	else {//改写		p->next->next->pre = p;		p->next = p->next->next;		free(p->next);		M = 1;	}}int main() {	M = 1;	head = (wd*)malloc(sizeof(wd));	head->pre = NULL;	head->next = NULL;	head->s = NULL;	wd* p = head;	char str[50000];	int i = 0;	gets_s(str);	while (str[i] != '\0') {		if (str[i] == 'k')  k(p);		if (str[i] == 'z')  z(p);		if (str[i] == 'w') w(p);		if (str[i] == 's') s(p);		if (str[i] == 'q') q(p);		if (str[i] == 'm') M = m(p, M);		else {			CreatList(p, str[i]);		}		i++;	}	while (p->pre != NULL)
	{
		p = p->pre;
	}	while (p->next != NULL)
	{

		printf("%c", p->s);
		p = p->next;
	}	return 0;}