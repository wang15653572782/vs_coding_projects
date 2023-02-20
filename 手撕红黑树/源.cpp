#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const bool BLACK = true, RED = false;
struct RBNode {
	int key;
	bool color;
	RBNode* left;
	RBNode* right;
	RBNode* parent;
	RBNode(int x, RBNode* p = NULL, RBNode* l = NULL, RBNode* r = NULL, bool c = RED) {
		key = x, parent = p; left = l; right = r; color = c;
	}
};
bool IsBlack(RBNode* x) { return (x == NULL || x->color == BLACK); }
bool IsRed(RBNode* x) { return !IsBlack(x); }
bool IsLChild(RBNode* x) { return (x != NULL && x->parent != NULL && x == x->parent->left); }
bool IsRChild(RBNode* x) { return (x != NULL && x->parent != NULL && x == x->parent->right); }
void LL(RBNode*& A) {
	RBNode* B = A->left;
	A->left = B->right;
	if (B->right != NULL)B->right->parent = A;
	B->right = A;
	B->parent = A->parent;
	A->parent = B;
	A = B;
}
void RR(RBNode*& A) {
	RBNode* B = A->right;
	A->right = B->left;
	if (B->left != NULL)B->left->parent = A;
	B->left = A;
	B->parent = A->parent;
	A->parent = B;
	A = B;
}
void LR(RBNode*& A) {
	RR(A->left);
	LL(A);
}
void RL(RBNode*& A) {
	LL(A->right);
	RR(A);
}
RBNode*& search(RBNode*& root, int K,RBNode*& parent){
	if (root == NULL || root->key == K) { parent = NULL; return root; }
	parent = root;
	while (true) {
		RBNode*& ch = (K < parent->key) ? parent->left : parent->right;
		if (ch == NULL || ch->key == K)return ch;
		parent = ch;
	}
}
void insertAdjust(RBNode*& root, RBNode* x) {
	if (x->parent == NULL) { root->color = BLACK; return; }
	RBNode* p = x->parent;
	if (IsBlack(p))return;
	RBNode* g = p->parent;
	RBNode* u = IsLChild(p) ? g->right : g->left;
	if (IsBlack(u)) {
		RBNode* gg = g->parent;
		RBNode*& subroot = (gg == NULL) ? root : (IsLChild(g)) ? gg->left : gg->right;
		if (IsLChild(p) && IsLChild(x))LL(subroot);
		else if (IsRChild(p) && IsRChild(x))RR(subroot);
		else if (IsLChild(p) && IsRChild(x))LR(subroot);
		else RL(subroot);
		subroot->color = BLACK;
		subroot->left->color = subroot->right->color = RED;
	}
	else {
		p->color = u->color = BLACK;
		if (g->parent != NULL)g->color = RED;
		insertAdjust(root, g);
	}
}
void insert(RBNode*& root, int K) {
	RBNode* pa;
	RBNode*& x = search(root, K, pa);
	if (x != NULL)return;
	x = new RBNode(K, pa);
	insertAdjust(root, x);
}
void removeAdjust(RBNode*& root, RBNode* r,RBNode* p) {
	if (p == NULL)return;
	RBNode* s = (r == p->left) ? p->right : p->left;
	RBNode* g = p->parent;
	RBNode*& subroot = (g == NULL) ? root : (IsLChild(p) ? g->left : g->right);
	if (IsBlack(s)) {
		if (IsRed(s->left) || IsRed(s->right)) {
			bool oldColor = p->color;
			if (IsLChild(s) && IsRed(s->left))LL(subroot);
			else if (IsRChild(s) && IsRed(s->right))RR(subroot);
			else if (IsLChild(s) && IsRed(s->right))LR(subroot);
			else RL(subroot);
			subroot->color = oldColor;
			subroot->left->color = subroot->right->color = BLACK;
		}
		else {
			s->color = RED;
			if (IsRed(p))p->color = BLACK;
			else removeAdjust(root, p, g);
		}
	}
	else {
		if (IsLChild(s))LL(subroot);
		else RR(subroot);
		s->color = BLACK; p->color = RED;
		removeAdjust(root, r, p);
	}
}
void remove(RBNode*& root, int K) {
	RBNode* pa;
	RBNode*& p = search(root, K, pa);
	if (p == NULL)return;
	RBNode* x = p, * r = NULL;
	if (p->left != NULL && p->right != NULL) {
		x = p->right;
		while (x->left != NULL)x = x->left;
		p->key = x->key;
		r = x->right;
		if (x->parent == p)x->parent->right = r;
		else x->parent->left = r;
	}
	else {
		r=p = (p->left != NULL) ? p->left : p->right;
	}
	if (r != NULL)r->parent = x->parent;
	if (IsBlack(x) && IsRed(r))r->color = BLACK;
	else if (IsBlack(x) && IsBlack(r))removeAdjust(root, r,x->parent);
	delete x;
}
void PreOrder(RBNode* p) {
	if (p == NULL)return;
	printf("%d %c ", p->key, (p->color==BLACK)?'B':'R');
	PreOrder(p->left);
	PreOrder(p->right);
}
void InOrder(RBNode* p) {
	if (p == NULL)return;
	InOrder(p->left);
	printf("%d %c ", p->key, (p->color == BLACK) ? 'B' : 'R');
	InOrder(p->right);
}

int main() {
	RBNode* t = NULL;
	freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	char sip[10]; int k;
	for (int i = 0; i < T; ++i) {
		scanf("%s", sip);
		scanf("%d", &k);
		if (sip[0] == 'I') { insert(t, k); }
		else remove(t, k);
	}
	InOrder(t);
	cout <<"\n"<<endl;
	PreOrder(t);
	return 0;
}

