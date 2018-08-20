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
#define INT_MAX inf
using namespace std;

struct node {

	int i, j, k;

};

int g[1300][130][70], v[1300][130][100] = { 0 };

int adj[6][3] = { { 0,0,1 },{ 0,0,-1 },{ 1,0,0 },{ -1,0,0 },{ 0,1,0 },{ 0,-1,0 } };

int m, n, l, t;

int ans = 0;

bool checkValid(int i, int j, int k) {

	if (i<0 || j<0 || k<0 || i >= m || j >= n || k >= l) return false;

	return true;

}

void bfs(node a) {

	int cnt = 0;

	queue<node> q;

	q.push(a);

	v[a.i][a.j][a.k] = 1;

	while (!q.empty()) {

		node k = q.front();

		cnt++;

		q.pop();

		for (int i = 0; i < 6; i++) {

			node next;

			next.i = k.i + adj[i][0];

			next.j = k.j + adj[i][1];

			next.k = k.k + adj[i][2];

			if (checkValid(next.i, next.j, next.k) && g[next.i][next.j][next.k] == 1 && v[next.i][next.j][next.k] == 0) {

				q.push(next);

				v[next.i][next.j][next.k] = 1;
			}

		}

	}

	if (cnt >= t) ans += cnt;

}



int main() {

	ios::sync_with_stdio(false);

	cin >> m >> n >> l >> t;


	for (int k = 0; k < l; k++) {

		for (int i = 0; i < m; i++) {

			for (int j = 0; j < n; j++) {

				cin >> g[i][j][k];

			}

		}

	}


	for (int k = 0; k < l; k++) {

		for (int i = 0; i < m; i++) {

			for (int j = 0; j < n; j++) {

				node a = { i,j,k };

				if (v[i][j][k] == 0 && g[i][j][k] == 1) {

					bfs(a);

				}

			}

		}

	}

	cout << ans;

	system("pause");

	return 0;
}