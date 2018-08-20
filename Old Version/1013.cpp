#include<iostream>
#include<vector>
using namespace std;
bool visited[1001];
char v[1001][1001];

void init() {
	for (int i = 0; i < 1001; i++) {
		visited[i] = false;
	}
}

void dfs(int a, int n) {
	visited[a] = true;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false && v[a][i] == 1)
			dfs(i, n);
	}
}

//实际求连通图数！！！
int main() {

	int n, m, k;

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int temp, temp1;
		cin >> temp >> temp1;
		v[temp][temp1] = 1;
		v[temp1][temp] = 1;
	}

	for (int i = 0; i < k; i++) {
		init();
		int temp, cnt = 0;
		cin >> temp;
		visited[temp] = true;
		for (int i = 1; i < n + 1; i++) {
			if (!visited[i]) {
				dfs(i, n);
				cnt++;
			}
		}
		printf("%d\n", cnt - 1);
	}

	return 0;
}