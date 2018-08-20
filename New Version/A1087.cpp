#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include<string>
#include<climits>
#include<queue>

using namespace std;

map<string, int> stringToInt;

map<int, string> intToString;

int cnt = 0 , maxHappiness = -1, anscnt = 0;

double maxAv = -1;

vector<bool> visit(205, false);

vector<int> happiness(205,0),d(205,INT_MAX),tempPath,ans;

vector<vector<int>> g(205, vector<int>(205,INT_MAX)),path(205);

int getId(string s) {

	if (stringToInt.find(s) == stringToInt.end()) {

		stringToInt[s] = cnt;

		intToString[cnt] = s;

		cnt++;

	}
	return stringToInt[s];
}

void dfs(int s, int d) {

	tempPath.push_back(s);

	if (s == d) {

		anscnt++;

		int sum = 0;

		for (auto it : tempPath) {

			sum += happiness[it];

		}
		
		double av = sum / ((tempPath.size() -1) * 1.0);

		if (maxHappiness < sum || (maxHappiness == sum && maxAv < av)) {

			ans = tempPath;

			maxHappiness = sum;

			maxAv = av;

		}

	}

	for (int i = 0; i < path[s].size(); i++) {

		dfs(path[s][i], d);

	}

	tempPath.pop_back();

}



int main() {

	int n, k;

	string start;

	cin >> n >> k >> start;

	int source = getId(start);

	for (int i = 0; i < n - 1; i++) {

		string s;

		int t;

		cin >> s >> t;

		int id = getId(s);

		happiness[id] = t;

	}

	for (int i = 0; i < k; i++) {

		string s1, s2;

		int cost;

		cin >> s1 >> s2 >> cost;

		int id1 = getId(s1), id2 = getId(s2);

		g[id1][id2] = g[id2][id1] = cost;

	}

	d[source] = 0;

	while (1) {

		int min = INT_MAX, v = -1;

		for (int i = 0; i < n; i++) {

			if (visit[i] == false && d[i] < min) {

				min = d[i];

				v = i;

			}
		}

		if (v == -1) break;

		visit[v] = true;

		for (int i = 0; i < n; i++) {

			if (visit[i] == false && g[v][i] != INT_MAX) {

				if (d[i] > d[v] + g[v][i]) {

					d[i] = d[v] + g[v][i];

					path[i].clear();

					path[i].push_back(v);

				}
				else if (d[i] == d[v] + g[v][i]) {

					path[i].push_back(v);

				}

			}

		}

	}

	int dd = getId("ROM");
	
	dfs(dd, source);

	printf("%d %d %d %d\n", anscnt, d[dd], maxHappiness, (int)maxAv);

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {

		if (i == ans.size() - 1) cout << intToString[ans[i]];

		else cout << intToString[ans[i]] << "->";

	}

	system("pause");

	return 0;
}