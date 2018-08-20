#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	long long key;
	node* lchild, *rchild;
};
map<long long, int> m;
long long num, k, a, b;
vector<int> pre;

node* newNode(int k) {
	node * n = new node;
	n->key = k;
	n->lchild = n->rchild = NULL;
	return  n;
}

node* insert(int preL ,int preR) {
	if (preL > preR) {
		return NULL;
	}
	node* root = newNode(pre[preL]);

	int k = preL+1;

	while (k <= preR) {
		if (pre[k] < pre[preL]) k++;
		else break;
	}

	root->lchild = insert(preL + 1, k - 1);

	root->rchild = insert(k, preR);
	
	return root;
}

node *findCom(node *root) {
	if (root->key<min(a, b)) return findCom(root->rchild);
	else if (root->key>max(a, b)) return findCom(root->lchild);
	else return root;
}

int main() {
	
	cin >> k >> num;

	node* root = NULL;

	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;

		m[temp] = 1;

		pre.push_back(temp);

	}

	root = insert(0, num - 1);


	for (int i = 0; i < k; i++) {
		scanf("%lld%lld", &a, &b);
		bool f1 = ( m[a] != 1),f2 = (m[b] != 1);
		if (f1&& f2) {

			printf("ERROR: %d and %d are not found.\n", a, b);

		}
		else if (f1) {

			printf("ERROR: %d is not found.\n", a);
		}
		else if (f2)
		{
			printf("ERROR: %d is not found.\n", b);
		}
		else
		{
			long long ans = findCom(root)->key;
			if(ans == a)
			{
				printf("%d is an ancestor of %d.\n", a, b);
			}
			else if(ans = b){
				printf("%d is an ancestor of %d.\n", b, a);
			}else {
				printf("LCA of %d and %d is %d.\n", a, b, ans);
			}

		}

	}

	system("pause");

	return 0;


}