#include<stdio.h>
#include<stdlib.h>
#define size 20000
#define max 9999999999
typedef struct Edge {
	int VerAdj;
	int cost;
	struct Edge* link;
}Edge;
typedef struct Vertex {
	int VerName;
	Edge* adjacent;
}Vertex;
Vertex head[size];
int path[size];
int path1[size] = { -1 };
int path2[size] = { -1 };
int dist[size];
int count[size] = { 0 };
int sb[size] = { -1 };
int W[size] = { -1 };
	void Dijk(Vertex head[], int n, int s, int dist[], int path[]) {
		int S[size]; int v = 0; int w;int c = 0; int m,mn;
	count[s] = 1;
		for (int i = 1; i <= n; i++) {
			path[i] = -1; dist[i] = max; S[i] = 0;
		}
		dist[s] = 0;
		for (int j = 1; j <= n; j++) {
			int min = max;
			for (int i = 1; i <= n; i++)
				if (S[i] == 0 && dist[i] < min) {
					min = dist[i]; v = i;
				}
			S[v] = 1;
			Edge* p = head[v].adjacent;
			while (p) {
				w = p->VerAdj;
				if (S[w] == 0 && dist[v] + p->cost < dist[w] || dist[v] + p->cost == dist[w]) {
					dist[w] = dist[v] + p->cost; path[w] = v;
				}
				p = p->link;
			}

		}
	}
					/*if (dist[v] + p->cost == dist[w] ) {
						m = w; mn = v;
						int g = w;
						if (count[v] + 1 < count[w]) {
							
							while (mn!=s) {
								path[m] = mn;
								m = mn; mn = path[n];
							}
						}
						if (count[v] + 1 == count[w]) {
							int M = count[w];
							while (mn != s) {
								path1[count[mn]-1] = mn;
								mn= path[mn];
							}
						m= path[m];
							while (m != s) {						
								path2[count[m] - 1] = m; m = path[m];
							}
							int i = 1;
							for ( i = 1; path1[i]==path2[i]; i++){}
							if (path1[i] > path2[i]) {
								for(int j=0;path[g]!=0;j++)
								path[g] = path2[count[v]-1-j];
								g = path[g];
							}
							else {
								for (int j = 0; path[g] != 0; j++)
									path[g] = path1[count[v] - 1 - j];
								g = path[g];

							}

						}
					}*/
					
int main(){
	int n, e;
	scanf_s("%d%d", &n, &e);
	for (int i = 0; i < n; i++)
		head[i].adjacent = NULL;
	for (int i = 0; i < e; i++) {
		int a;
		int b, c;
		scanf_s("%d%d%d", &a, &b, &c);
		head[a].VerName = a;
		if (head[a].adjacent == NULL) {
			Edge* p = (Edge*)malloc(sizeof(Edge));
			p->VerAdj = b;
			p->cost = c;
			p->link = NULL;
			head[a].adjacent = p;

		}
		else {
			Edge* p = (Edge*)malloc(sizeof(Edge));
			p->VerAdj = b;
			p->cost = c;
			p->link = head[a].adjacent->link;
			head[a].adjacent = p;
		}
	}
	Dijk(head, n, 0, dist, path);
	for (int i = 1; i < n; i++) {
		
		printf("%d", path[k]);
	}
		/*while (k != 0) {
			W[count[k] - 1] = k;
			k = path[k];
		}
		printf("0");
		for (int jl = 1; jl < count[i]; jl++) {
			printf("->%d", W[jl]);
		}
		printf("\n");
	}*/
	return 0;
}
