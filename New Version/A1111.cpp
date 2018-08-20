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

struct edge {
	int to, len,time;
};

struct dij {

	int x, d;

	dij(int _x, int _d):x(_x),d(_d){}

	bool operator < (const dij &ano) const { return d > ano.d; }
};

vector<vector<edge>> v(505);


vector<int> path1, path2,temp;

int minLen = inf;

void dfs(vector<int> &p,int s) {

	if (s == -1) return;

	path1.insert(path1.begin(),s);

	dfs(p, p[s]);

}

void dfs(vector<vector<int>> &temppath, int s,int d) {

	temp.push_back(s);

	if (s == d) {

		if (temp.size() < minLen) {

			minLen = temp.size();

			path2 = temp;

		}

		temp.pop_back();

		return;

	}

	for (int i = 0; i < temppath[s].size(); i++) {

		dfs(temppath, temppath[s][i], d);

	}

	temp.pop_back();

}


int main() {

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {

		int v1, v2, tag, len, time;

		cin >> v1>> v2>> tag>> len>> time;

		if (tag == 1) {

			v[v1].push_back({ v2,len,time });

		}
		else {

			v[v1].push_back({ v2,len,time });

			v[v2].push_back({ v1,len,time });

		}

	}

	int s, de;

	cin >> s >> de;

	vector<int> d(505, inf), w(505, inf), pre(505, -1);

	priority_queue<dij> q;

	q.push({ s,0 });

	d[s] = 0;

	while (!q.empty()) {

		dij  temp = q.top(); q.pop();

		int x = temp.x;

		if (d[x] < temp.d) continue;

		for (int i = 0; i < v[x].size(); i++) {

			int u = v[x][i].to, cost = v[x][i].len;

			if (d[u] > d[x] + cost) {

				d[u] = d[x] + cost;

				w[u] = w[x] + v[x][i].time;

				pre[u] = x;

				q.push({ u,d[u] });

			}
			else if(d[u] == d[x] + cost && w[u] > w[x] + v[x][i].time)  {

				w[u] = w[x] + v[x][i].time;

				pre[u] = x;

			}

		}

	}

	//----------time-----------------

	vector<int> td(505, inf);

	vector<vector<int>> temppath(505);

	priority_queue<dij> pq;

	pq.push({ s,0 });

	td[s] = 0;

	while (!pq.empty()) {

		dij  temp = pq.top(); pq.pop();

		int x = temp.x;

		if (td[x] < temp.d) continue;

		for (int i = 0; i < v[x].size(); i++) {

			int u = v[x][i].to, cost = v[x][i].time;

			if (td[u] > td[x] + cost) {

				td[u] = td[x] + cost;

				pq.push({ u,td[u]});

				temppath[u].clear();

				temppath[u].push_back(x);

			}
			else if (td[u] == td[x] + cost) {
				
				temppath[u].push_back(x);

			}

		}

	}

	dfs(pre, de);

	dfs(temppath, de, s);

	reverse(path2.begin(), path2.end());

	if (path1 == path2) {

		cout << "Distance = " << d[de] << "; ";

		cout << "Time = " << td[de] << ": ";

		for (int i = 0; i < path1.size(); i++) {

			if (i == 0) cout << path1[i];

			else cout << " -> " << path1[i];

		}

	}
	else {

		cout << "Distance = " << d[de] << ": ";

		for (int i = 0; i < path1.size(); i++) {

			if (i == 0) cout << path1[i];

			else cout << " -> " << path1[i];

		}
		cout << endl;

		cout << "Time = " << td[de] << ": ";

		for (int i = 0; i < path2.size(); i++) {

			if (i == 0) cout << path2[i];

			else cout << " -> " << path2[i];

		}

	}

	system("pause");

	return 0;
}