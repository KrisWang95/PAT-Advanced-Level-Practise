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
	int key;

	node* lchild, *rchild;

	node(int x): key(x),lchild(NULL), rchild(NULL){}

};

void insert(node* &root, int k) {

	if (root == NULL) {

		root = new node(k);

		return;

	}

	if (k <= root->key) {

		insert(root->lchild, k);

	}
	else {

		insert(root->rchild, k);
	}

}

vector<int> levelNum;

int maxDepth = -1;

void dfs(node* root, int depth) {

	if (root == NULL) return;

	levelNum[depth]++;

	maxDepth = max(maxDepth, depth);

	dfs(root->lchild, depth + 1);

	dfs(root->rchild, depth + 1);


}


int main() {

	int n;

	cin >> n;

	levelNum.resize(n, 0);

	node * root = NULL;

	for (int i = 0; i < n; i++) {

		int temp;

		cin >> temp;

		insert(root, temp);

	}

	dfs(root, 0);

	cout << levelNum[maxDepth] << " + " << levelNum[maxDepth - 1] << " = "<< levelNum[maxDepth] + levelNum[maxDepth-1];


	system("pause");

	return 0;
}