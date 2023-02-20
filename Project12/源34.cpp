#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct  tree {
	int  data;
	struct  tree* left;
	struct  tree* right;
}tree, * btree;
btree creat() {
	int g;
	scanf_s("%d", &g);
	if (g == 0)return NULL;
	tree* p = (btree)malloc(sizeof(tree));
	p->data = g;
	p->left = creat();
	p->right = creat();
	return p;
}
int  maxlen = 0;
int max = 0;
int maxpath[100] = { 0 };

int a[100];
int maxstart = 0;
int  maxend = 0;
void First(tree* t, int start, int end, int i, int f) {
	if (t == NULL)return;
	else {
		a[i] = t->data;
		if (i == 0 || f <= 0) {
			f = a[i];

			start = i;


		}
		if (f > 0) {
			f = f + a[i];

		}
		end = i;
		if ((f > max) || (f == max && end - start + 1 < maxlen)) {
			max = f;
			maxstart = start;
			maxend = end;
			maxlen = end - start + 1;


			/*for (int j = 1; j < maxlen; j++) {
				maxpath[j] = f[j] - f[j - 1];
			}*/
			/*maxpath[j] = t->data;*/

		}

		First(t->left, start, end, i + 1, f);
		First(t->right, start, end, i + 1, f);
	}
}
int main() {
	tree* root = creat();
	First(root, 0, 0, 0, 0);



	printf("%d\n", max);
	for (int d = maxstart; d <= maxend; d++) {
		if (a[d] != 0)
			printf("%d ", a[d]);
	}
	return 0;
}

