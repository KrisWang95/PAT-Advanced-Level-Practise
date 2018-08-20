#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

struct edge{
	int nextV;
	int weight;
};

stack<int> top;
int n, inDegree[100],ve[100],vl[100];
vector<edge> g[100];

bool topLogicalSort() {
	queue<int> q;

	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()){

		int v = q.front();

		q.pop();

		top.push(v);

		for (int i = 0; i < g[v].size(); i++){
			int u = g[v][i].nextV;
			inDegree[u]--;
			if (inDegree[u] == 0){
				q.push(u);
			}
			if (ve[v] + g[v][u].weight > ve[u]) { // 找到更大的，更新v的后继u的ve[u]
				ve[u] = ve[v] + g[v][u].weight;
			}
		}
		
	}
	if (top.size() == n) return true;
	return false;
}

int critical_path() {

	memset(ve, 0, sizeof(ve));
	if (topLogicalSort() == false) return -1;//求ve[n]
	
	fill(vl, vl + n, ve[n - 1]);//终点ve[n - 1]
	while (!top.empty()) {
		int u = top.top();
		top.pop();
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].nextV;
			if (vl[v] - g[v][u].weight < vl[u]) {
				vl[u] = vl[v] - g[v][u].weight;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <g[i].size(); j++){
			int v = g[i][j].nextV;
			int e = ve[i], l = vl[v] - g[i][j].weight;
			if (e == l) cout << i << "->" << v << endl;
		}
	}
	return ve[n - 1];
}