#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

struct node{

	int k, height = 1;

	node *lchild, *rchild;

	node(int x) : k(x), lchild(NULL),rchild(NULL) {}

};

int getHeight(node * root) {
	if (root == NULL) return 0;
	else return root->height;
}

void updateHeight(node *root) {

	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;

}

int getBalanceFactor(node *root) {
	if(root) return getHeight(root->lchild) - getHeight(root->rchild);
	else return 0;
}

void l(node* &root) { //rr

	node *temp = root->rchild;

	root->rchild = temp->lchild;

	temp->lchild = root;

	updateHeight(root);

	updateHeight(temp);

	root = temp;

}

void r(node* &root) { //ll

	node *temp = root->lchild;

	root->lchild = temp->rchild;

	temp->rchild = root;

	updateHeight(root);

	updateHeight(temp);

	root = temp;

}

void insert(node* &root, int k) {
	if (root == NULL) {

		root = new node(k);

		return;

	}

	if (k < root->k) {

		insert(root->lchild, k);

		updateHeight(root);

		if (getBalanceFactor(root) == 2) {

			if (getBalanceFactor(root->lchild) == 1) {//ll

				r(root);

			}
			else if (getBalanceFactor(root->lchild) == -1) {//lr

				l(root->lchild);

				r(root);

			}
		}

	}
	else {

		insert(root->rchild, k);

		updateHeight(root);

		if (getBalanceFactor(root) == -2) {

			if (getBalanceFactor(root->rchild) == -1) {//rr

				l(root);

			}
			else if (getBalanceFactor(root->rchild) == 1) {//rl

				r(root->rchild);

				l(root);

			}
		}

	}
}

int main() {

	node* root = NULL;

	int num;

	cin >> num;

	for (int i = 0; i < num; i++) {

		int temp;

		cin >> temp;

		insert(root, temp);
	}


	cout << root->k << endl;
	

	system("pause");

	return 0;

}