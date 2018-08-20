#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include<string>
#include<climits>
using namespace std;

vector<int> dis(1050, INT_MAX);

vector<bool> visit(1050, false);

vector< vector<int> > g(1050, vector<int>(1050, INT_MAX));



void dijkstra(int s,int len) {

	dis[s] = 0;

	while (1) {

		int min = INT_MAX, u = -1;

		for (int i = 1; i <= len; i++) {

			if (min > dis[i] && visit[i] == false) {

				min = dis[i];

				u = i;

			}

		}

		if (u == -1) break;

		visit[u] = true;

		for (int i = 1; i <= len; i++) {

			if (visit[i] == false && g[u][i] != INT_MAX) {

				if (dis[i] > dis[u] + g[u][i]) {

					dis[i] = dis[u] + g[u][i];

				}
			}

		}

	}

}



int main() {

	int n, m, k, d;

	scanf("%d %d %d %d", &n, &m, &k, &d);

	for (int i = 0; i < k; i++) {

		int temp[3] = { 0 };

		for (int j = 0; j < 3; j++) {

			string s;

			cin >> s;

			if (s[0] == 'G') { temp[j] = n; s.erase(s.begin()); }

			temp[j] += stoi(s);

		}

		g[temp[0]][temp[1]] = g[temp[1]][temp[0]] = temp[2];


	}

	int ansid = -1;

	double ansdis = -1, ansaver = INT_MAX;

	for (int i = 1; i <= m; i++) {

		fill(dis.begin(), dis.end(), INT_MAX);

		fill(visit.begin(), visit.end(), false);

		dijkstra(i + n, n + m);

		double mindis = INT_MAX, aver = 0;

		for (int j = 1; j <= n; j++) {

			if (dis[j] > d) {

				mindis = -1;

				break;
			}

			aver += dis[j]*1.0;

			if (mindis > dis[j]) mindis = dis[j];

		}

		if (mindis == -1) continue;

		aver = aver / n;

		if (mindis > ansdis) {

			ansid = i;

			ansdis = mindis;

			ansaver = aver;

		}
		else if (mindis == ansdis && aver < ansaver) {

			ansid = i;

			ansaver = aver;

		}

	}

	if (ansid != -1) printf("G%d\n%.1f %.1f", ansid, ansdis, ansaver);

	else printf("No Solution");



	system("pause");

	return 0;
}