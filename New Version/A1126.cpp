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

vector<int> degree;

vector<bool> visit;

vector<vector<int>> edge;

int c = 0;

void dfs(int s) {

	visit[s] = true;

	c++;

	for (int i = 0; i < edge[s].size(); i++) {

		if(!visit[edge[s][i]])dfs(edge[s][i]);
	}

}


int main() {

	int n, en;

	cin >> n >> en;

	degree.resize(n + 1, 0);

	edge.resize(n + 1);

	visit.resize(n + 1, false);

	for (int i = 0; i < en; i++) {

		int v1, v2;

		cin >> v1 >> v2;

		edge[v1].push_back(v2);

		edge[v2].push_back(v1);

		degree[v1]++;

		degree[v2]++;

	}

	int cnt = 0;

	for (int i = 1; i <= n; i++) {

		if (degree[i] % 2 != 0) cnt++;

		if (i == 1) cout << degree[i];

		else cout << " " << degree[i];

	}

	dfs(1);

	if (cnt == 0 && c == n) {

		cout << endl << "Eulerian";

	}
	else if (cnt == 2 && c == n) {

		cout << endl << "Semi-Eulerian";

	}
	else {

		cout << endl << "Non-Eulerian";

	}

	system("pause");

	return 0;
}