/*dijkstra ªÿÀ›ºÙ÷¶*/
#include<iostream>
#include<vector>
#define inf 65535
using namespace std;
int m[505][505], dis[505], current[505], minNeed = inf, minBack = inf;
bool visited[505];
vector<int> midp[505];
vector<int> temppath,path;
void findpath(int v) {
	temppath.push_back(v);
	if (v == 0) {
		int need = 0, back = 0;
		for (int i = temppath.size() - 1; i >= 0; i--) {
			int id = temppath[i];
			if (current[id] > 0) {
				back += current[id];
			}
			else {
				if (back + current[id] > 0) {
					back += current[id];
				}
				else {
					need += (- current[id] - back);
					back = 0;
				}
			}
		}
		if (need < minNeed) {
			minNeed = need;
			minBack = back;
			path = temppath;
		}
		else if (need == minNeed && back < minBack) {
			minBack = back;
			path = temppath;
		}
	}
	for (int i = 0; i < midp[v].size(); i++)
		findpath(midp[v][i]);
	temppath.pop_back();//ºÙ÷¶
}
int main() {
	int capacity, num, p, roads;
	cin >> capacity >> num >> p >> roads;
	for (int i = 1; i <= num; i++){
		cin >> current[i];
		current[i] -= capacity / 2;
	}
	
	for (int i = 0; i < 505; i++) {
		dis[i] = inf;
		visited[i] = false;
		for (int j = 0; j < 505; j++){
			m[i][j] = inf;
		}
	}

	for (int i = 1; i <= roads; i++) {
		int a, b,c;
		scanf("%d %d %d", &a, &b, &c);
		m[a][b] = c;
		m[b][a] = c;
		if (a == 0) dis[b] = c;
	}

	dis[0] = 0;
	while (1) {
		int v = -1, minDis = inf;
		for (int i = 0; i <= num; i++) {
			if (visited[i] == false && dis[i] < minDis) {
				minDis = dis[i];
				v = i;
			}
		}
		if (v == -1) break;
		visited[v] = true;

		for (int i = 0; i <= num; i++) {
			if (visited[i] == false && m[v][i] < inf) {
				if (dis[i] > dis[v] + m[v][i]) {
					dis[i] = dis[v] + m[v][i];
					midp[i].clear();
					midp[i].push_back(v);
				}
				else if (dis[i] == dis[v] + m[v][i]) {
					midp[i].push_back(v);
				}
			}
		}
	}

	findpath(p);

	printf("%d 0", minNeed);
	for (int i = path.size() - 2; i >= 0; i--)
		printf("->%d", path[i]);
	printf(" %d", minBack);
	system("pause");
	return 0;
	
}
