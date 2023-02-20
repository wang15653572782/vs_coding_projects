#include<stdio.h>
#include<stdlib.h>
#define size 105
typedef struct Edge {
	int VerAdj;
	struct Edge* link;
}Edge;
typedef struct Vertex {
	int VerName;
	Edge* adjacent;
}Vertex;
Vertex head[size];
int count[size];
void toposort(Vertex head[], int n) {
	int k, top;
	Edge* p;
	for (int i = 1; i <= n; i++)count[i] = 0;
	for (int i = 1; i <= n; i++) {
		p = head[i].adjacent;
		while (p) {
			k = p->VerAdj; count[k] = count[k] + 1; p = p->link;
		}
	}
	top = -1; int M = 0;
	for (int i = 1; i <= n; i++) {
		if (count[i] == 0) {
			count[i] = top; top = i;

		}
	}
	int flag = 0;
	for (int i = 1; i <n; i++) {
		if (top == -1) { printf("0"); return; }//有环
		M = 0;
		int j = top; top = count[top];//选出入度为0
		p = head[j].adjacent;
		while (p) {
			k = p->VerAdj; count[k] = count[k] - 1;
			if (count[k] == 0) {
				M++;
				count[k] = top; top = k;
			}
			p = p->link;
		}

		if (M != 1)flag = 1;
	}
	if (flag == 1)printf("2\n");
	if (flag==0)printf("1\n");
}

int main() {
	int m, n;

	while (scanf_s("%d%d", &n, &m) != EOF) {

		for (int i = 1; i < size; i++) {
			head[i].adjacent = NULL;
			count[i] = 0;
		}

		for (int i = 0; i < m; i++) {
			int d, u;
			scanf_s("%d%d", &d, &u);
			Edge* p = (Edge*)malloc(sizeof(Edge));
			p->VerAdj = u;
			p->link = head[d].adjacent;
			head[d].adjacent = p;

		}
		toposort(head, n);
	}
	return 0;
}
