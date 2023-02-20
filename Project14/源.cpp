#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct  tree {
	int  weight;
	char info;
	int first;
	struct tree* llink;
	struct tree* rlink;
}tree, * htree;
int WPL;
htree t;
htree huffman(htree H, int m) {
	WPL = 0;
	for (int i = 0; i < m; i++) {
		H[i].llink = NULL;
		H[i].rlink = NULL;
	}
	for (int i = 0; i < m; i++) {
		t = (htree)malloc(sizeof(tree));
		t->weight = H[i].weight + H[i + 1].weight;
		WPL = WPL + H[i].weight + H[i + 1].weight;
		t->llink = H + i;
		t->rlink = H + i + 1;
		int j = i + 2;
		while (t->weight >= H[j].weight && j <= m - 1) {
			H[j - 1] = H[j];
			j++;
		}
		H[j - 1] = *t;

	}
	return t;
}//构建哈夫曼树
void translate(tree* t, char str[], int l) {
	int jl = 0;
	while (jl < l) {
		if (str[jl] == '0')t->llink;
		if (str[jl] == '1')t->rlink;
		if (t->llink == NULL && t->rlink == NULL) {
			printf("%c", t->info);
		}
		jl++;
	}
	printf("\n");
	if (!(t->llink == NULL && t->rlink == NULL) && str[jl] != '\0')
		printf("\nINVALID\n");
}
int ll;
int str1[26][1000];
int str2[26] = { 0 };
int M = 0;
int code[1000];
void Preorder(tree* t, int tt) {
	if (t == NULL)return;

	if (tt == 0 || tt == 1) {

		code[M] = tt;
		M++;
		if (t->llink == NULL && t->rlink == NULL) {
			ll = t->info - 'a';
			str2[ll] = M;
			for (int i = 0; i < M; i++) {
				str1[ll][i] = code[i];
			}
		}
	}
	Preorder(t->llink, 0);
	if (t->llink != NULL && t->rlink != NULL)
		M--;
	Preorder(t->rlink, 1);
	if (t->llink != NULL && t->rlink != NULL)
		M--;
}//先根遍历编码
char str[26];
int main() {
	int n;
	int m;

	tree c[26];
	char a[6000];
	char x[6000], y[6000];
	scanf_s("%s", a);
	for (int i = 0; i < 26; i++) {
		c[i].weight = 0;
	}
	n = strlen(a);
	int b[26] = { 0 };
	for (int i = 0; i < n; i++) {
		b[a[i] - 'a']++;
	}//记录各字母出现个数
	int ja = 0;
	for (int i = 0; i < 26; i++) {
		if (b[i] != 0)
			ja++;
		//	printf("%d",b[i]);
	}
	m = ja;
	int j = 0;
	for (int i = 0; i < n; i++) {
		while ((b[a[i] - 'a'] != 0) && (j < 26)) {
			c[j].info = a[i];
			c[j].weight = b[a[i] - 'a'];
			j++;
			b[a[i] - 'a'] = 0;
		}
	}//记录指针信息	
	tree e;
	int k = 1;
	while (k == 1) {
		k = 0;
		for (int i = 0; i < m - 1; i++)
			if (c[i].weight > c[i + 1].weight) {
				e = c[i]; c[i] = c[i + 1]; c[i + 1] = e;
				k = 1;
			}
	}
	//冒泡排序

	for (int i = 0; i < m; i++) {

		str[i] = c[i].info;

	}
	htree s = huffman(c, m);
	int temp;
	printf("%d", s->rlink->weight);
	printf("%d", WPL);
	if (WPL % 8 != 0) {
		temp = WPL / 8 + 1;
	}
	else temp = WPL / 8;
	printf("%d %d\n", n, temp);

	Preorder(s, 2);
	for (int i = 0; i < m; i++) {
		printf("%c:", str[i]);
	}
	for (int i = 0; i < m; i++) {
		printf("%c:", str[i]);
		for (int g = 0; g < str2[str[i] - 'a']; g++) {
			printf("%d", str1[str[i] - 'a'][g]);
		}
		printf("\n");
	}

	/*scanf("%s", x);
	scanf("%s", y);
	int X = strlen(x);
	int Y = strlen(y);
	translate(s, x, X);
	translate(s, y, Y);*/
	return 0;
}
