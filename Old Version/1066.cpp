#include<iostream>
#include<algorithm>

using namespace std;

struct node {
	int v, height;
	node *lchild, *rchild;
}*root;

node* newNode(int v) {
	node* n = new node;
	n->v = v;
	n->height = 1;
	n->lchild = NULL;
	n->rchild = NULL;
	return n;
}

int getHeight(node* root) {
	if (root == NULL) return 0;
	return root->height;
}

void updateHeight(node* root) {
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(node* root) {
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void l(node* &root) {
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void r(node* &root) {
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node* &root, int v) {
	if (root == NULL) {
		root = newNode(v);
		return;
	}
	if (v < root->v) {
		insert(root->lchild, v);
		updateHeight(root);
		if (getBalanceFactor(root) == 2) {
			if (getBalanceFactor(root->lchild) == 1) { //LL
				r(root);
			}
			else if(getBalanceFactor(root->lchild) == -1){//LR
				l(root->lchild);
				r(root);
			}
		}
	}
	else {
		insert(root->rchild, v);
		updateHeight(root);
		if (getBalanceFactor(root) == -2) {
			if (getBalanceFactor(root->rchild) == -1) { //RR
				l(root);
			}
			else if (getBalanceFactor(root->rchild) == 1) {//RL
				r(root->rchild);
				l(root);
			}
		}
	}
}

int main() {
	int num,temp;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		insert(root, temp);
	}
	cout << root->v << endl;
	system("pause");
	return 0;
}