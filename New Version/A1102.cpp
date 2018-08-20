#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

struct node {
	int lchild, rchild;
}Node[10];

vector<int> in;
map<int, int> level;

bool isRoot[10];

void postOrder(int root) {
	if (root == -1) return;
	postOrder(Node[root].lchild);
	postOrder(Node[root].rchild);
	swap(Node[root].lchild, Node[root].rchild);
}

void inOrder(int root, int index) {

	if (root == -1) return;
	level[index] = root;
	inOrder(Node[root].lchild, index * 2 + 1);
	in.push_back(root);
	inOrder(Node[root].rchild, index * 2 + 2);

}

int main() {
	int num, cnt = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		Node[i].lchild = (s1 == "-" ? -1 : s1[0] - '0');
		Node[i].rchild = (s2 == "-" ? -1 : s2[0] - '0');
		if (Node[i].lchild != -1) isRoot[Node[i].lchild] = true;
		if (Node[i].rchild != -1) isRoot[Node[i].rchild] = true;
	}

	int root;

	for (int i = 0; i < num; i++) {
		if (isRoot[i] != true) {
			root = i;
			break;
		}
	}
	postOrder(root);
	inOrder(root, 0);

	map<int, int>::iterator it;
	for (it = level.begin(); it != level.end(); it++, cnt++) {

		cout << it->second << (cnt < (num - 1) ? " " : "\n");
	}

	for (int i = 0; i < num; i++) {
		cout << in[i] << (i < num - 1 ? " " : "");
	}

	return 0;
}
