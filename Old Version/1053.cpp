#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

const int maxn = 110;
int n, m, s, path[maxn];

struct node {
	int weight;
	vector<int> child;
}Node[maxn];

bool cmp(int a ,int b) {
	return Node[a].weight > Node[b].weight;
}
void dfs(int index ,int numNode,int sum) {
	if (sum > s) return;
	if (sum == s) {
		if (Node[index].child.size() != 0) return;
		for (int i = 0; i < numNode; i++) {
			cout << Node[path[i]].weight;
			if (i < numNode - 1) cout << " ";
			else cout << endl;
		}
		return;
	}
	for (int i = 0; i < Node[index].child.size(); i++){
		int id = Node[index].child[i];
		path[numNode] = id;
		dfs(id, numNode + 1, sum + Node[index].weight);
	}
}

int main() {
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		cin >> Node[i].weight;
	}
	int tempid, numC,cid;
	for (int i = 0; i < m; i++) {
		cin >> tempid >> numC;
		for (int j = 0; j < numC; j++) {
			cin >> cid;
			Node[tempid].child.push_back(cid);
		}
		sort(Node[tempid].child.begin(), Node[tempid].child.end(), cmp);
	}
	path[0] = 0;
	dfs(0, 1, Node[0].weight);
	system("pause");
	return 0;
}