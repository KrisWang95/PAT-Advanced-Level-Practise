#include<iostream>
#include<queue>
#define maxn 50
using namespace std;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
int post[maxn], in[maxn], numNode, num = 0;

node* post_in_creat(int postL, int postR, int inL, int inR) {
	if (postL > postR || inL > inR) return NULL;
	node* root = new node;
	//从后序序列找到根结点
	root->data = post[postR];
	//从前序序序列找到根节点，并计算左子树的结点数
	int k ;
	for (k = inL; k <= inR; k++) {
		if (in[k] == post[postR]) {
			break;
		}
	}
	int numLeft = k - inL;
	//递归建立左子树
	root->lchild = post_in_creat(postL, postL + numLeft - 1, inL, k - 1);
	//递归建立右子树
	root->rchild = post_in_creat(postL + numLeft, postR - 1, k + 1, inR);
	return root;
}
void bfs(node* n) {
	queue<node*> q;
	q.push(n);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		printf("%d", temp->data);
		num++;
		if (num < numNode) printf(" ");
		if (temp->lchild != NULL) q.push(temp->lchild);
		if (temp->rchild != NULL) q.push(temp->rchild);
	}
}
int main() {
	cin >> numNode;
	for (int i = 0; i < numNode; i++) {
		cin >> post[i];
	}
	for (int i = 0; i < numNode; i++) {
		cin >> in[i];
	}
	bfs(post_in_creat(0, numNode - 1, 0, numNode - 1));
	system("pause");
	return 0;
}