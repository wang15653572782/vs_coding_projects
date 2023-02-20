#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct node {
	struct node* next[36]={0};
	int nextcnt = 0;
	int if_end=0;//是否为最后一个
	 int times=0;
	char word[30]="";
	node* topk[11] = { 0 };
	int topkcnt = 0;
}Tnode,*Tnodeptr;
typedef struct word {
	int i;
	char x[20];
	long long int times;
}word, * wordp;

void insert(Tnodeptr root, char word[30], int times) {
	Tnodeptr tmp = root;
	int len = strlen(word);
	for (int i = 0; i < len;++i) {
		char ch = word[i];
		int pos;
		if (ch >= '0' && ch <= '9')pos = ch - '0';
		else pos = ch - 'a' + 10;
		if (tmp->next[pos] == NULL) {
			tmp->next[pos] = new Tnode;
			tmp->nextcnt++;
		}
		tmp = tmp->next[pos];
	}
	if (tmp->if_end == 1) {
		if (times > tmp->times)tmp->times = times;
	}
	else {
		tmp->if_end = 1;
		tmp->times = times;
	}
	strcpy_s(tmp->word, word);
	
}
void findtopk(Tnodeptr p,int depth, Tnodeptr R[], int& n, int k) {
	depth++;
	if (depth++ && p->if_end == 1) {
		int e = p->times;
		int i = n - 1;
		while (i >= 0 && e > R[i]->times) {
			R[i + 1] = R[i];
			--i;
		}
		R[i + 1] = p;
		if (n < k)++n;
	}
	for (int i = 0; i < 36; ++i) {
		if (p->next[i] != NULL)findtopk(p->next[i], depth, R, n, k);
	}
}
void find(Tnodeptr root, char word[30], int k) {
	Tnodeptr tmp = root;
	int len = strlen(word);
	for (int i = 0; i < len; ++i) {
		char ch = word[i];
		int pos;
		if (ch >= '0' && ch <= '9')pos = ch - '0';
		else pos = ch - 'a' + 10;
		if (tmp->next[pos] == NULL) {
			printf("no suggestion\n");
			return;
		}
		tmp = tmp->next[pos];
	}
	if (tmp->nextcnt == 0) {
		printf("no suggestion\n");
		return;
	}
	if (tmp->topkcnt == 0) {
		findtopk(tmp, 0, tmp->topk,tmp->topkcnt,k);
	}
	for (int i = 0; i < tmp->topkcnt; ++i) {
		printf("%s\n", tmp->topk[i]->word);
	}
}
int main() {
	freopen("in.txt", "r", stdin);
	Tnodeptr root =new Tnode;
	int n, m, k;
	scanf_s("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		 int times;
		 scanf_s("%d", &times);
		char x[30];
		scanf_s("%s",x);
		insert(root, x, times);
	}
	for (int i = 0; i < m; ++i) {
		char y[30];
		scanf_s("%s",y);
		 find(root, y,k);
		 if (i < m - 1)printf("\n");

	}
	return 0;
}