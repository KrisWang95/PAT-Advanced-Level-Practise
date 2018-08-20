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

map<pair<int,int>, int> line;

vector<vector<int>> e(10000);

vector<bool> visit(10000, false);

vector<int> temppath, ans;

int minTrans = 65535, minStop = 65535;

int getTrans() {

	set<int> temp;

	for (int i = 0; i < temppath.size(); i++) {

		if (i > 0) {

			temp.insert(line[make_pair(temppath[i], temppath[i - 1])]);

		}
	}
	return temp.size();
}

void dfs(int s, int t) {
	
	if (s == t) {

		int temp = getTrans();
		
		if (minStop > temppath.size() || (minStop == temppath.size() && minTrans > temp )) {

			minTrans = temp;

			minStop = temppath.size();

			ans = temppath;

		}

		return;

	}

	for (int i = 0; i < e[s].size(); i++) {

		int u = e[s][i];

		if (visit[u] == false) {

			visit[u] = true;

			temppath.push_back(u);

			dfs(u, t);

			visit[u] = false;

			temppath.pop_back();

		}
		
	}

}

int main() {

	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {

		int temp,last;

		scanf("%d", &temp);

		for (int j = 0; j < temp; j++) {

			int t;

			scanf("%d", &t);

			if (j > 0) {

				line[make_pair(t, last)] = line[make_pair(last, t)] = i;

				e[t].push_back(last);

				e[last].push_back(t);

			}

			last = t;

		}

	}

	int qn;

	scanf("%d", &qn);


	for (int i = 0; i < qn; i++) {

		minTrans = 65535;

		minStop = 65535;

		temppath.clear();

		int s, t;

		scanf("%d %d", &s, &t);

		temppath.push_back(s);

		visit[s] = true;

		dfs(s, t);

		visit[s] = false;

		printf("%d\n", ans.size() - 1);

		int last = line[make_pair(ans[0],ans[1])];

		int start = s;

		for (int j = 0; j < ans.size(); j++) {

			if (j == ans.size() - 1 || last != line[make_pair(ans[j], ans[j+1])]) {

				printf("Take Line#%d from %04d to %04d.\n", last, start, ans[j]);

				if (j < ans.size() - 1) {

					last = line[make_pair(ans[j], ans[j + 1])];

					start = ans[j];

				}

			}

		}
	

	}

	system("pause");

	return 0;
}