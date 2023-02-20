#include<iostream>
#include<algorithm>
using namespace std;
struct AVLnode {
	int key;
	int height;//以该节点为根的子树高度
	AVLnode* left;
	AVLnode* right;
	AVLnode(int k, int h, AVLnode* l, AVLnode* r) {
		key = k; height = h; left = l; right = r;
	}
};
int height(AVLnode* t) { return (t == NULL) ? -1 : t->height;}
int max(int a, int b) { return (a > b) ? a : b;}
void LL(AVLnode*& A) {
	AVLnode* B = A->left;
	A->left = B->right;
	B->right = A;
	A->height = max(height(A->left), height(A->right)) + 1;
	B->height = max(height(B->left), height(B->right)) + 1;
	A = B;
}
void RR(AVLnode*& A) {
	AVLnode* B = A->right;
	A->right = B->left;
	B->left = A;
	A->height = max(height(A->left), height(A->right)) + 1;
	B->height = max(height(B->left), height(B->right)) + 1;
	A = B;
}
void LR(AVLnode*& A) {
	RR(A->left);
	LL(A);
}
void RL(AVLnode*& A) {
	LL(A->right);
	RR(A);
}
int main() {
	return 0;
}