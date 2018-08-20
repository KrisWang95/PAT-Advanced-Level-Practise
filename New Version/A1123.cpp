#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cctype>
#include<climits>
#include<algorithm>
#include<cmath>
#define _CRT_SECURE_NO_WARNINGS
#define inf INT_MAX 
using namespace std;

struct node {

	int key, height = 1;
	                                                                                                                                                                                                                                                                                                                                                                                                                                            
	node *lchild, *rchild;

	node(int k) :key(k), lchild(NULL),rchild(NULL){}

};

int getHeight(node* root) {

	if (root == NULL) return 0;
	
	else return root->height;
	
}

void updateHeight(node* root) {

	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;

}

int getBalanceFactor(node* root) {

	return getHeight(root->lchild) - getHeight(root->rchild);

}

void l(node* &root) { //RR

	node* temp = root->rchild;

	root->rchild = temp->lchild;

	temp->lchild = root;

	updateHeight(root);

	updateHeight(temp);

	root = temp;

}

void r(node* &root) { //LL

	node* temp = root->lchild;

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

	if (k < root->key) {

		insert(root->lchild, k);

		updateHeight(root);

		if (getBalanceFactor(root) == 2) {

			if (getBalanceFactor(root->lchild) == 1) {//LL

				r(root);

			}
			else if (getBalanceFactor(root->lchild) == -1) {//LR

				l(root->lchild);

				r(root);

			}

		}


	}
	else {

		insert(root->rchild, k);

		updateHeight(root);

		if (getBalanceFactor(root) == -2) {

			if (getBalanceFactor(root->rchild) == -1) {//RR

				l(root);

			}
			else if (getBalanceFactor(root->rchild) == 1) {//RL

				r(root->rchild);

				l(root);

			}

		}

	}

}

bool isComplete = true;

vector<int> level;

void getLevel(node* root){

	queue<node*> q;

	q.push(root);

	bool isNULL = false;


	while (!q.empty()) {

		node* temp = q.front(); q.pop();

		level.push_back(temp->key);

		if (temp->lchild) {

			if (isNULL) isComplete = false;

			q.push(temp->lchild);


		}
		else {

			isNULL = true;
		}

		if (temp->rchild) {

			if (isNULL) isComplete = false;

			q.push(temp->rchild);


		}
		else {

			isNULL = true;
		}


	}



}



int main() {

	int n;

	cin >> n;

	node* root = NULL;

	for (int i = 0; i < n; i++) {

		int temp;

		cin >> temp;

		insert(root, temp);

	}

	getLevel(root);

	for (int i = 0; i < level.size(); i++) {
		if (i == 0) cout << level[i];

		else cout << " " << level[i];
		
	}

	cout << endl << (isComplete ?  "YES" : "NO");



	system("pause");

	return 0;
}