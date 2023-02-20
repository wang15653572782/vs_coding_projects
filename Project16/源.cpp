#include<stdio.h>
#include<stdlib.h>
#define size 50
#define max 300
int edge[size][size];
int path[size][size];
int A[size][size];
void Floyd(int n, int (*edge)[size],int (*A)[size],int (*path)[size]){
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
		A[i][j]=edge[i][j];
		if(i!=j&&A[i][j]==1){
			path[i][j]=i;
		}else{
			path[i][j]=-1;
		}
		for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		if(A[i][k]+A[k][j]<A[i][j]){
			A[i][j]=A[i][k]+A[k][j];
			path[i][j]=path[k][j];
		}
	}
}
int main() {
	int m, n;
	while (scanf_s("%d%d", &n, &m) != EOF) {
		edge[n][n] = { 0 };
		path[n][n] = { -1 };
		A[n][n] = {0};
		for (int j = 0; j < n; j++) {
			int i, k;
			scanf_s("%d%d", &i, &k);
			for (int g = 0; g < k; g++) {
				edge[i][g] = 1;
			}
		}
		Floyd(n,edge,A,path);	
		for (int i = 0; i < m; i++) {
			int a, b; 
			scanf_s("%d%d", &a, &b);
			if (path[a][b] == -1)printf("connection impossible\n");
			else {
				int k = 0;
				while (a != b) {
					b = path[a][b];
					k++;
				}
				printf("%d\n", k);
			}

		}

	}

	return 0;
}