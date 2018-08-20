#include<iostream>
#include<vector>
#define inf 65535

using namespace std;

int dist[505], e[505][505], cost[505][505],mincost = inf;
bool visited[505];

vector<int> pathPre[505],path,temppath;

void findMinCost(int s,int d) {

	temppath.push_back(s);

	if (s == d) {
		int tempcost = 0;
		for (int i = 0; i < temppath.size() - 1; i++){
			tempcost += cost[temppath[i]][temppath[i + 1]];
		}
		if (tempcost < mincost) {
			mincost = tempcost;
			path = temppath;//¸üÐÂÂ·¾¶																 
		}
	}
	for (int i = 0; i < pathPre[s].size(); i++)
		findMinCost(pathPre[s][i],d);

	temppath.pop_back();
}
int main() {

	int n, m, s, d;

	cin >> n >> m >> s >> d;

	for (int i = 0; i < n; i++) {

		dist[i] = inf;
		visited[i] = false;
		for (int j = 0; j < n; j++) {
			e[i][j] = inf;
		}

	}

	for (int i = 0; i < m; i++) {

		int city1, city2, dis, cos;

		cin >> city1 >> city2 >> dis >> cos;

		e[city1][city2] = dis;
		e[city2][city1] = dis;

		cost[city1][city2] = cos;
		cost[city2][city1] = cos;
		
	}

	dist[s] = 0;

	while (1) {
		int v = -1, minDis = inf;
		for (int i = 0; i < n; i++){
			if (!visited[i] && dist[i] < minDis) {
				v = i;
				minDis = dist[i];
			}
		}

		if (v == -1) break;

		visited[v] = true;

		for (int i = 0; i < n; i++) {
			if (visited[i] == false && e[v][i] != inf) {
				if (dist[i] > dist[v] + e[v][i]) {
					dist[i] = dist[v] + e[v][i];
					pathPre[i].clear();
					pathPre[i].push_back(v);
				}
				else if(dist[i] == dist[v] + e[v][i]){
					pathPre[i].push_back(v);
				}
			}
		}
	}

	findMinCost(d,s);

	for (int i = path.size() - 1; i >= 0; i--)
		printf("%d ", path[i]);
	printf("%d %d", dist[d], mincost);

	return 0;

}