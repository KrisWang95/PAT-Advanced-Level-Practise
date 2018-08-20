#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int g[502][501], visited[501] = { 0 },cost[501][501],dis[501];

vector<vector<int>> preNode(501);

vector<int> tempPath, path;

int tempCost, minCost = INT16_MAX;

int n, m, s, d;

void findMinCost(int s, int d) {

	tempPath.push_back(s);

	if (s == d) {
		int tempcost = 0;
		for (int i = 0; i < tempPath.size() - 1; i++) {
			tempcost += cost[tempPath[i]][tempPath[i + 1]];
		}
		if (tempcost < minCost) {
			minCost = tempcost;
			path = tempPath;
		}
	}
	for (int i = 0; i < preNode[s].size(); i++)
		findMinCost(preNode[s][i], d);

	tempPath.pop_back();//¼ôÖ¦
}

int main() {

	for (int i = 0; i < 501; i++) {

		for (int j = 0; j < 501; j++) {

			g[i][j] = INT_MAX;

		}

		dis[i] = INT_MAX;
	}

	cin >> n >> m >> s >> d;

	for (int i = 0; i < m; i++) {

		int c1, c2, distance, c;

		cin >> c1 >> c2 >> distance >> c;

		g[c1][c2] = g[c2][c1] = distance;

		cost[c1][c2] = cost[c2][c1] = c;

	}

	dis[s] = 0;

	while (1) {

		int min = INT_MAX, u = -1;

		for (int i = 0; i < n; i++) {

			if (min > dis[i] && visited[i] == 0 ) {

				min = dis[i];

				u = i;
			}

		}

		if (u == -1) break;

		visited[u] = 1;

		for (int i = 0; i < n; i++) {

			if (visited[i] == 0 && g[u][i] != INT_MAX) {

				if (dis[i] > g[u][i] + dis[u]) {

					dis[i] = g[u][i] + dis[u];

					preNode[i].clear();

					preNode[i].push_back(u);

				}
				else if (dis[i] == g[u][i] + dis[u]) {

					preNode[i].push_back(u);

				}
			}

		}

	}
	

	findMinCost(d, s);

	for (int i = path.size() - 1; i >= 0; i--)

		printf("%d ", path[i]);

	printf("%d %d", dis[d], minCost);

	
	system("pause");

	return 0;
}


