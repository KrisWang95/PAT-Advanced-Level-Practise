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

int n, m;

vector<vector<int>> g(110);

int dep[110] = { 0 }, gen[110] = { 0 };

void bfs(int root) {

	queue<int> q;

	q.push(root);

	dep[root] = 1;

	while (!q.empty()){

		int k = q.front();

		q.pop();

		for (int i = 0; i < g[k].size(); i++) {

			dep[g[k][i]] = dep[k] + 1;

			gen[dep[g[k][i]]]++;

			q.push(g[k][i]);

		}

	}



}



int main() {

	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {

		int temp, num;

		cin >> temp >> num;

		for (int j = 0; j < num; j++) {

			int p;

			cin >> p;

			g[temp].push_back(p);

		}

	}

	bfs(1);

	int max = INT_MIN, v;

	for (int i = 1; i <= n; i++) {

		if (gen[dep[i]] > max) {

			max = gen[dep[i]];

			v = dep[i];
		}

	}

	cout << max << " " << v;


	system("pause");

	return 0;
}