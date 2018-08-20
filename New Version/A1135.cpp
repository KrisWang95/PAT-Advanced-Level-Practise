#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
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

	int key;

	node *left, *right;

	node(int x):key(x),left(NULL),right(NULL){}

};

vector<int> pre;

bool isBST = true;

node* build(int preL, int preR) {

	if (preL > preR) return NULL;

	node* root = new node(pre[preL]);

	int k = preL + 1;

	for (;k <= preR && abs(pre[k]) < abs(pre[preL])  ; k++);

	int l = k;

	for (; l <= preR && abs(pre[l]) > abs(pre[preL]); l++);

	if (l != preR + 1) {

		isBST = false; 

		return NULL;

	}

	root->left = build(preL + 1, k - 1);

	root->right = build(k, preR);

	return root;

}

bool checkValid1(node* root) {

	if (root == NULL) return true;

	if (root->key < 0) {

		if (root->left && root->right) return (root->left->key > 0 && root->right->key > 0);

		else if (root->left && root->right == NULL) return root->left->key > 0;

		else if (root->left == NULL && root->right) return root->right->key > 0;

		else return true;

	}

	return checkValid1(root->left) && checkValid1(root->right);

}

set<int> s;

void dfs(node* root, int cnt) {

	if (root == NULL) {

		s.insert(cnt);

		return;
	}

	if (root->key > 0) {

		dfs(root->left, cnt + 1);

		dfs(root->right, cnt + 1);

	}
	else {

		dfs(root->left, cnt);

		dfs(root->right, cnt);

	}

}

bool checkValid2(node* root) {

	s.clear();

	dfs(root, 0);

	return s.size() == 1;
}



int main() {

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {

		int tn;

		cin >> tn;

		pre.resize(tn);

		for (int j = 0; j < tn; j++) {

			cin >> pre[j];

		}

		node* root = build(0, tn - 1);

		bool tag = checkValid1(root);

		bool flag = checkValid2(root);

		if (isBST && pre[0] > 0 && tag && flag) cout << "Yes\n";

		else cout << "No\n";


	}



	system("pause");

	return 0;
}